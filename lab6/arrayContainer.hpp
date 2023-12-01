// arrayContainer.hpp
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class ArrayContainer {
private:
    int* array;
    int size;

public:
    ArrayContainer(int n);
    ~ArrayContainer();

    void generateRandomData();
    void display() const;
    void bubbleSort();
    void insertionSort();
};