#include "stack.cpp"

int main() {
    Stack<int> myStack;

    myStack.push(4);
    myStack.push(3);
    myStack.push(1);
    myStack.push(2);
    myStack.push(4);

    std::cout << "Содержимое стека: ";
    myStack.display();

    myStack.pop();

    std::cout << "Содержимое стека после pop: ";
    myStack.display();

    int minElement = myStack.findMin();
    std::cout << "Минимальный элемент в стеке: " << minElement << '\n';

    return 0;
}
