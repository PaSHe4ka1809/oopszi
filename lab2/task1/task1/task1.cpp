#include <iostream>
using namespace std;

bool IsInArea(double x, double y) {
	if (x * x + y * y < 1) return true;
	else if ((x >= -1) && (x <= 0) && (y <= 1) && (y >= -1)) return true;
	else return false;
}

void main(double x, double y) {
	bool result;
	setlocale(LC_ALL, "RUS");
	cout << "x:";
	cin >> x;
	cout << "y:";
	cin >> y;
	result = IsInArea(x, y);
	if (result == true) cout << "Точка находится в закрашенной области\n";
	else cout << "Точка НЕ находится в закрашенной области\n";
	system("pause");
}
