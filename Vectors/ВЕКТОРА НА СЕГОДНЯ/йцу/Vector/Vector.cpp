// ‘айл Vector.cpp ---------------------------------------
#include <iostream>
//#include <fstream>
using namespace std;
//extern std::ofstream cout;

#include "Vector.h"
//  онстуктор по умолчанию
Vector::Vector()
{
	size = 0;
	mas = NULL;
}
//  онстуктор инициализатор
Vector::Vector(int _size): size(_size)
{
	mas = new double[size];
}
 //  онстуктор инициализатор
Vector::Vector(int _size, double d): size(_size)
{
	mas = new double[size];
	for ( int i = 0; i < size; ++i )
		mas[i] = d;
}
//  онстуктор инициализатор
Vector::Vector(int _size, double* ar): size(_size)
{
	mas = new double[size];
	for ( int i = 0; i < size; ++i )
		mas[i] = ar[i];
}
//  онстуктор копировани€
Vector::Vector(const Vector &vec) {
	size = vec.size;
	mas = new double[size];
	for ( int i = 0; i < size; ++i )
		mas[i] = vec.mas[i];
}
// ƒеструктор
Vector::~Vector() {
	if (mas != NULL )
	{
		delete[] mas;
		mas = NULL;
		size = 0;
	}
}

// вывод на консоль
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

// ѕерегрузка операций

// дл€ чтени€ и записи
double& Vector::operator[](int index)  {
	if ( index < 0 || index >= size )
		abort(); // принудительное завершение программы
	return mas[index];
}

// только дл€ чтени€ в константных методах и объектах
const double& Vector::operator[](int index) const   {
	if ( index < 0 || index >= size )
		abort(); // принудительное завершение программы
	return mas[index];
}

// операци€ присваивани€	
Vector& Vector::operator=(const Vector &vec) {
	if ( this != &vec ) { // не надо присваивать себ€ себе!
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

// операци€ суммировани€
Vector  Vector::operator+(const Vector &vec)  {
	if ( size != vec.size )
		abort(); // принудительное завершение программы
	Vector res(size);
	for ( int i = 0; i < size; ++i )
		res.mas[i] = mas[i] + vec.mas[i];
	return res;
}

// операци€ скал€рного произведени€
double  Vector::operator*(const Vector &vec)  {
	if ( size != vec.size )
		abort(); // принудительное завершение программы
	double res = 0.0;
	for ( int i = 0; i < size; ++i )
		res += mas[i] * vec.mas[i];
	return res;	
} 
 // операци€ умножени€ действительного на вектор
Vector  operator*(double d, const Vector &vec)  {
	Vector res(vec.size);
	for ( int i = 0; i < vec.size; ++i )
		res.mas[i] = d * vec.mas[i];
	return res;	
}

/* // вывод в поток
ostream& operator<<(ostream& stream, const Vector &vec)  {
	stream << vec.size << " ";
	for ( int i = 0; i < vec.size; ++i )
		stream << vec.mas[i] << " ";
	stream << endl;
	return stream;
}
 // ввод из потока
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
