#include <iostream>
#include "rational.h"

using namespace std;

Rational::Rational()
{
	nominator = 0;
	denominator = 1;
}

Rational::Rational(int n, int d)
{
	nominator = n;
	denominator = d;
}

int Rational::getNominator() const { return this->nominator; }
int Rational::getDenominator() const { return this->denominator; }

Rational Rational::FromDoubleToRational(double nom)
{
	double eps = 0.001;
	for (int i = 1;; i++) {
		double tem = nom / (1.0 / i);
		if (fabs(tem - round(tem)) < eps) {
			return Rational(round(tem), i);
			break;
		}
	}
}

ostream& operator << (ostream& stream, const Rational& a)
{
	if (a.nominator != 0)
	{
		stream << a.nominator << "/" << a.denominator;
	}
	return stream;
}

Rational operator+(Rational A, Rational B)
{
	return Rational(A.getNominator() * B.getDenominator() + B.getNominator() * A.getDenominator(), A.getDenominator() * B.getDenominator());
}

Rational Rational::operator*(const Rational& rhs)
{
	Rational result(
		this->nominator * rhs.nominator,
		this->denominator * rhs.denominator
	);

	return result;
}

Rational Rational::operator/(const Rational& rhs)
{
	Rational result(
		this->nominator * rhs.denominator,
		this->denominator * rhs.nominator
	);

	return result;
}

void Rational::Cancellation()
{
	if (nominator != 0)
	{
		int m = denominator,
			n = nominator,
			ost = m % n;
		while (ost != 0)
		{
			m = n; n = ost;
			ost = m % n;
		}
		int nod = n;
		if (nod != 1)
		{
			nominator /= nod; denominator /= nod;
		}
	}
}