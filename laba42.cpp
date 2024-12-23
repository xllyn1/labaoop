#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
using namespace std;
class Error {
public:
    virtual const char* what() const {
        return "Неизвестная ошибка.";
    }
};

class InvalidPointerError : public Error {
public:
    const char* what() const override {
        return "Ошибка: Ошибочный указатель.";
    }
};

class ListError : public Error {
public:
    const char* what() const override {
        return "Ошибка: Ошибка работы со списком.";
    }
};

class InvalidIndexError : public Error {
public:
    const char* what() const override {
        return "Ошибка: Недопустимый индекс.";
    }
};

class ListOverflowError : public Error {
public:
    const char* what() const override {
        return "Ошибка: Список переполнен.";
    }
};

template <typename T>
class PointerArray {
private:
    vector<T*> array;
    size_t capacity;

public:
    PointerArray(size_t cap) : capacity(cap) {}

    void add(T* obj) {
        if (array.size() >= capacity) {
            throw ListOverflowError();
        }
        array.push_back(obj);
    }

    T* operator[](size_t index) {
        if (index >= array.size()) {
            throw InvalidIndexError();
        }
        return array[index];
    }

    size_t size() const {
        return array.size();
    }

    ~PointerArray() {
        for (auto ptr : array) {
            delete ptr;
        }
    }
};

class Example {
public:
    void display() const {
        cout << "Это объект класса Example." << endl;
    }
};



int main() {
    setlocale(LC_ALL, "Russian");

    PointerArray<Example> exampleArray(5);

    try {
        for (int i = 0; i < 5; ++i) {
            exampleArray.add(new Example());
        }

        throw runtime_error("Ошибка выполнения: Пример исключения.");

        exampleArray.add(new Example());
    }
    catch (const ListError& e) {
        cerr << e.what() << endl;
    }
    catch (const InvalidIndexError& e) {
        cerr << e.what() << endl;
    }
    catch (const InvalidPointerError& e) {
        cerr << e.what() << endl;
    }
    catch (const ListOverflowError& e) {
        cerr << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Произошла ошибка выполнения: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Произошла неизвестная ошибка." << endl;
    }

    try {
        for (size_t i = 0; i < exampleArray.size(); ++i) {
            exampleArray[i]->display();
        }
    }
    catch (const InvalidIndexError& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

