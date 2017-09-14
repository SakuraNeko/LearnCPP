// JustTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 23;
	int b;
	cin >> b;
	int c = a + b;
	cout << c << endl;
	c = a*b;
	cout << c << endl;
	for (size_t i = 0; i < 100; i++)
	{
		c += b;
	}
	cout << c << endl;
	return 0;
}

