#pragma once
#include <iostream>
using namespace std;

class Rational
{
	int m, n;
	void Reduct();
public:
	Rational ();
	Rational (int _m, int _n);
	Rational (double a);
	Rational operator +(Rational B);
	Rational operator -(Rational B);
	Rational operator *(Rational B);
	Rational operator /(Rational B);
	Rational operator +(int B);
	Rational operator-(int B);
	Rational operator *(int B);
	Rational operator /(int B);
	void operator = (Rational B);
	void operator = (int B);
	void operator +=(Rational B);
	void operator -=(Rational B);
	void operator *=(Rational B);
	void operator /=(Rational B);
	void operator +=(int B);
	void operator -=(int B);
	void operator *=(int B);
	void operator /=(int B);
	friend ostream & operator <<(ostream &os, const Rational & num);
	friend istream& operator >>(istream & os, Rational  &num);
};
