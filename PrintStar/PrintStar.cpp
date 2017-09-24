// PrintStar.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	void PrintSquare();
	void PrintTriangle();
	void PrintDiamond();
	void PrintVoidDiamond();
	return 0;
}

inline void PrintSquare()
{
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t i = 0; i < 5; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

inline void PrintTriangle()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = n-i; j > 0; j--)
		{
			cout << " ";
		}
		for (size_t k = 0; k < 2*i-1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

inline void PrintDiamond()
{
	for (size_t i = 0; i < 7; i++)
	{

	}
}

inline void PrintVoidDiamond()
{

}