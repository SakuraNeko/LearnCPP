// VisualPet.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class pet {
	string name;
	int age;
	int thirst;//口渴度
public:
	void init(string na, int a) { name = na; age = a; thirst = 5; }
	void increaseage()
	{
		age++;
	}
	int getage()const { return age; }
	void show()const { cout << "name:" << name << "age:" << age; }
	void drink() { thirst++; }
	int getthirst()const { return thirst; }
};
class dog : public pet{
	string color;
public:
	void init(string na, int a, string c)
	{
		pet::init(na, a);
		color = c;
	}
	void show()const
	{
		pet::show();
		cout << "color" << color << endl;
	}
};
int main()
{
	dog friendlydog;
	cout << "你收到了友谊的小狗" << endl << "给小狗取个名字吧？" << endl;
	cin >> friendlydog.name;
	cout << "小狗的名字就叫" << friendlydog << "了" << endl;

	bool ret = friendlydog.run();//开始饲养宠物

	
	friendlydog.init("peny", 5, "yellow");
	friendlydog.show;
	friendlydog.increaseage();
	cout << "age" << friendlydog.getage << endl;

	if (ret == ture)
		cout << "友谊的小狗死了" << endl;
	system("pause");
    return 0;
}

