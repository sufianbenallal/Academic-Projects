# Neural Network from Scratch for Heart Failure Prediction

Advanced machine learning project implementing a neural network manually using NumPy, without relying on high-level frameworks.

## Dataset

- Heart Failure Clinical Records dataset (binary classification: survival vs death) :contentReference[oaicite:0]{index=0}

## Features

### Neural Network Implementation
- Fully implemented from scratch using NumPy
- Forward propagation
- Backpropagation using chain rule
- Sigmoid activation function
- Binary cross-entropy loss

### Model Development

#### Single-Layer Perceptron
- Initial implementation with one hidden layer
- Achieved ~70% validation accuracy :contentReference[oaicite:1]{index=1}

#### Deep Neural Networks
- Extended architecture to multiple layers:
  - 2-layer network
  - 4-layer network
  - 6-layer network
- Compared performance using cross-validation

### Training and Optimisation
- Batch gradient descent implementation
- Hyperparameter tuning:
  - Learning rate
  - Number of epochs
  - Training size

### Model Evaluation
- Train / validation / test split
- 10-fold cross-validation
- Confusion matrix analysis
- Final test accuracy ≈ 76% :contentReference[oaicite:2]{index=2}

### Key Experiments

- Impact of learning rate on convergence
- Effect of model depth on performance
- Bias–variance analysis
- Dataset size influence

## Results

- Deeper networks did not significantly improve performance due to dataset size
- Best architecture: simpler model ([16,8])
- Model generalisation limited by small dataset and class imbalance

## Concepts Covered

- Neural networks from scratch
- Backpropagation and gradient descent
- Binary classification
- Hyperparameter tuning
- Cross-validation
- Model evaluation (confusion matrix)
- Bias-variance trade-off
- Deep learning fundamentals

## Technologies

- Python
- NumPy
- Matplotlib
