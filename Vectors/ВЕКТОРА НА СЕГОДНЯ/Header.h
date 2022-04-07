#pragma once
#include <iostream>
#include <fstream> 

class Vector
{
	int size;
	double *mas;
public:
	Vector(int n);
	~Vector();
	//Перегрузки
	Vector(const Vector &b);
	double& operator[](int i);
	Vector operator+(Vector y);
	void  operator+=(const Vector &y);
	double operator*(const Vector &y);
	Vector& operator=(const Vector &y);
	friend Vector  operator*(double d, const Vector &y);
	//friend ostream& operator<<(ostream& OS, const Vector &y);
	//friend istream& operator>>(istream& OS, Vector &y);
};
Vector  operator*(double d, const Vector &y);
//ostream& operator<<(ostream& OS, const Vector &y);
//istream& operator>>(istream& OS, Vector &y);