// arrayOperations.hpp
#pragma once

#include <iostream>
#include <algorithm>

class ArrayOperations {
public:
    ArrayOperations(int studentNumber);

    void fillArray();
    void sortArrays();
    void findKeys();

private:
    int *array;
    int size;

    int binarySearch(int key);
    int interpolationSearch(int key);
};
