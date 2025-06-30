#include <iostream>
using namespace std;
int main() {
	long long s = 0, n, a=0;
	cin >> n;
	n = abs(n);
	a = n;
	while (a > 0) {
		s = s * 10 + a % 10;
		a /=10;
	}
	if (s == n && n>9) {
		cout << " Palindrom";
	}
	else {
		cout << " Ne Palindrom";
	}
	return 0;
}
