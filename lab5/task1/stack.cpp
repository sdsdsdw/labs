#include "stack.hpp"

template <typename T>
void Stack<T>::push(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        std::cerr << "Помилка: Стек порожній. Неможливо виконати видалення.\n";
        return;
    }
    Node<T>* temp = top;
    top = top->next;
    delete temp;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
T Stack<T>::findMin() const {
    if (isEmpty()) {
        std::cerr << "Помилка: Стек порожній. Неможливо знайти мінімум.\n";
        return T();
    }

    T minElement = top->data;
    Node<T>* current = top->next;

    while (current != nullptr) {
        if (current->data < minElement) {
            minElement = current->data;
        }
        current = current->next;
    }

    return minElement;
}

template <typename T>
void Stack<T>::display() const {
    Node<T>* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}
