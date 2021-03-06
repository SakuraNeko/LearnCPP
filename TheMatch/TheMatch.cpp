// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <graphics.h>
#include <conio.h>
#include <vector>

#define WIDTH 800//显示窗口
#define HEIGHT 600//显示窗口

using namespace std;
#define DISTANCE 70
#define MOVEMULTIPLE (WIDTH-100)/DISTANCE		//对象移动距离，在图像上移动对应的倍数距离
IMAGE wugui, tuzi, clear;
class runner {
public:
	virtual bool toDistination(int s) = 0;

	virtual int getdistance()const = 0;
	virtual string classname() = 0;
	virtual void prepare(int s) = 0;
	virtual bool fastSpeed() { return false; }		//行走方式
	virtual bool slide() { return false; }
	virtual bool slowSpeed() { return false; }
	virtual bool bigStep() { return false; }
	virtual bool sleep() { return false; }
	virtual bool bigSlide() { return false; }
	virtual bool smallSlide() { return false; }
	virtual bool smallStep() { return false; }
	int time;
	int position;
	int gettime()const
	{
		return time;
	}
	int getposition()
	{
		return position;
	}
protected:
	int distance;
};

class tortoise :public runner {
private:
	const int FASTSPEED;//快速移动
	const int SLIDE;//滑倒
	const int SLOWSPEED;//慢速移动
public:
	virtual string classname()
	{
		return "wugui";
	}
	virtual bool toDistination(int s);
	tortoise(int fs, int s, int ss);
	virtual	bool fastSpeed();
	virtual	bool slide();
	virtual	bool slowSpeed();
	virtual int getdistance()const
	{
		return distance;
	}
	virtual void prepare(int s)
	{
		distance = s;
		time = 0;
		putimage((DISTANCE - getdistance()) * MOVEMULTIPLE, getposition(), &wugui);
	}
};

bool tortoise::toDistination(int s)			//MOVEMULTIPLE：对象移动距离，在图像上移动对应的倍数距离
{
	putimage((DISTANCE - getdistance()) * MOVEMULTIPLE, getposition(), &clear);
	distance -= s;
	if (distance > DISTANCE)
		distance = DISTANCE;
	if (distance < 0)
		distance = 0;
	putimage((DISTANCE - getdistance()) * MOVEMULTIPLE, getposition(), &wugui);
	time++;
	return distance <= 0;
}
tortoise::tortoise(int fs, int s, int ss) :FASTSPEED(fs), SLIDE(s), SLOWSPEED(ss)
{   }

bool tortoise::fastSpeed()
{
	return tortoise::toDistination(FASTSPEED);
}
bool tortoise::slide()
{
	return toDistination(SLIDE);
}
bool tortoise::slowSpeed()
{
	return toDistination(SLOWSPEED);
}

class rabbit :public runner {
private:
	const int BIGSTEP;//大步移动
	const int SLEEP;//睡觉
	const int BIGSLIDE;//慢速移动
	const int SMALLSLIDE;//小步滑倒
	const int SMALLSTEP;//小步前进 					
public:
	rabbit(int bst, int s, int bsl, int ssl, int sst);
	virtual bool toDistination(int s);
	bool bigStep();
	bool sleep();
	bool bigSlide();
	bool smallSlide();
	bool smallStep();
	virtual string classname()
	{
		return "tuzi";
	}
	virtual int getdistance()const
	{
		return distance;
	}
	virtual void prepare(int s)
	{
		distance = s;
		time = 0;
		putimage((DISTANCE - getdistance()) * MOVEMULTIPLE, getposition(), &tuzi);
	}
};

