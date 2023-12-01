/* 
    *   Скласти програму, яка формує одновимірний масив з n випадкових
    *   чисел. Визначити середнє арифметичне цих чисел. Значення n змінюється в
    *   межах від 10 до 50 мільйонів.

    *   Завдання. 
    *   Отримати завдання зі свого варіанту на асимптотичну і верх-
    *   ню оцінку складності алгоритму. Виконати таку оцінку теоретично. Провести
    *   експериментальну оцінку способом часу виконання того ж алгоритму шляхом
    *   складання відповідної програми на мові C++.
 */

// main.cpp
#include <iostream>
#include <functional>
#include "randomArrayGenerator.cpp"
#include "timeMeasurement.cpp"

int main() {
    int n = RandomArrayGenerator::generateRandomSize(10, 50000000);
    double* array = RandomArrayGenerator::generateRandomArray(n);

    auto duration = TimeMeasurement::measureExecutionTime([&]() {
        double average = RandomArrayGenerator::calculateAverage(array, n);
        std::cout << "Розмір масиву n: " << n << '\n';
        std::cout << "Середнє арифметичне: " << average << '\n';
    });

    std::cout << "Час виконання: " << duration.count() << " мс\n";

    delete[] array;
    return 0;
}
