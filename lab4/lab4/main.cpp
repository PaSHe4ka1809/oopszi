#include "rational.h"

using namespace std;

Rational y1(const Rational& x)
{
	return (Rational(2, 1) * x) + (Rational(13, 10) / x);
}

double y2(double x)
{
	return 2 * x + 1.3 / x;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Rational n1(1, 2);
	double x;
	cout << "y(x) = 2*x+1.3/x\n¬ведите x: " << endl;
	cin >> x;
	Rational x1 = n1.FromDoubleToRational(x);
	Rational res = y1(x1);
	res.Cancellation();
	cout << "Rational: y(" << x << ") = " << res << endl;
	Rational res2 = n1.FromDoubleToRational(y2(x));
	cout << "Double: y(" << x << ") = " << res2 << endl;
	system("pause");
	return 0;
}