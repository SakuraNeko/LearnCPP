// NameAndPhoneEasyManage.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;
static int n;

struct
{
	char name[10][10];
	int phone_num[10][20];
}people_info;

void info_input()
{
	int i;
	cout << "Please input people number:" << endl;
	cin >> n;
	cout << "please input"<< n <<"people"<<"name & phone number." << endl;
	for (i = 0; i<n; i++)
	{
		cin >> people_info.name[i];
		cin >> people_info.phone_num[i][15];
	}
	cout << "Finish" << endl;
}

void processmth_a(int i)
{
	if (i != 0) 
	{
		cout << i << "	"; 
	}
}

void processmth_b(char i)
{
	int j;
	cout << i;
}

int main()
{
	info_input();
	//vector<int *> v(info.num, info.num+sizeof(info.num)/sizeof(int));
	//for_each
	cout << "for_each:" << endl << "Phone:";
	for_each(*people_info.phone_num, *(people_info.phone_num + n + 1), processmth_a);
	cout << endl;
	cout << "Name:";
	for_each(*people_info.name, *(people_info.name + n + 1), processmth_b);
	int cnum[10][20];
	char cname[10][10];
	//ostream_iterator<int> osint(cout, " ");
	//copy
	copy(*people_info.phone_num, *(people_info.phone_num + n + 1), *cnum);
	cout << endl;
	cout << "Copy:" << endl << "Phone number";
	for_each(*cnum, *(cnum + n + 1), processmth_a);

	copy(*people_info.name, *(people_info.name + n + 1), *cname);
	cout << endl;
	cout << "name:";
	for_each(*cname, *(cname + n + 1), processmth_b);
}

