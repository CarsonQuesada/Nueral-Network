# Neural Network

A minimal C++ implementation of a feedforward neural network for digit classification.

This project trains a small neural network on a dataset of 100 samples and evaluates it on 10 test samples, typically achieving 40–50% accuracy. The goal is educational: implementing core neural network concepts from scratch in C++.

---

## Overview

* Language: C++17
* Build system: CMake
* Architecture:
    - Input layer
    - One hidden layer (100 nodes)
    - Output layer (10 nodes for digits 0–9)
* Activation function: Sigmoid
* Training method: Backpropagation

The network is trained using CSV datasets and evaluates predictions by selecting the highest output value as the predicted digit.

---

## Dataset
Expected files:
data/TrainingData100.csv
data/TestingData10.csv

* Training samples: 100
* Test samples: 10
* Labels: digits 0–9
Accuracy is limited due to the very small dataset size.

---

## Building
### Requirements
* CMake ≥ 3.10
* C++17 compatible compiler

### Build Instructions
From the project root:
```
cmake -S . -B build
cmake --build build
```
If your CMake configuration outputs to out/bin, the executable will be located in:

---

## Running
Ensure the `data/` directory is available next to the executable.
Run:
```./neural_network```

The program will:
1. Load the training dataset
2. Train the neural network
3. Evaluate on the test dataset
4. Print per-sample results
5. Display final accuracy percentage
Example output:
```
CORRECT!  | Target: 3, Evaluated to: 3
INCORRECT! | Target: 7, Evaluated to: 2
...
50% correct
```

---

## Purpose
This project demonstrates:
* Matrix-based neural network implementation
* Weight initialization using random values
* Forward propagation
* Backpropagation
* Basic dataset handling in C++
It is not optimized for performance, scalability, or production use.

---

If you want, I can also produce:
* A shorter version
* A more formal version for a portfolio
* Or a version that highlights specific implementation details (e.g., math layer, matrix class design)