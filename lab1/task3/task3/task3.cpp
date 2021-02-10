#include <iostream>
using namespace std;

double f(double x);

void main() {
	double x, result;
	x = 5;
	result = f(x);
	cout << result << endl;
	cin >> x;
	result = f(x);
	cout << result << endl;
	cin >> x;
}

double f(double x) {
	double func;
	func = (1 - 2 * (sin(x) * sin(x)) / 1 + sin(x) * sin(x));
	return func;
}