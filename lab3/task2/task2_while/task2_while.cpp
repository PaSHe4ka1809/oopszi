#include <iostream>;
using namespace std;

int i;
double eps, s, res;

double sum(double eps) {
	i = 0;
	s = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
	while (abs(s) > eps) {
		i++;
		s += pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
	}
	return s;
}

void main(double eps) {
	setlocale(LC_ALL, "RUS");
	cout << "eps:";
	cin >> eps;
	res = sum(eps);
	cout << "Сумма:" << s << endl;
}