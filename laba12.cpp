//Задание 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Book {
private:
    string author;
    string title;
    string type; // "Художественная" или "Техническая"

public:
    // Пользовательский конструктор
    Book(const string& author, const string& title, const string& type) {
        if (author.empty() || title.empty()) {
            throw invalid_argument("Автор и название книги не могут быть пустыми.");
        }
        this->author = author;
        this->title = title;
        this->type = type;
    }

    void DisplayInfo() const {
        cout << "Автор: " << author << "\n"
            << "Название: " << title << "\n"
            << "Тип: " << type << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void AddBook(const Book& book) {
        books.push_back(book);
    }

    void ShowBooks() const {
        for (const auto& book : books) {
            book.DisplayInfo();
            cout << "-------------------" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Library library;

    try {
        library.AddBook(Book("Лев Толстой", "Война и мир", "Художественная"));
        library.AddBook(Book("Исаак Ньютон", "Математические начала натуральной философии", "Техническая"));
        library.AddBook(Book("Фёдор Достоевский", "Преступление и наказание", "Художественная"));
        library.AddBook(Book("Алан Тьюринг", "Числа в компьютерах", "Техническая"));

        cout << "Книги в библиотеке:" << endl;
        library.ShowBooks();
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
/*Задание 2
#include <iostream>
#include <string>

using namespace std;


void printBookCount(int fictionCount, int technicalCount) {
    int choice;

    cout << "Выберите тип литературы для отображения количества:" << endl;
    cout << "1. Художественная литература" << endl;
    cout << "2. Техническая литература" << endl;
    cout << "Введите ваш выбор (1 или 2): ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Количество художественной литературы: " << fictionCount << endl;
        break;
    case 2:
        cout << "Количество технической литературы: " << technicalCount << endl;
        break;
    default:
        cout << "Некорректный ввод! Пожалуйста, введите 1 или 2." << endl;
        break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int fictionCount = 120;
    int technicalCount = 80;

    // Вызов функции для вывода количества книг
    printBookCount(fictionCount, technicalCount);

    return 0;
}
*/