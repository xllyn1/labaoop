#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int n;

    cout << "Введите количество целых чисел в массиве: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть положительным!" << endl;
        return 1;
    }

    int* arr = new int[n];

    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Содержимое массива:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << ", адрес: " << &arr[i]
            << ", расстояние от начала массива: " << (reinterpret_cast<char*>(&arr[i]) - reinterpret_cast<char*>(arr)) << " байт" << endl;
    }


    cout << "Адрес начала массива: " << arr << endl;

    delete[] arr;

    return 0;
}
