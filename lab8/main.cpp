#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Рекурсивная функция для бинарного поиска
int binarySearch(int* arr, int x, int left, int right) {
    if (left > right) {
        return -1; // Элемент не найден
    }

    int mid = left + (right - left) / 2; // Избегаем переполнения

    if (arr[mid] == x) {
        return mid; // Элемент найден
    } else if (arr[mid] < x) {
        return binarySearch(arr, x, mid + 1, right); // Ищем в правой половине
    } else {
        return binarySearch(arr, x, left, mid - 1); // Ищем в левой половине
    }
}

int main() {
    // Открытие входного и выходного файлов
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Подсчет количества чисел в файле
    int size = 0;
    int temp;
    while (inputFile >> temp) {
        ++size;
    }

    // Проверка на пустой файл
    if (size == 0) {
        cerr << "Input file is empty." << endl;
        outputFile << "Input file is empty." << endl;
        inputFile.close();
        outputFile.close();
        return 1;
    }

    // Возврат в начало файла для чтения данных
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // Создание динамического массива
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        inputFile >> arr[i];
    }

    inputFile.close();

    // Сортировка массива
    sort(arr, arr + size);

    // Ввод элемента для поиска
    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    // Вызов бинарного поиска
    int result = binarySearch(arr, x, 0, size - 1);

    // Запись результата в файл
    if (result != -1) {
        outputFile << "Element " << x << " found at index " << result << " in the sorted array." << endl;
        cout << "Element " << x << " found at index " << result << " in the sorted array." << endl;
    } else {
        outputFile << "Element " << x << " not found in the array." << endl;
        cout << "Element " << x << " not found in the array." << endl;
    }

    // Освобождение памяти
    delete[] arr;
    outputFile.close();
    return 0;
}
