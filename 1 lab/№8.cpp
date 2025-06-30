#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long n, i;
    cin >> n;
    if (n <= 1) {
        cout << "ivalid input";
        return 0;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << "sostavnoe";
            return 0;
        }
    
    }
    cout << "prostoe";
    return 0;
}