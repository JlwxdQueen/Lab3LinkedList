#ifndef BADTESTS_H
#define BADTESTS_H

#include <iostream>
#include "../include/linkedlist.h"

template<typename T>
void makeBadTests() {
    LinkedList<T> list;

    std::cout << "Тесты на ошибки:" << std::endl;

    // Попытка удалить элемент из пустого списка
    std::cout << "Попытка удалить элемент из пустого списка..." << std::endl;
    list.pop_front();

    // Поиск элемента в пустом списке
    std::cout << "Попытка найти элемент по индексу 0 в пустом списке..." << std::endl;
    try {
        list.find(0);
    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    // Попытка удаления элемента по индексу из пустого списка
    std::cout << "Попытка удалить элемент по индексу 0 из пустого списка..." << std::endl;
    try {
        list.removeIndexFromList(0);
    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    // Проверка наличия элемента в пустом списке
    std::cout << "Проверка наличия элемента 10 в пустом списке..." << std::endl;
    const bool contains = list.contains(10);
    std::cout << "Список содержит элемент 10? " << (contains ? "Да" : "Нет") << std::endl;

    // Попытка добавления элемента 5 в пустой список
    std::cout << "Попытка добавления элемента 5 в пустой список..." << std::endl;
    list.addBeginElemToList(5);

    // Проверка размера списка
    std::cout << "Размер списка: " << list.size() << std::endl;
}

#endif
