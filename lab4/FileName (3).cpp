#include <iostream>
#include <stdlib.h>
#include <algorithm> 
using namespace std;
void choise(long*& Arr, int n) {
    for (int startI = 0; startI < n - 1; startI++)
    {
        int smallestI = startI;
        for (int currentI = startI + 1; currentI < n; currentI++)
        {
            if (Arr[currentI] > Arr[smallestI]) {
                smallestI = currentI;
            }
        }
        swap(Arr[startI], Arr[smallestI]);
    }
}
void Shella(long*& Arr, int n) {
    {
        int h, i, t;
        int k;   
        h = n / 2;  
        while (h > 0)
        {
            k = 1;
            while (k)
            {  
                k = 0;
                for (i = 0; i < n - h; i++)
                {
                    if (Arr[i] < Arr[i + h])
                    {
                        t = Arr[i]; Arr[i] = Arr[i + h]; Arr[i + h] = t;
                        k = 1;      
                    }
                }
            }
            h = h / 2;  
        }
    }
}
int Cmp(const void* val1, const void* val2) {
    long a, b;
    a = *(long*)val1;
    b = *(long*)val2;
    if (a > b) return -1;
    if (a < b) return 1;
    if (a == b) return 0;
}
int Comp(const void* val1, const void* val2) {
    long a, b;
    a = *(long*)val1;
    b = *(long*)val2;
    if (a > b) return 1;
    if (a < b) return -1;
    if (a == b) return 0;
}

    int main() {
        setlocale(LC_ALL, "Russian");
        srand(time(NULL));
        long n, f;
        cout << "Введите количество элементов массива: ";
        cin >> n;
        long* Arr;
        Arr = new long[n];
        for (int i = 0; i < n; i++)
        {
            Arr[i] = rand() % 100;
        }
        choise(Arr, n); 
        cout << "Массив c сортировкой выбором:" << endl;
        for (int i = 0; i < n; i++) {
            cout << Arr[i] << " ";
        }
        Shella(Arr, n);
        cout << endl << "Массив c сортировкой Шелла:" << endl;
        for (int i = 0; i < n; i++) {
            cout << Arr[i] << " ";
        }
        qsort(Arr, n, sizeof(long), Cmp);
        cout << endl << "Массив c сортировкой по убыванию через qsort:" << endl;
        for (int i = 0; i < n; i++) {
            cout << Arr[i] << " ";
        }
        sort (Arr, Arr+n);
        cout << endl << "Массив c сортировкой sort:" << endl;
        for (int i = 0; i < n; i++) {
            cout << Arr[i] << " ";
        }
        cout << endl  << "Введите что искать" << endl;
        cin >> f;
        sort (Arr, Arr + n);
        long* s = (long*)bsearch(&f, Arr, n, sizeof(long), Comp);
        cout << "Элемент = " << s-Arr+1 << endl;
        return 0;
    }