rabbit::rabbit(int bst, int s, int bsl, int ssl, int sst) :
	BIGSTEP(bst), SLEEP(s), BIGSLIDE(bsl), SMALLSLIDE(ssl), SMALLSTEP(sst)
{   }
bool rabbit::toDistination(int s)
{
	putimage((DISTANCE - getdistance()) * MOVEMULTIPLE, getposition(), &clear);
	distance -= s;
	if (distance > DISTANCE)
		distance = DISTANCE;
	if (distance < 0)
		distance = 0;
	putimage((DISTANCE - getdistance()) * MOVEMULTIPLE, getposition(), &tuzi);
	time++;

	return distance <= 0;
}
bool rabbit::bigStep()
{
	return toDistination(BIGSTEP);
}
bool rabbit::sleep()
{
	return toDistination(SLEEP);
}
bool rabbit::bigSlide()
{
	return toDistination(BIGSLIDE);
}
bool rabbit::smallSlide()
{
	return toDistination(SMALLSLIDE);
}
bool rabbit::smallStep()
{
	return toDistination(SMALLSTEP);
}

class match {
	vector<runner*> playerlist;
public:
	void add(runner *p);
	void start();
	int stop();
	int nextRound();
	int round;
	void show();
};

void match::add(runner * p)
{
	p->position = 100 * playerlist.size();
	playerlist.push_back(p);

}

void match::start()
{
	for (size_t i = 0; i<playerlist.size(); i++)
		playerlist[i]->prepare(DISTANCE);

	srand(int(::time(0)));
	round = 0;

}

int match::stop()
{
	for (size_t i = 0; i < playerlist.size(); i++)
	{
		if (playerlist[i]->getdistance() <= 0)
			return 1;
	}
	return 0;
}

int match::nextRound()
{
	round++;
	int n;
	for (size_t i = 0; i < playerlist.size(); i++)
	{
		n = rand() % 10;
		cout << i + 1 << "号选手：";
		if (playerlist[i]->classname() == "wugui")
		{
			switch (n)
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:cout << "乌龟快速跑动" << endl; playerlist[i]->fastSpeed(); break;
			case 5:
			case 6:cout << "乌龟滑倒" << endl; playerlist[i]->slide(); break;
			case 7:
			case 8:
			case 9:cout << "乌龟慢速跑动" << endl; playerlist[i]->slowSpeed(); break;
			}
		}
		else if (playerlist[i]->classname() == "tuzi")
		{
			switch (n)
			{
			case 0:cout << "兔子大步滑倒" << endl; playerlist[i]->bigSlide(); break;
			case 1:
			case 2:cout << "兔子睡觉，原地踏步" << endl; playerlist[i]->sleep(); break;
			case 3:
			case 4:cout << "兔子大步跳跃" << endl; playerlist[i]->bigStep(); break;
			case 5:
			case 6:
			case 7:cout << "兔子小步跳跃" << endl; playerlist[i]->smallStep(); break;
			case 8:
			case 9:cout << "兔子小步滑倒" << endl; playerlist[i]->smallSlide(); break;
			}
		}
	}
	return 1;
}

void match::show()
{
	for (size_t i = 0; i < playerlist.size(); i++)
		cout << "选手" << i + 1 << "的剩余步数为 " << playerlist[i]->getdistance() << endl;
}

int main(void)
{
	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	setbkcolor(BLACK);
	loadimage(&wugui, _T("Assets/wugui.jpg"), 100, 100, true);
	loadimage(&tuzi, _T("Assets/tuzi.jpg"), 100, 100, true);
	loadimage(&clear, _T("Assets/bk.bmp"), 100, 100);

	rabbit r(9, 0, -12, -2, 1);
	tortoise t(3, -6, 1);
	rabbit r1(3, 0, -2, 1, 1);
	tortoise t1(1, 0, 1);
	match game;

	game.add(&t);
	game.add(&r);
	game.add(&r1);
	game.add(&t1);

	cout << "按回车键开始龟兔赛跑,跑道总长度" << DISTANCE << "米" << endl;
	game.start();
	cin.get();

	do {
		cout << "第" << game.round + 1 << "回合" << endl;
		game.nextRound();
		game.show();
		cout << "-----------------------------------\n";
		Sleep(300);
	} while (!game.stop());

	system("pause");
	return 0;
}