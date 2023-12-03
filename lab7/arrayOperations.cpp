#include "arrayOperations.hpp"

ArrayOperations::ArrayOperations(int studentNumber) {
    size = static_cast<int>(10 + 0.6 * studentNumber);
    array = new int[size];
}

void ArrayOperations::fillArray() {
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100 + 1;
    }
}

void ArrayOperations::sortArrays() {
    if (size % 2 == 0) {
        std::sort(array, array + size);
    }
    else {
        for (int i = 1; i < size; ++i) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }
}

void ArrayOperations::findKeys() {
    int key1 = array[size / 4];          // для парних номерів
    int key2 = array[3 * size / 4];      // для непарних номерів

    int sequentialResult = -1;
    int binaryResult = binarySearch(key1);

    std::cout << "Для парних номерів варіантів:" << '\n';
    std::cout << "Ключ, що знаходиться в середині лівої частини масиву: " << key1 << '\n';
    std::cout << "Пошук методом послідовного пошуку: " << sequentialResult << '\n';
    std::cout << "Пошук методом бінарного пошуку: " << binaryResult << '\n';

    int sequentialResult2 = -1;
    int interpolationResult = interpolationSearch(key2);

    std::cout << "\nДля непарних номерів варіантів:" << '\n';
    std::cout << "Ключ, що знаходиться в середині правої частини масиву: " << key2 << '\n';
    std::cout << "Пошук методом послідовного пошуку: " << sequentialResult2 << '\n';
    std::cout << "Пошук методом інтерполяційного пошуку: " << interpolationResult << '\n';
}

int ArrayOperations::binarySearch(int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == key)
            return mid;
        else if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int ArrayOperations::interpolationSearch(int key) {
    int low = 0, high = size - 1;
    while (low <= high && key >= array[low] && key <= array[high]) {
        int pos = low + ((double)(high - low) / (array[high] - array[low])) * (key - array[low]);

        if (array[pos] == key)
            return pos;
        else if (array[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}
