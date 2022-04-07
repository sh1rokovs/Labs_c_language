// ���� Vector.h ---------------------------------------
#pragma once
#include <fstream> 

class Vector {
public:
	Vector();        // ���������� �� ���������
	explicit Vector(int _count);    // ���������� �������������
	Vector(int _count, double d);   // ���������� �������������
	Vector(int _count, double* ar); // ���������� �������������
	Vector(const Vector &vec);      // ���������� �����������
	~Vector();                      // ����������
	// ����� �� �������
	void outPut(const char* name);
	void outPut(const char* name) const;

	// ���������� ��������
	double& operator[](int index);       // ��� ������ � ������
	const double& operator[](int index) const; // ������ ��� ������ � ����������� ������� � ��������
	
	Vector& operator=(const Vector &vec); // �������� ������������
	Vector  operator+(const Vector &vec); // �������� ������������
	double  operator*(const Vector &vec); // �������� ���������� ������������
	friend Vector  operator*(double d, const Vector &vec); // �������� ��������� ��������������� �� ������
    friend ostream& operator<<(ostream& stream, const Vector &vec); // ����� � �����
    friend istream& operator>>(istream& stream,       Vector &vec); // ���� �� ������
 
private:
	double *mas; // ������ ��������� ������� 
	int size;    // ���������� ��������� �������
};
Vector  operator*(double d, const Vector &vec); // �������� ��������� ��������������� �� ������
ostream& operator<<(ostream& stream, const Vector &vec); // ����� � �����
istream& operator>>(istream& stream,       Vector &vec); // ���� �� ������
