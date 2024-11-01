#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>

template <typename T>
struct Element {
    T data;                   // Данные элемента
    Element<T>* next;         // Указатель на следующий элемент
};

template <typename T>
class LinkedList {

    Element<T>* begin;  // Указатель на первый элемент
    Element<T>* end;    // Указатель на последний элемент
    int count;          // Количество элементов в списке

public:
    LinkedList();
    ~LinkedList();

    void createList();                                  // Метод для инициализации списка
    void addEndElemToEmptyList(const T& data);          // Метод для добавления элемента в конец пустого списка
    void addEndElemToList(const T& data);               // Метод для добавления элемента в конец непустого списка
    void addBeginElemToList(const T& data);             // Метод для добавления элемента в начало списка
    Element<T>* move(int index);                        // Метод для перемещения к элементу перед указанным индексом
    void addCenterElemToList(const T& data, int index); // Метод для добавления элемента в центр списка
    [[nodiscard]] bool isEmpty() const;                 // Метод для проверки списка на наличие элементов
    Element<T>* createElement(const T& data);           // Метод для создания элемента
    void pop_front();                                   // Метод для удаления элемента из начала списка
    void pop_back();                                    // Метод для удаления элемента из конца списка
    void removeElemFromList(const T& data);             // Метод для удаления элемента через его содержимое
    void removeIndexFromList(int index);                // Метод для удаления элемента через его индекс
    Element<T>* find(int index);                        // Метод для нахождения элемента по индексу
    bool contains(const T& data) const;                 // Метод для проверки на нахождения элемента в списке
    void unique();                                      // Метод для удаления повторяющихся элементов
    void sort();                                        // Метод для сортировки списка
    Element<T>* getBegin() const;                       // Метод для получения ссылки на первый элемент
    Element<T>* getEnd() const;                         // Метод для получения ссылки на последний элемент
    int size() const;                                   // Метод для получения размера списка
    void printList() const;                             // Метод для вывода списка в консоль
};

template <typename T>
LinkedList<T>::LinkedList() : begin(nullptr), end(nullptr), count(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    Element<T>* current = begin;
    while (current != nullptr) {
        Element<T>* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

template <typename T>
void LinkedList<T>::createList() {
    begin = nullptr;
    end = nullptr;
    count = 0;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
Element<T>* LinkedList<T>::createElement(const T& data) {
    auto* elem = new Element<T>;
    elem->data = data;
    elem->next = nullptr;
    return elem;
}

template <typename T>
void LinkedList<T>::addEndElemToEmptyList(const T& data) {
    if (isEmpty()) {
        auto* elem = createElement(data);
        begin = end = elem;
        count++;
    } else {
        std::cerr << "Список не пуст. Используйте другой метод" << std::endl;
    }
}

template<typename T>
void LinkedList<T>::addEndElemToList(const T &data) {
    if (isEmpty()) {
        std::cerr << "Список пуст. Используйте другой метод" << std::endl;
    } else {
        auto* elem = createElement(data);
        end->next = elem;
        end = elem;
        count++;
    }
}

template<typename T>
void LinkedList<T>::addBeginElemToList(const T &data) {
    auto* elem = createElement(data);
    if (isEmpty()) {
        begin = end = elem;
    } else {
        elem->next = begin;
        begin = elem;
    }
    count++;
}


template<typename T>
Element<T>* LinkedList<T>::move(const int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Индекс за границами списка.");
    }

    Element<T>* current = begin;

    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current;
}

template<typename T>
void LinkedList<T>::addCenterElemToList(const T &data, const int index) {
    if (isEmpty()) {
        std::cerr << "Список пуст. Используйте другой метод" << std::endl;
    } else {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Индекс за границами списка");
        }

        auto* elem = createElement(data);
        Element<T>* elemPrev = move(index - 1);
        elem->next = elemPrev->next;
        elemPrev->next = elem;
        count++;
    }
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (isEmpty()) {
        std::cerr << "Список пуст" << std::endl;
    } else {
        const Element<T>* delElem = begin;
        begin = begin->next;
        delete delElem;
        count--;
    }
}

template<typename T>
void LinkedList<T>::pop_back() {
    if (isEmpty()) {
        std::cerr << "Список пуст" << std::endl;
        return;
    }
    if (count == 1) {
        delete begin;
        begin = end = nullptr;
    } else {
        Element<T>* current = begin;
        while (current->next != end) {
            current = current->next;
        }
        delete end;
        end = current;
        end->next = nullptr;
    }
    count--;
}

template<typename T>
void LinkedList<T>::removeElemFromList(const T& data) {
    if (isEmpty()) {
        std::cerr << "Список пуст" << std::endl;
        return;
    }

    Element<T>* current = begin;
    Element<T>* prev = nullptr;

    while (current != nullptr) {
        if (current->data == data) {
            if (prev == nullptr) {
                begin = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            count--;
            return;
        }
        prev = current;
        current = current->next;
    }

    std::cerr << "Элемент не найден" << std::endl;
}

template<typename T>
void LinkedList<T>::removeIndexFromList(const int index) {
    if (isEmpty()) {
        std::cerr << "Список пуст" << std::endl;
    } else if (index == 0) {
        pop_front();
    } else {
        Element<T>* elemPrev = move(index - 1);
        Element<T>* elemDel = elemPrev->next;
        elemPrev->next = elemDel->next;
        delete elemDel;
        count--;
    }
}

template <typename T>
Element<T>* LinkedList<T>::find(const int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Индекс за границами списка.");
    }

    Element<T>* current = begin;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current;
}

template <typename T>
bool LinkedList<T>::contains(const T& data) const {
    Element<T>* current = begin;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
void LinkedList<T>::unique() {
    if (isEmpty()) {
        std::cerr << "Список пуст." << std::endl;
        return;
    }

    Element<T>* current = begin;

    while (current != nullptr) {
        Element<T>* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                const Element<T>* toDelete = runner->next;
                runner->next = runner->next->next;
                delete toDelete;
                count--;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}


template<typename T>
void LinkedList<T>::sort() {
    if (isEmpty() || count == 1) {
        return;
    }

    Element<T>* sorted = nullptr;
    Element<T>* current = begin;

    while (current != nullptr) {
        Element<T>* next = current->next;

        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Element<T>* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    begin = sorted;
}


template<typename T>
Element<T>* LinkedList<T>::getBegin() const {
    return begin;
}

template<typename T>
Element<T>* LinkedList<T>::getEnd() const {
    return end;
}

template<typename T>
int LinkedList<T>::size() const {
    return count;
}

template<typename T>
void LinkedList<T>::printList() const {
    Element<T>* current = begin;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif
