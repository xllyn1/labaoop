#include <iostream>
#include <string>
using namespace std;


class Publication {
protected:
    string title;
    float price;

public:

    virtual void getdata() {
        cout << "Введите название: ";
        cin.clear();
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }


    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }
};


class Book : public Publication {
private:
    int pages;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
};


class Audio : public Publication {
private:
    int duration;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> duration;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << duration << " минут" << endl;
    }
};


int main() {
    system("chcp 1251");
    Book book;
    Audio audio;
    cout << "Введите данные для книги:\n";
    book.getdata();
    cin.ignore();
    cout << "\nВведите данные для аудиозаписи:\n";
    audio.getdata();

    cout << "\nДанные о книге:\n";
    book.putdata();

    cout << "\nДанные об аудиозаписи:\n";
    audio.putdata();

    return 0;
}
