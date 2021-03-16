#include <iostream>;
using namespace std;

double eps, s, res;
int k;

int findFirstNegativeElement(double eps) {
	s = 0;
	for (int i = 0; ; i++) {
		k = i;
		s = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
		if (s > 0) continue;
		if (abs(s) <= eps) {
			return k;
		}
	}
}

void main(double eps) {
	setlocale(LC_ALL, "RUS");
	cout << "eps:";
	cin >> eps;
	res = findFirstNegativeElement(eps);
	cout << "Первый отрицательный член последовательности:" << res << endl;
}