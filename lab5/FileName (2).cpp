#include <iostream>
using namespace std;
int main() {
  setlocale(LC_ALL, "Russian");
  srand(time(NULL));
    printf("������� ������� �������:");
    printf("\n");
    size_t n, m;
        int r;
   cin >> n >> m;
   char s[] = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
    int** mtrx = new int* [n];
    for (size_t  i = 0; i < n; i++)
    {
        mtrx[i] = new int[m];
        for (size_t j = 0; j < m; j++)
        {
            mtrx[i][j] = s[rand() % sizeof(s)-1];  
            printf (" % c",  mtrx[i][j]);
        } 
        printf("\n");
    }
    printf("\n");
    printf( "�������� �� 180 ��������");
    printf("\n");
    printf("\n");
    for (size_t  i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++) {
            printf(" % c", mtrx[n - i - 1][m - j - 1]);
        }
          printf("\n");
    }
    return 0;
}

 
