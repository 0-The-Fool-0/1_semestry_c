#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
        int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Некорректный ввод" << endl;
        return 0;
    }
        int* Arr;
        Arr = new int[n]; 
        
        int pos = n / 2;
        int neg = n - pos;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0 && neg > 0) {
                Arr[i] = -rand() % 100;
                neg--;
            }
            else {
                Arr[i] = rand() % 100;
                pos--;
            }
        }
cout << "Массив:" << endl;
for (int i = 0; i < n; i++) {
    cout << Arr[i] << " ";
}
return 0;
}