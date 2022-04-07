#include "Rational.h"

istream & operator >>(istream & os, Rational &num) 
{
	os >> num.m>>num.n;
	return os;
}
ostream & operator <<(ostream &os, const Rational &num) 
{
	if (num.n != 1)
		os << num.m << "/" << num.n;
	else
		os << num.m;
	return os;
}