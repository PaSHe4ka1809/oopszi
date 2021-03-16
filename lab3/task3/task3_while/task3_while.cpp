#include <iostream>;
using namespace std;

int i, n, k;
double s, res;

void print(int n, int k) {
	setlocale(LC_ALL, "RUS");
	i = 0;
	while (i < n) {
		s = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
		i++;
		if (i % k == 0)	continue;
		printf("Иттерация: %d ", i);
		printf(" Результат: %f\n", s);
	}
}

void main(int n, int k) {
	cout << "n:";
	cin >> n;
	cout << "k:";
	cin >> k;
	print(n, k);
}