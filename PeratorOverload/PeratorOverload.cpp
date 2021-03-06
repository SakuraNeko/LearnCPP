// PeratorOverload.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#undef UNICODE

using namespace std;

class myComplex {
private:
	double real;
	double imag;
public:
	myComplex(double r,double i):real(r),imag(i){}
	myComplex operator=(myComplex c);
	myComplex& operator+=(myComplex c);
	myComplex& operator-=(myComplex c);

	friend myComplex operator+(myComplex c1, myComplex c2);
	friend myComplex operator-(myComplex c1, myComplex c2);
	friend bool operator>(myComplex c1, myComplex c2);
	friend bool operator<(myComplex c1, myComplex c2);
	friend ostream& operator<<(ostream os, myComplex c);
	friend istream& operator>>(istream& os, myComplex c);
};

myComplex& myComplex::operator+=(myComplex c)
{
	real += c.real;
	imag += c.imag;
	return *this;
}

myComplex& myComplex::operator-=(myComplex c)
{
	real -= c.real;
	imag -= c.imag;
	return *this;
}

myComplex myComplex::operator=(myComplex c)
{
	if (this == &c)
		return *this;
	real = c.real;
	imag = c.imag;
	return *this;
}

myComplex operator+(myComplex c1,myComplex c2)
{
	return myComplex(c1.real + c2.real, c1.imag + c2.imag);
}

myComplex operator-(myComplex c1, myComplex c2)
{
	return myComplex(c1.real - c2.real, c1.imag - c2.imag);
}

bool operator>(myComplex c1, myComplex c2)
{
	return (c1.real*c1.real + c1.imag*c1.imag) > (c2.real*c2.real + c2.imag*c2.imag);
}

bool operator<(myComplex c1, myComplex c2)
{
	return (c1.real*c1.real + c1.imag*c1.imag) < (c2.real*c2.real + c2.imag*c2.imag);
}

ostream& operator<<(ostream os, myComplex c)
{
	os << c.real << "+" << c.imag << "i  ";
	return os;
}

istream& operator>>(istream& is, myComplex c)
{
	is >> c.real >> c.imag;
	return is;
}

int _tmain(int argc,_TCHAR* argy[])
{
	myComplex c1(20, 44), c2(33, 8);
	myComplex c3 = c1 + c2;
	myComplex c4 = c1 - c2;
	if (c1 > c2)
		cout << "c1>c2";
	else
		cout << "c1<c2";
	c1 += c2;
	c1 -= c2;
	cout << endl;
	system("pause");
    return 0;
}
