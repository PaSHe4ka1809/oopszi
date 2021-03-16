#include <iostream>;
using namespace std;

int i, k;
double eps, res;
double s = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));

int findFirstElement(double eps) {
	i = 0;
	do {
		if (abs(s) <= eps) break;
		i++;
		k = i;
		s = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
	} while (true);
	return k;
}

void main(double eps) {
	setlocale(LC_ALL, "RUS");
	cout << "eps:";
	cin >> eps;
	res = findFirstElement(eps);
	cout << "Первый член последовательности:" << res << endl;
}