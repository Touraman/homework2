#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "libr.h"

using namespace std;


// Конструктор по умолчанию
MyString::MyString() : p_str(nullptr) {}

// Конструктор с параметром
MyString::MyString(const char* str) {
    if (str) {
        p_str = new char[strlen(str) + 1];
        strcpy(p_str, str);
    }
    else {
        p_str = nullptr;
    }
}

// Конструктор копирования
MyString::MyString(const MyString& str) {
    if (str.p_str) {
        p_str = new char[strlen(str.p_str) + 1];
        strcpy(p_str, str.p_str);
    }
    else {
        p_str = nullptr;
    }
}

// Деструктор
MyString::~MyString() {
    delete[] p_str;
}

// Метод для установки строки
void MyString::set_string(const char* str) {
    if (p_str) {
        delete[] p_str;
    }
    if (str) {
        p_str = new char[strlen(str) + 1];
        strcpy(p_str, str);
    }
    else {
        p_str = nullptr;
    }
}

// Метод для получения строки
const char* MyString::get_string() const {
    return p_str;
}

// Оператор присваивания
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) { // Проверка на самоприсваивание
        delete[] p_str; // Освобождаем старую память
        if (other.p_str) {
            p_str = new char[strlen(other.p_str) + 1];
            strcpy(p_str, other.p_str);
        }
        else {
            p_str = nullptr;
        }
    }
    return *this;
}

int main() {
    // Конструктор с параметром
    MyString str1("Hello");
    cout << "String 01:" << endl;
    cout << str1.get_string() << endl;

    // Оператор присваивания
    MyString str2;
    str2 = str1;
    cout << "String 02 before changes:" << endl;
    cout << str2.get_string() << endl;

    // Изменение строки
    cout << "String 02 after changes:" << endl;
    str2.set_string("San Petersburg");
    cout << str2.get_string() << endl;

    return 0;
}