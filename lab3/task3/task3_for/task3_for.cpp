#include <iostream>;
using namespace std;

int i, n, k;
double s, res;

void print(int n, int k) {
	setlocale(LC_ALL, "RUS");
	for (i = 0;  i < n; i++) {
		if (i % k == k - 1) continue;
		s = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
			printf("Иттерация: %d ", i + 1);
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