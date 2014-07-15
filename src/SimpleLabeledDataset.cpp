/* 
 * File:   SimpleLabeledDataset.cpp
 * Author: janvojt
 * 
 * Created on July 13, 2014, 8:17 PM
 */

#include "SimpleLabeledDataset.h"
#include <cstring>
#include "log/LoggerFactory.h"
#include "log4cpp/Category.hh"

SimpleLabeledDataset::SimpleLabeledDataset(int inputDimension, int outputDimension, int size) {
    addedCounter = 0;
    inDimension = inputDimension;
    outDimension = outputDimension;
    this->size = size;
    data = new float[(inputDimension + outputDimension) * size];
}

SimpleLabeledDataset::SimpleLabeledDataset(const SimpleLabeledDataset& orig) {
}

SimpleLabeledDataset::~SimpleLabeledDataset() {
    delete data;
}

void SimpleLabeledDataset::addPattern(const float *input, const float *output) {
    
    if (addedCounter >= size) {
        LOG()->error("Trying to add %d learning patterns while the dataset size is only %d.", addedCounter+1, size);
    }
    
    int inputSize = sizeof(float) * inDimension;
    int outputSize = sizeof(float) * outDimension;
    int patternSize = inDimension + outDimension;
    float *dataPtr = data + (addedCounter * patternSize);
    std::memcpy(dataPtr, input, inputSize);
    std::memcpy(dataPtr + inDimension, output, outputSize);
    addedCounter++;
}

int SimpleLabeledDataset::getInputDimension() {
    return inDimension;
}

int SimpleLabeledDataset::getOutputDimension() {
    return outDimension;
}

void SimpleLabeledDataset::initDataset() {
    data = new float[size * (inDimension + outDimension)];
}

float* SimpleLabeledDataset::next() {
    return data + (cursor++ * (inDimension + outDimension));
}

bool SimpleLabeledDataset::hasNext() {
    return cursor < size;
}

void SimpleLabeledDataset::reset() {
    cursor = 0;
}
