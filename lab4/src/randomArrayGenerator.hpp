// randomArrayGenerator.hpp
#pragma once

#include <random>

class RandomArrayGenerator {
public:
    static double* generateRandomArray(int n);
    static int generateRandomSize(int min, int max);
    static double calculateAverage(const double* array, int n);
};