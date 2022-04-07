// Файл Vector.h ---------------------------------------
#pragma once
#include <fstream> 

class Vector {
public:
	Vector();        // Констуктор по умолчанию
	explicit Vector(int _count);    // Констуктор инициализатор
	Vector(int _count, double d);   // Констуктор инициализатор
	Vector(int _count, double* ar); // Констуктор инициализатор
	Vector(const Vector &vec);      // Констуктор копирования
	~Vector();                      // Деструктор
	// вывод на консоль
	void outPut(const char* name);
	void outPut(const char* name) const;

	// Перегрузка операций
	double& operator[](int index);       // для чтения и записи
	const double& operator[](int index) const; // только для чтения в константных методах и объектах
	
	Vector& operator=(const Vector &vec); // операция присваивания
	Vector  operator+(const Vector &vec); // операция суммирования
	double  operator*(const Vector &vec); // операция скалярного произведения
	friend Vector  operator*(double d, const Vector &vec); // операция умножения действительного на вектор
    friend ostream& operator<<(ostream& stream, const Vector &vec); // вывод в поток
    friend istream& operator>>(istream& stream,       Vector &vec); // ввод из потока
 
private:
	double *mas; // массив компонент вектора 
	int size;    // количество компонент вектора
};
Vector  operator*(double d, const Vector &vec); // операция умножения действительного на вектор
ostream& operator<<(ostream& stream, const Vector &vec); // вывод в поток
istream& operator>>(istream& stream,       Vector &vec); // ввод из потока
