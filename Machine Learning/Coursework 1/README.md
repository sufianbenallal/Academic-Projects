# Heart Failure Prediction using Machine Learning

Machine learning project analysing clinical data to predict patient survival using multiple algorithms and evaluation techniques.

## Dataset

- Heart Failure Clinical Records dataset
- 299 patients with 12 clinical features and a binary target variable (`death_event`) :contentReference[oaicite:0]{index=0}

## Workflow

### Data Analysis
- No missing values detected
- Distribution analysis and outlier detection
- Class imbalance evaluation (~68% survival, ~32% mortality)

### Preprocessing
- Feature-target separation (X, Y)
- Z-score normalization using StandardScaler
- Train / validation / test split (70% / 15% / 15%)

### Models Implemented

#### K-Nearest Neighbours (KNN)
- Hyperparameter tuning (k = 1, 3, 5, 7, 9)
- Best performance at k = 5
- Cross-validation (5-fold)

#### Gaussian Naïve Bayes
- Probabilistic classification approach
- Better generalisation on test data compared to KNN

### Dimensionality Reduction

#### PCA (Principal Component Analysis)
- Reduced features while retaining 95% variance
- Improved performance for both models

## Results

- KNN shows higher training accuracy but slight overfitting
- Naïve Bayes provides more stable generalisation
- PCA improves accuracy for both models

## Concepts Covered

- Supervised learning
- Model comparison (KNN vs Naïve Bayes)
- Hyperparameter tuning
- Cross-validation
- Feature scaling
- Dimensionality reduction (PCA)
- Bias-variance trade-off

## Technologies

- Python
- Scikit-learn
- NumPy / Pandas
- Matplotlib / Seaborn
