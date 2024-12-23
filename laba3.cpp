//Задание 1
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Detail {
protected:
    Detail() {
        cout << "Создана деталь" << endl;
    }

public:
    virtual void display() const = 0;
    virtual ~Detail() {}
};
class Assembly : public Detail {
protected:
    Assembly() {
        cout << "Создана сборка" << endl;
    }

public:
    void display() const override {
        cout << "Это сборка" << endl;
    }

    static shared_ptr<Assembly> create() {
        return shared_ptr<Assembly>(new Assembly());
    }
};
class SpecialDetail : public Detail {
protected:
    SpecialDetail() {
        cout << "Создана специальная деталь" << endl;
    }

public:
    void display() const override {
        cout << "Это специальная деталь" << endl;
    }

    static shared_ptr<SpecialDetail> create() {
        return shared_ptr<SpecialDetail>(new SpecialDetail());
    }
};

template<typename T>
void addDetail(vector<shared_ptr<Detail>>& storage) {
    storage.push_back(T::create());
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<shared_ptr<Detail>> storage;

    addDetail<Assembly>(storage);
    addDetail<SpecialDetail>(storage);

    for (const auto& detail : storage) {
        detail->display();
    }

    return 0;
}
/*Задание 2
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;
class Base {
public:
    virtual void show() const {
        cout << "Это объект базового класса." << endl;
    }

    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() const override {
        cout << "Это объект производного класса." << endl;
    }
};

void add(vector<shared_ptr<Base>>& storage, shared_ptr<Base> obj) {
    storage.push_back(obj);
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    vector<shared_ptr<Base>> storage;

    for (int i = 0; i < 10; ++i) {
        int randomNum = rand();
        if (randomNum % 2 == 0) {
            add(storage, make_shared<Base>());
        }
        else {
            add(storage, make_shared<Derived>());
        }
    }

    for (const auto& obj : storage) {
        obj->show();
    }

    return 0;
}
*/