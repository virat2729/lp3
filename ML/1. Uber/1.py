import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.preprocessing import StandardScaler


# Load your dataset
# Replace 'uber_data.csv' with your dataset path
df = pd.read_csv('uber.csv')


# 1. Pre-process the dataset

# Drop rows with missing values (optional based on data quality)
df.dropna(inplace=True)


# Feature Engineering (Example for columns like pickup and dropoff coordinates)
# Convert pickup and dropoff coordinates to numerical distance (Euclidean)
def calculate_distance(lat1, lon1, lat2, lon2):
    return np.sqrt((lat1 - lat2)**2 + (lon1 - lon2)**2)

df['distance'] = calculate_distance(df['pickup_latitude'], df['pickup_longitude'],
                                    df['dropoff_latitude'], df['dropoff_longitude'])


# Select relevant features
X = df[['distance']]  # Add other relevant features as needed
y = df['fare_amount']  # Assuming 'fare_amount' is the target variable


# Split data into train and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


# Standardize the features (important for linear regression)
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)


# 2. Implement linear regression and random forest regression models

# Linear Regression Model
lr_model = LinearRegression()
lr_model.fit(X_train_scaled, y_train)
y_pred_lr = lr_model.predict(X_test_scaled)


# Random Forest Regression Model
rf_model = RandomForestRegressor(n_estimators=100, random_state=42)
rf_model.fit(X_train, y_train)
y_pred_rf = rf_model.predict(X_test)


# 3. Evaluate the models and compare their respective scores

# Define a function to print evaluation metrics
def evaluate_model(y_true, y_pred, model_name):
    rmse = np.sqrt(mean_squared_error(y_true, y_pred))
    r2 = r2_score(y_true, y_pred)
    print(f"{model_name} - RMSE: {rmse:.2f}, R^2 Score: {r2:.2f}")


# Evaluate Linear Regression
evaluate_model(y_test, y_pred_lr, "Linear Regression")


# Evaluate Random Forest Regression
evaluate_model(y_test, y_pred_rf, "Random Forest Regression")
