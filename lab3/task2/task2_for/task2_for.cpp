#include <iostream>;
using namespace std;

double eps, s, res;

double sum2(double eps) {
	s = 0;
	for (int i = 0; ; i++) {
		s += pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
		if (abs(s) < eps) break;
	}
	return s;
}

void main(double eps) {
	setlocale(LC_ALL, "RUS");
	cout << "eps:";
	cin >> eps;
	res = sum2(eps);
	cout << "Сумма:" << s << endl;
}