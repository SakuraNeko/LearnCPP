// TriangleDandC.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

main()
{
	float a, b, c, S = 0, x = 0;
	cout << "输入三角形三条边的边长:" << endl;
	cin >> a, b, c;

	if (a + b > c && b + c > a && a + c > b)
	{
		x = (a + b + c) / 2.0;
		S = sqrt(x * (x - a) * (x - b) * (x - c));
		cout << "area = " << S << endl;
	}
	else
	cout << "不能构成三角形" << endl; 
}