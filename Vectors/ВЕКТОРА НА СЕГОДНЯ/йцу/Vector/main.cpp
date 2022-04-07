// Файл TestVector.cpp ---------------------------------------
#include <clocale>
#include <iomanip>
#include <iostream>
//#include <fstream>
using namespace std; 
//std::ofstream cout("rezult.txt", std::ios::out);

#include "Vector.h"
 

int main()
{
	setlocale(LC_CTYPE, "Russian");
	// задание точности и формата вывода
	cout << setprecision( 2 ) << fixed;

	int vCount = 5;

	Vector v1(vCount, 1.1); // Констуктор инициализатор
	v1.outPut("v1");

	double *d2 = new double[vCount];
	for ( int i = 0; i < vCount; ++i )
		d2[i] = 1 + (i + 1)*0.1;

	// Конструктор инициализатор
	Vector v2(vCount, d2);
	v2.outPut("v2");

	double comp = v2[2];
	cout << "\ncomp = v2[2];  " << comp << " -----------------------------" << endl;

	cout << "\nv3 = v2;" << " --------------------------------------" << endl;
	Vector v3;
	v3 = v2;
	v3.outPut("v3");

	cout << "\nv3[3] = 4.4;" << " --------------------------------------" << endl;
	v3[3] = 4.4;
	v3.outPut("v3");
	v2.outPut("v2");

	const Vector vc(vCount, d2);
	comp = vc[2];
	cout << "\ncomp = vc[2];  " << comp << " -----------------------------" << endl;
	vc.outPut("vc");
	

	cout << "\nv5 =  v1 + v2;" << " --------------------------------------" << endl;
	Vector v5;
	v5 =  v1 + v2;
	v5.outPut("v5");

	cout << "\nv6 = 1.1 * v2;" << " --------------------------------------" << endl;
	Vector v6(vCount);
	v6 = 1.1 * v2;
	v6.outPut("v6");

	double  scal = v1 * v2;
	cout << "\nscal = v1 * v2; : " << scal << " --------------------------------------" << endl;
	/*
		// Запись в поток
	cout << "\nos << v1 << v2 << endl; ------------------" << endl;
	v1.outPut("v1");
	v2.outPut("v2");
	ofstream os; // поток для записи
	os.open("vector.txt"); // файл для записи
	os << v1 << v2 << endl;
	os.close();

	// Чтение из потока
	cout << "\nis >> v3 >> v5; --------------------------" << endl;
	ifstream is; // поток для чтения
	is.open("vector.txt"); // файл для чтения
	is >> v3 >> v5;
	v3.outPut("v3");
	v5.outPut("v5");
	is.close();
	*/
	delete[] d2;

	return 0;
}

