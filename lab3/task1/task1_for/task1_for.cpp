#include <iostream>;
using namespace std;

int n;
double s, res;

double sum(int n) {

	for (int i = 0; i < n; i++) {
		s += pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
	}
	return s;
}

void main(void) {
	setlocale(LC_ALL, "RUS");
	cout << "n:";
	cin >> n;
	res = sum(n);
	cout << "Сумма:" << s << endl;
}