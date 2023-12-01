#include "arrayContainer.hpp"

ArrayContainer::ArrayContainer(int n) : size(n) {
    array = new int[size];
    generateRandomData();
}

ArrayContainer::~ArrayContainer() {
    delete[] array;
}

void ArrayContainer::generateRandomData() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < size; ++i) {
        array[i] = std::rand() % 100;
    }
}

void ArrayContainer::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
}

void ArrayContainer::bubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void ArrayContainer::insertionSort() {
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = key;
    }
}