// ���� Vector.cpp ---------------------------------------
#include <iostream>
//#include <fstream>
using namespace std;
//extern std::ofstream cout;

#include "Vector.h"
// ���������� �� ���������
Vector::Vector()
{
	size = 0;
	mas = NULL;
}
// ���������� �������������
Vector::Vector(int _size): size(_size)
{
	mas = new double[size];
}
 // ���������� �������������
Vector::Vector(int _size, double d): size(_size)
{
	mas = new double[size];
	for ( int i = 0; i < size; ++i )
		mas[i] = d;
}
// ���������� �������������
Vector::Vector(int _size, double* ar): size(_size)
{
	mas = new double[size];
	for ( int i = 0; i < size; ++i )
		mas[i] = ar[i];
}
// ���������� �����������
Vector::Vector(const Vector &vec) {
	size = vec.size;
	mas = new double[size];
	for ( int i = 0; i < size; ++i )
		mas[i] = vec.mas[i];
}
// ����������
Vector::~Vector() {
	if (mas != NULL )
	{
		delete[] mas;
		mas = NULL;
		size = 0;
	}
}

// ����� �� �������
void Vector::outPut(const char* name)  {
	cout << name << ": ";
	for ( int i = 0; i < size; ++i )
		cout << mas[i] << ",\t";
	cout << endl;
}
void Vector::outPut(const char* name) const {
	cout << name << ": ";
	for ( int i = 0; i < size; ++i )
		cout << mas[i] << ",\t";
	cout << endl;
}

// ���������� ��������

// ��� ������ � ������
double& Vector::operator[](int index)  {
	if ( index < 0 || index >= size )
		abort(); // �������������� ���������� ���������
	return mas[index];
}

// ������ ��� ������ � ����������� ������� � ��������
const double& Vector::operator[](int index) const   {
	if ( index < 0 || index >= size )
		abort(); // �������������� ���������� ���������
	return mas[index];
}

// �������� ������������	
Vector& Vector::operator=(const Vector &vec) {
	if ( this != &vec ) { // �� ���� ����������� ���� ����!
		if ( size != vec.size )
		{
			delete[]mas;
			size = vec.size;
			mas = new double[size];
		}
		for ( int i = 0; i < size; ++i )
			mas[i] =  vec.mas[i];
	}
	return *this;
}

// �������� ������������
Vector  Vector::operator+(const Vector &vec)  {
	if ( size != vec.size )
		abort(); // �������������� ���������� ���������
	Vector res(size);
	for ( int i = 0; i < size; ++i )
		res.mas[i] = mas[i] + vec.mas[i];
	return res;
}

// �������� ���������� ������������
double  Vector::operator*(const Vector &vec)  {
	if ( size != vec.size )
		abort(); // �������������� ���������� ���������
	double res = 0.0;
	for ( int i = 0; i < size; ++i )
		res += mas[i] * vec.mas[i];
	return res;	
} 
 // �������� ��������� ��������������� �� ������
Vector  operator*(double d, const Vector &vec)  {
	Vector res(vec.size);
	for ( int i = 0; i < vec.size; ++i )
		res.mas[i] = d * vec.mas[i];
	return res;	
}

/* // ����� � �����
ostream& operator<<(ostream& stream, const Vector &vec)  {
	stream << vec.size << " ";
	for ( int i = 0; i < vec.size; ++i )
		stream << vec.mas[i] << " ";
	stream << endl;
	return stream;
}
 // ���� �� ������
istream& operator>>(istream& stream,       Vector &vec)  {
	int strsize;
	stream >> strsize;
	if ( vec.size != strsize )
	{
		if ( vec.mas != NULL )
			delete[] vec.mas;
		vec.size = strsize;
		vec.mas = new double[strsize];
	}
	for ( int i = 0; i < vec.size; ++i )
		stream >> vec.mas[i];
	return stream;
}
*/
