
#include <iostream>
using namespace std;
int main() {
	long long n, i = 1;
	cout << "Enter natural number";
	cin >> n;
	if (n < 0) {
		cout << "invalid input" << endl;
		return 0;
	}
	if (n == 0) {
		cout << "1" << endl;
		return 0;
	}
	while (n >= 2) {
		i = i * n;
		n--;
	}
 {
	cout << i << endl;
		}
		return 0;	
}