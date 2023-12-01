#include "timeMeasurement.hpp"

std::chrono::milliseconds TimeMeasurement::measureExecutionTime(std::function<void()> action) {
    auto start_time = std::chrono::high_resolution_clock::now();
    action();
    auto end_time = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
}
