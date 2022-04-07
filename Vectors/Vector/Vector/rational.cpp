#include "Rational.h"
#include <iostream>
using namespace std;

void Rational::Reduct()
{
	int tm, tn;
	tm = abs(m);
	tn = abs(n);
	if (tn != 0 && tm != 0)
	{
		while (tm != tn)
			if (tm > tn)
				tm -= tn;
			else
				tn -= tm;
		m /= tm;
		n /= tm;
	}

}

Rational::Rational(double a)
{
	m=0;
	n=1;
}

Rational::Rational(int _m, int _n)
{
	m=_m;
	n=_n;
}

Rational::Rational()
{
	m=0;
	n=1;
}

Rational Rational::operator +(Rational B)
{
	Rational res;
	res.m = m*B.n + B.m*n;
	res.n = n*B.n;
	res.Reduct();
	return res;
}
Rational Rational ::operator - (Rational B)
{
	Rational res;
	res.m = m*B.n - n*B.m;
	res.n = n*B.n;
	res.Reduct();
	return res;
}
Rational Rational ::operator *(Rational B)
{
	Rational res;
	res.m = m*B.m;
	res.n = n*B.n;
	res.Reduct();
	return res;
}
Rational Rational ::operator/(Rational B)
{
	Rational res;
	res.m = m*B.n;
	res.n = n*B.m;
	res.Reduct();
	return res;
}

Rational Rational::operator +(int B)
{
	Rational res;
	res.m = m + B*n;
	res.n = n;
	res.Reduct();
	return res;
}
Rational Rational ::operator -(int B)
{
	Rational res;
	res.m = m - B*n;
	res.n = n;
	res.Reduct();
	return res;
}
Rational Rational ::operator *(int B)
{
	Rational res;
	res.m = m*B;
	res.n = n;
	res.Reduct();
	return res;
}
Rational Rational ::operator/(int B)
{
	Rational res;
	res.m = m;
	res.n = n*B;
	res.Reduct();
	return res;
}

void Rational:: operator =(Rational B)
{
	m = B.m;
	n = B.n;

}
void Rational ::operator = (int B)
{
	if ( B!= 0)
	{
		m = B;
		n = 1;
	}
	else 
	{
		m = 0;
		n = 0;
	}
}

void Rational:: operator +=(Rational B)
{
	m = m*B.n + n*B.m;
	n = n*B.n;
	Reduct();
}
void Rational ::operator -=(Rational B)
{
	m = m*B.n - n*B.m;
	n = n*B.n;
	Reduct();
}
void Rational ::operator *=(Rational B)
{
	m = m*B.m;
	n = n*B.n;
	Reduct();
}
void Rational ::operator/=(Rational B)
{
	m = m*B.n;
	n = n*B.m;
	Reduct();
}
void Rational :: operator+=(int B)
{
	m = m + n*B;
	Reduct();
}
void Rational :: operator -=(int B)
{
	m = m - n*B;
	Reduct();
}
void Rational ::operator *=(int B)
{
	m = m *B;
	Reduct();
}
void Rational ::operator /=(int B)
{
	n = n*B;
	Reduct();
}
