// timeMeasurement.hpp
#pragma once

#include <chrono>
#include <functional>

class TimeMeasurement {
public:
    static std::chrono::milliseconds measureExecutionTime(std::function<void()> action);
};