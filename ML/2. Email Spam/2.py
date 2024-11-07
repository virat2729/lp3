import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import classification_report, accuracy_score

# Load the dataset
#  Replace with the path to your file
emails_df = pd.read_csv('emails.csv')

# Separate features and labels
X = emails_df.drop(columns=['Email No.', 'Prediction'])  # Features
y = emails_df['Prediction']  # Labels

# Split data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


# Scale features for better performance in KNN and SVM
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)


# Reduce dimensionality with PCA
pca = PCA(n_components=50)  # Reducing to 50 principal components for efficiency
X_train_reduced = pca.fit_transform(X_train_scaled)
X_test_reduced = pca.transform(X_test_scaled)


# Initialize classifiers
knn = KNeighborsClassifier(n_neighbors=5)
svm = SVC(kernel='linear')


# Train and evaluate KNN
knn.fit(X_train_reduced, y_train)
y_pred_knn = knn.predict(X_test_reduced)
knn_accuracy = accuracy_score(y_test, y_pred_knn)
knn_report = classification_report(y_test, y_pred_knn)


print("K-Nearest Neighbors (KNN) Performance:")
print("Accuracy:", knn_accuracy)
print("Classification Report:\n", knn_report)


# Train and evaluate SVM
svm.fit(X_train_reduced, y_train)
y_pred_svm = svm.predict(X_test_reduced)
svm_accuracy = accuracy_score(y_test, y_pred_svm)
svm_report = classification_report(y_test, y_pred_svm)


print("\nSupport Vector Machine (SVM) Performance:")
print("Accuracy:", svm_accuracy)
print("Classification Report:\n", svm_report)
