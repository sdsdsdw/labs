/*  *   Варіант 1
    *   1. Побудувати бінарне дерево, що містить n = 15 вузлів. Значення ключів
    *   у вузлах задавати датчиком випадкових чисел з діапазоном D від 0 до 100.
    *   2. Забезпечити симетричний обхід дерева.
    *   3. Здійснити пошук значення ключа.
    *   
    *   Завдання. 1. 
    *   Розробити динамічну структуру бінарного дерева пошуку
    *   згідно зі своїм варіантом, що реалізують алгоритми формування та обходу
    *   двійкових дерев, а також пошуку елементів у них.
    * 
    *   2. Створити колекцію map для парних варіантів – довідник лік (назва,
    *   призначення), для непарних – каталог «предметний вказівник» ( термін, номер
    *   сторінки). Продемонструвати основні функції шаблону map.
*/

#include "binaryTree.cpp"
#include <iostream>
#include <map>

int main() {
    // task 1:
    BinaryTree binaryTree;
    binaryTree.buildTree(15);

    std::cout << "Симетричний обхід дерева:" << '\n';
    binaryTree.inOrderTraversal();

    int searchKey = 32;
    TreeNode* foundNode = binaryTree.searchKey(searchKey);
    if (foundNode)
        std::cout << "Знайдено вузол з ключем " << searchKey << '\n';
    else
        std::cout << "Вузол з ключем " << searchKey << " не знайдено" << '\n';

    // task 2:
    std::map<int, std::string> medicalGuide;
    std::map<int, std::pair<std::string, int>> subjectCatalog;

    medicalGuide[1] = "Аспірин";
    medicalGuide[2] = "Парацетамол";
    medicalGuide[3] = "Ібупрофен";

    subjectCatalog[5] = std::make_pair("Алгоритм", 42);
    subjectCatalog[7] = std::make_pair("Структури даних", 77);
    subjectCatalog[9] = std::make_pair("Програмування", 123);

    std::cout << "\nМедичний довідник (парні варіанти):" << '\n';
    for (const auto& pair : medicalGuide) {
        std::cout << "Ключ: " << pair.first << ", значення: " << pair.second << '\n';
    }

    std::cout << "\nПредметний вказівник (непарні варіанти):" << '\n';
    for (const auto& pair : subjectCatalog) {
        std::cout << "Ключ: " << pair.first << ", термін: " << pair.second.first
                  << ", Сторінка: " << pair.second.second << '\n';
    }

    return 0;
}
