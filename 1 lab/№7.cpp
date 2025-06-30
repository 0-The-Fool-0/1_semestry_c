#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double x, n;
	cout << "vvedite chislo vozvodimoe v stepen'";
	cin >> x;
	cout << "vvedite ctepen'";
	cin >> n;
	if (n == 0 && x == 0) {
		cout << "ne imeet smysla";
		return 0;
	}
	if (n<0 && x == 0) {
		cout << "delenie na 0 ne opredelenno";
		return 0;
	}
	if (n!= ceil(n) && x < 0) {
		cout << "answer in complex numbers";
		return 0;
	}
	pow(x, n);
	cout << pow(x, n);
	return 0;
}