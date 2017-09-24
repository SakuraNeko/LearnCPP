// PrintStar.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void PrintSquare()
{
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t i = 0; i < 5; i++)
			cout << "*";
		cout << endl;
	}
}

void PrintTriangle()
{
	int n,i,j,k;
	cout << "How many lines" << endl;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = n-i; j > 0; j--)
			cout << " ";
		for (size_t k = 0; k < 2*i-1; k++)
			cout << "*";
		cout << endl;
	}
}

void PrintDiamond()
{
	int n, i, j, k;
	for (size_t i = n - 1; i >= 1; i--) 
	{ 
		for (j = n; j >= i; j--)
			cout << " ";
	}
	for (size_t k = 1; k <= 2*i-1; k++) 
		cout << "*";
	cout << endl;
}

void PrintVoidDiamond()
{
	int n , i, j, k, l;
	cout <<"please enter size";
	cin >> n;
	for (i = 1; i<n; i++)
	{
		for (j = 1; j <= n + i - 1; j++)
			if (j == n - i + 1 || j == n + i - 1)
				cout << "*";
			else
				cout << " ";
		cout << endl;
	}
	for (i = 1; i <= 2 * n - 1; i++)
		cout << "*";
	cout << endl;
	for (k = 1; k<n; k++)
	{
		for (l = 1; l <= 2 * n - j - 1; k++)
			if (k == n - (n - j - 1) || k == 2 * n - j - 1)
				cout <<"*";
			else
				cout <<" ";
		cout << endl;
	}
}

int main()
{
	void PrintSquare();
	void PrintTriangle();
	void PrintDiamond();
	void PrintVoidDiamond();
	return 0;
}