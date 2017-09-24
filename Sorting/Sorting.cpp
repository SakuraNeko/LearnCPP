// Sorting.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void output(int arr[], int n);
void Sorting(int arr[], int n);

inline void Sorting(int& a,int& b)
{
	int temp = a; a = b; b = temp;
}

int main()
{
	int a[10];
	for (size_t i = 0; i < 10; i++)
	{
		cin >> a[i];
		cin >> ;
	}
	output(a,10);
	Sorting(a,10);
	output(a,10);
	return 0;
}