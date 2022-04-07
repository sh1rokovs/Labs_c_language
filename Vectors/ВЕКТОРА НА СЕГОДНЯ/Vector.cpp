#include <iostream>
#include"Header.h"
#include <fstream> 

using namespace std;

Vector::Vector(int n)
{
	size = n;
	mas = new double[size];
	for (int i = 0; i < n; i++)
		mas[i] = 0;
}

 Vector::~Vector()
{
   delete[] mas;
}
 
 //Конструктор копирования
 Vector::Vector(const Vector &b)
 {
	 size = b.size;
	 mas = new double[size];
	 for (int i = 0; i < size; i++)
		 mas[i] = b.mas[i];
 }
 
 double& Vector::operator[](int i) 
 {
	 return mas[i];
 }

 Vector Vector::operator+(Vector y)
 {
	 Vector res(size);
	 for (int i = 0; i < size; i++)
	 {
		 res.mas[i] = mas[i] + y.mas[i];
	 }
	 return res;
 }

 void Vector :: operator+=(const Vector &y)
 {
	 for (int i = 0; i < size; i++)
		 mas[i] += y.mas[i];
 }

 //скаляр. произв
 double Vector::operator*(const Vector &y)
 {
	 double res = 0.0;
	 for (int i = 0; i < size; i++)
		 res += mas[i] *y.mas[i];
	 return res;
 }

 Vector  operator*(double d, const Vector &y)
 {
	 Vector res(y.size);
	 for (int i = 0; i < y.size; i++)
		 res.mas[i] = d * y.mas[i];
	 return res;
 }

 Vector& Vector::operator=(const Vector &y)
 {
	 if (size != y.size)
	 {
		 delete[]mas;
		 size = y.size;
		 mas = new double[size];
	 }
	 for (int i = 0; i < size; i++)
		 mas[i] = y.mas[i];
	 return *this;
 }
	 /*
	 // вывод в поток
 ostream& operator<<(ostream& OS, const Vector &y)
 {
	OS << y.size << " ";
	 for (int i = 0; i < y.size; i++)
		 OS << y.mas[i] << " ";
	 OS << endl;
	 return OS;
 }
 // ввод из потока
 istream& operator>>(istream& OS, Vector &y)
 {
	 int strsize;
	 OS >> strsize;
	 if (y.size != strsize)
	 {
    	 delete[] y.mas;
		 y.size = strsize;
		 y.mas = new double[strsize];
	 }
	 for (int i = 0; i < y.size; i++)
		 OS >> y.mas[i];
	 return OS;
 }
 */