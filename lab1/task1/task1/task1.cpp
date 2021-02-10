#include <iostream>
using namespace std;

void main(double f, double x) {
	x = 5;
	f = (1 - 2 * (sin(x) * sin(x)) / 1 + sin(x) * sin(x));
	cout << f << endl;
	cin >> x;
	f = (1 - 2 * (sin(x) * sin(x)) / 1 + sin(x) * sin(x));
	cout << f << endl;
	cin >> x;
}