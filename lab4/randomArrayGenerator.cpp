#include "randomArrayGenerator.hpp"

int RandomArrayGenerator::generateRandomSize(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

double* RandomArrayGenerator::generateRandomArray(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());

    double* array = new double[n];

    for (int i = 0; i < n; ++i) {
        std::uniform_real_distribution<double> value_distribution(0.0, 100.0);
        array[i] = value_distribution(gen);
    }

    return array;
}

double RandomArrayGenerator::calculateAverage(const double* array, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += array[i];
    }

    return sum / n;
}