#include <iostream>
#include <stack>

template <typename T>
void displayStack(const std::stack<T>& stk) {
    std::stack<T> temp = stk;
    std::cout << "Stack contents: ";
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << '\n';
}

int main() {
    std::stack<int> myStack;

    myStack.push(4);
    myStack.push(3);
    myStack.push(1);
    myStack.push(2);
    myStack.push(4);

    displayStack(myStack);

    myStack.pop();

    displayStack(myStack);

    std::stack<int> myStackWithMin;

    myStackWithMin.push(4);
    myStackWithMin.push(3);
    myStackWithMin.push(1);
    myStackWithMin.push(2);
    myStackWithMin.push(4);

    displayStack(myStackWithMin);

    int minElement = myStackWithMin.top();
    myStackWithMin.pop();

    displayStack(myStackWithMin);

    std::cout << "Минимальный элемент в стеке: " << minElement << '\n';

    return 0;
}
