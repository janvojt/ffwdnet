#!/bin/bash
#
# This is a configuration file for automated launching of a set of tests testing
# different network architectures and learner configurations
# on the MNIST dataset.


# Title will be included in graphs
PROBLEM_TITLE="MNIST"

# Network architecture configuration
## Set if we want to use file configurations for the networks. Otherwise leave empty
CONF_DIR="examples/cnn-mnist-test"
## Set configurations of hidden neurons if we want to use MLP network
HIDDEN_NEURONS="196 392 588 784 980 1176 1372 1568 1764 1960 2156 2352 784,784 784,784,784 784,784,784,784 784,784,784,784,784 784,784,784,784,784,784"
INPUT_NEURONS="784"
OUTPUT_NEURONS="10"

# Specify dataset locations within resources
DATASET_LABELS="resources/mnist/train-images-idx3-ubyte"\
":resources/mnist/train-labels-idx1-ubyte"
DATASET_TESTS="resources/mnist/t10k-images-idx3-ubyte"\
":resources/mnist/t10k-labels-idx1-ubyte"

# Learner configuration
EPOCHS="1"
ITERATIONS="2"
INIT_INTERVALS="-0.3,0.3"
LEARNING_RATE="0.001"
GPU_FLAG="-p"
ADD_OPTS="-i"

# Testing configuration
MEASURES="mse time memory"
TESTDIR="test-output/mnist/m$EPOCHS$GPU_FLAG"
