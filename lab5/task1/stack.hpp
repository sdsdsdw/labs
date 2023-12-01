// stack.hpp
#pragma once

#include "node.hpp"
#include <iostream>

template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    Stack() : top(nullptr) {}

    void push(T value);
    void pop();
    bool isEmpty() const;
    void display() const;
    T findMin() const;
};
