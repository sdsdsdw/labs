/* 
    *   Створити динамічну структуру згідно зі своїм варіантом з використан-
    *   ням шаблонів бібліотеки STL.
    *
    *   Створити стек з цілими числами за допомогою однозв'язного списку.
    *   Реалізувати операції push та pop для додавання та видалення елементів зі стеку
    *   відповідно. Додати числа 4, 3, 1, 2, 4 до стеку та вивести його вміст. Видалити
    *   один елемент зі стеку, вивести вміст стеку знову. Знайти мінімальний елемент,
    *   який належить стеку.  
*/

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
