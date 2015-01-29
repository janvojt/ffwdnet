/* 
 * File:   cudaHelpers.h
 * Author: janvojt
 *
 * Created on November 29, 2014, 11:49 PM
 */

#ifndef CUDAHELPERS_H
#define	CUDAHELPERS_H

#include <stdio.h>
#include <cstdlib>
#include <iostream>

#define checkCudaErrors(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess) 
   {
      fprintf(stderr,"GPUassert: %s (%s:%d)\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

// Computes matrix sum A = A + B.
void k_sumVectors(double *dA, double *dB, int elements);

void k_computeOutputLocalGradient(double *actualOutput, double *expectedOutput, double *localGradient, int elements);

void k_computeTotalDerivative(int thisNeurons, int nextNeurons, 
        double learningRate, double *thisInput, double *nextLocalGradient,
        double *weightDiffs);

void k_computeBiasDerivative(
        double learningRate, double *nextLocalGradient,
        double *biasDiffs, int elements);

void k_computeHiddenLocalGradient(
        int thisNeurons, int nextNeurons,
        double *thisInput, double *weights,
        double *thisLocalGradient, double *nextLocalGradient);

// Compute the sigmoid function on device array.
void k_computeSigmoid(double *dArray, int elements);

// Assumes array of double values between 0 and 1 in dArray and 
// spreads this to given interval.
void k_spreadInterval(double min, double max, double *dArray, int size);

#endif	/* CUDAHELPERS_H */
