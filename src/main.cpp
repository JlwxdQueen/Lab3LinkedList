#include <windows.h>
#include <iostream>
#include "../include/tests.h"
#include "../include/badTests.h"

void displayMenu() {
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Запустить тесты" << std::endl;
    std::cout << "2. Запустить ЗЛЫЕ тесты" << std::endl;
    std::cout << "0. Выход" << std::endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice;

    while (true) {
        displayMenu();
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                makeTests();
            return 0;

            case 2:
                makeBadTests<int>();
            return 0;

            case 0:
                std::cout << "Выход из программы." << std::endl;
            return 0;

            default:
                std::cout << "Неверный выбор, пожалуйста, попробуйте снова." << std::endl;
            break;
        }
    }
}
