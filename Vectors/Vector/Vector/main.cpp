#include "Rational.h"
#include "Vector.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Vector <int> aI,bI;
	Vector <double> aD, bD;
	Vector <Rational> aR, bR;
	int numI;
	double numD;
	Rational numR;
	int x,m=1;
	do
	{ 
		cout << "�������� �����" << endl;
		cout << "1.Integer" << endl;
		cout << "2.Double" << endl;
		cout << "3.Rational" << endl;
		cout << "4.Exit"<<endl;
		cin >> x;
		if(x==1)
		{
			cout << "������� ������ ������ a" << endl;
			cin >> aI;
			cout << "������� ������ ������ b" << endl;
			cin >> bI;
			cout << "������� ����� k" << endl;
			cin >> numI;
			system("cls");
			cout << "a=("<<aI <<")" <<endl;
			cout <<"b=("<< bI <<")"<< endl;
			cout << "k=" << numI << endl;
			cout <<"a+b=(" <<aI + bI << ")" << endl;
			cout << "a-b=(" << aI - bI << ")" << endl;
			cout << "a*b=(" << aI * bI << ")" << endl;
			cout << "a*k=" << aI*numI << endl;
			cout << "b*k=" << bI*numI << endl;
			system("pause");
			system("cls");
		}
		if(x==2)
		{
			cout << "������� ������ ������ a" << endl;
			cin >> aD;
			cout << "������� ������ ������ b" << endl;
			cin >> bD;
			cout << "������� ����� k" << endl;
			cin >> numD;
			system("cls");
			cout << "a=(" << aD << ")" << endl;
			cout << "b=(" << bD << ")" << endl;
			cout << "k=" << numD << endl;
			cout << "a+b=(" << aD + bD << ")" << endl;
			cout << "a-b=(" << aD - bD << ")" << endl;
			cout << "a*b=(" << aD * bD << ")" << endl;
			cout << "a*k=" << aD*numD << endl;
			cout << "b*k=" << bD*numD <<endl;
			system("pause");
			system("cls");
		}
		if(x==3)
		{
			cout << "������� ������ ������ a " << endl;
			cin >> aR;
			cout << "������� ������ ������ b" << endl;
			cin >> bR;
			cout << "������� ����� k" << endl;
			cin >> numR;
			system("cls");
			cout << "a=(" << aR << ")" << endl;
			cout << "b=(" << bR << ")" << endl;
			cout << "k=" << numR << endl;
			cout << "a+b=(" << aR + bR << ")" << endl;
			cout << "a-b=(" << aR - bR << ")" << endl;
			cout << "a*b=(" << aR * bR << ")" << endl;
			cout << "a*k=" << aR*numR << endl;
			cout << "b*k=" << bR*numR << endl;
			system("pause");
			system("cls");
		}
		if(x==4)
		{
			return;
		}
	}
	while(m==1);
}