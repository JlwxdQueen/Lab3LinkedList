#ifndef TESTS_H
#define TESTS_H
#include <iostream>
#include "../include/linkedlist.h"

inline void makeTests() {

    LinkedList<int> list;

    // Создаем список
    list.createList();
    std::cout << "Список создан. Пустой? " << (list.isEmpty() ? "Да" : "Нет") << std::endl;

    // Добавляем элементы
    std::cout << "Добавляем элемент 10 в пустой список..." << std::endl;
    list.addEndElemToEmptyList(10);
    std::cout << "Пустой? " << (list.isEmpty() ? "Да" : "Нет") << std::endl;

    std::cout << "Добавляем элемент 20 в список..." << std::endl;
    list.addEndElemToList(20);

    std::cout << "Добавляем элемент 30 в список..." << std::endl;
    list.addEndElemToList(30);

    std::cout << "Текущие элементы после добавления:" << std::endl;
    list.printList();

    // Сортируем список
    std::cout << "Добавляем элемент 25 в список..." << std::endl;
    list.addEndElemToList(25);
    std::cout << "Сортируем список..." << std::endl;
    list.sort();
    std::cout << "Элементы после сортировки:" << std::endl;
    list.printList();

    // Удаляем элемент
    std::cout << "Удаляем элемент 20 из списка..." << std::endl;
    list.removeElemFromList(20);
    std::cout << "Элементы после удаления:" << std::endl;
    list.printList();

    // Проверка на нахождение элемента
    std::cout << "Содержит ли список элемент 30? "
              << (list.contains(30) ? "Да" : "Нет") << std::endl;

    std::cout << "Содержит ли список элемент 20? "
              << (list.contains(20) ? "Да" : "Нет") << std::endl;

    // Удаление элемента по индексу
    std::cout << "Удаляем элемент по индексу 0..." << std::endl;
    list.removeIndexFromList(0);
    std::cout << "Элементы после удаления по индексу:" << std::endl;
    list.printList();

    // Проверяем размер списка
    std::cout << "Размер списка: " << list.size() << std::endl;

    // Удаляем все элементы
    std::cout << "Удаляем все элементы..." << std::endl;
    while (!list.isEmpty()) {
        list.pop_front();
    }

    std::cout << "Список пуст? " << (list.isEmpty() ? "Да" : "Нет") << std::endl;
}

#endif
