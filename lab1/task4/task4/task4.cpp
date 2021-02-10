#include <iostream>
using namespace std;

double x, result;
void f(void);

void main() {
	x = 5;
	f();
	cout << result << endl;
	cin >> x;
	f();
	cout << result << endl;
	cin >> x;
}

void f(void) {
	result = (1 - 2 * (sin(x) * sin(x)) / 1 + sin(x) * sin(x));
}