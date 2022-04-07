#pragma once
#include <iostream>
using namespace std;
template <class T>
class Vector 
{
private:
	T* mas;
	int size;
public:
	Vector <T>(int size = 3);
	Vector  <T>(const Vector <T> &v);
	~Vector<T>();	
	friend istream & operator >>(istream & os, Vector <T> &v)
	{
	
		for (int i = 0; i < v.size; i++)
			os >> v.mas[i];
		return os;
	}
	friend ostream & operator<<(ostream & os, const Vector<T> & v) 
	{
			for (int i = 0; i <v.size; i++)
				os << v.mas[i] << " ";
			return os;
	}
	void operator+=(const Vector <T> &v);
	void operator-=(const Vector <T> &v);
	void operator*=(const T a);
	Vector operator+(const Vector <T> &v);
	Vector operator-(const Vector <T> &v);
	Vector operator*(const T a);
	T operator*(const Vector <T> &v);
	void operator= (const Vector <T> &v);
	T operator [](int n);
	void SetOnPosition(int index, T b);
	T GetFromPosition(int index);
	void Resize(int newSize);
};
template <class T> Vector <T> ::Vector(int _size)
{
	size = _size;
	mas = new T[size];
	for (int i = 0; i<size; i++)
		mas[i] = 0;
}
template <class T> Vector <T>::Vector(const Vector <T> &v)
{
	size = v.size;
	mas = new T[size];
	for (int i = 0; i<size; i++)
		mas[i] = v.mas[i];
}
template <class T> Vector<T>::~Vector()
{
	delete[] mas;
}
template <class T> void Vector <T>::operator+=(const Vector <T> &v)
{
	for (int i = 0; i<size; i++)
		mas[i] += v.mas[i];
}
template <class T> void Vector <T> ::operator-=(const Vector<T> &v)
{
	for (int i = 0; i<size; i++)
		mas[i] -= v.mas[i];
}
template <class T> void Vector <T> ::operator*=(const T a)
{ 
	for (int i = 0; i < size; i++)
		mas[i] *= a;
}
template <class T> Vector <T> Vector <T> :: operator+(const Vector <T> &v)
{
	Vector <T> c;
	for (int i = 0; i<size; i++)
		c.mas[i] = mas[i] + v.mas[i];
	return c;
}
template <class T> Vector <T> Vector <T> ::operator-(const Vector <T> &v)
{
	Vector <T> c;
	for (int i = 0; i<size; i++)
		c.mas[i] = mas[i] - v.mas[i];
	return c;
}
template <class T> Vector <T> Vector <T> ::operator*(const T a)
{
	Vector <T> c(size);
	for (int i = 0; i < size; i++)
		c.mas[i] = mas[i] * a;
	return c;
}
template <class T> T  Vector <T> ::operator*(const Vector <T> &v)
{
	T res = 0.0; 
	for (int i = 0; i < size; i++)
		res += mas[i] * v.mas[i];
	return res;
}
template <class T> void Vector <T>::operator=(const Vector <T> &v)
{
	if (size != v.size)
	{
		delete[] mas;
		mas = new T [v.size];
	}
	for (int i = 0; i<v.size; i++)
		this->mas[i] = v.mas[i];
	size = v.size;
}
template <class T> T Vector <T>::operator [](int n)
{
	return mas[n];
}
template <class T> void Vector<T>::SetOnPosition(int index, T b)
{
	mas[index] = b;
}
template <class T> T Vector <T>::GetFromPosition(int index)
{
	return mas[index];
}
template <class T> void Vector <T>::Resize(int newSize)
{
	T* masCopy = new T[size];
	for (int i = 0; i < size; i++)
		masCopy[i] = mas[i];
	delete[] mas;
	mas = new T[newSize];
	if (size < newSize)
	{
		for (int i = 0; i < size; i++)
			mas[i] = masCopy[i];
		for (int i = size; i < newSize; i++)
			mas[i] = 0;
	}
	else
		for (int i = 0; i < newSize; i++)
		{
			mas[i] = masCopy[i];
		}
	size = newSize;
	delete[] masCopy;
}