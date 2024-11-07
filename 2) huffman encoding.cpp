#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// A tree node structure to represent characters and their frequencies
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Custom comparator to order nodes by frequency in the priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Recursive function to generate Huffman codes and store them in a map
void generateCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // If the node is a leaf (character node), add the code to the map
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Function to build the Huffman Tree and generate codes
unordered_map<char, string> huffmanEncoding(const string& text) {
    // Calculate frequency of each character in the input text
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate until there is only one node left in the priority queue
    while (pq.size() > 1) {
        // Remove two nodes of the lowest frequency
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes
        int sum = left->freq + right->freq;
        Node* newNode = new Node('\0', sum); // '\0' is used for internal nodes
        newNode->left = left;
        newNode->right = right;

        // Add the new node to the priority queue
        pq.push(newNode);
    }

    // The root of the tree
    Node* root = pq.top();

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    return huffmanCode;
}

// Function to print Huffman codes
void printCodes(const unordered_map<char, string>& huffmanCode) {
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << "\n";
    }
}

// Driver program
int main() {
    string text;
    cout << "Enter the text to encode: ";
    getline(cin, text);

    unordered_map<char, string> huffmanCode = huffmanEncoding(text);

    printCodes(huffmanCode);

    // Print encoded string
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }

    cout << "\nEncoded string:\n" << encodedString << endl;

    return 0;
}
