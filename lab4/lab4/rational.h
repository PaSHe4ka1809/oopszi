#include "math.h"
#include <iostream>

using namespace std;

class Rational
{
private:
	int nominator, denominator;
public:
	Rational();
	Rational(int nom, int den);
	int getNominator() const;
	int getDenominator() const;
	void Cancellation();
	Rational FromDoubleToRational(double nom);
	Rational operator*(const Rational& rhs);
	Rational operator/(const Rational& rhs);
	friend Rational operator+(Rational A, Rational B);
	friend ostream & operator<<(ostream& out, const Rational& a);
};

