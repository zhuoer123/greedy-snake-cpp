#ifndef _SNAKE_HEAD
#define _CRT_SECURE_NO_WARNINGS
#define _SNAKE_HEAD
#include "wall.h"
#include "food.h"
#include "infoFile.h"
#include<conio.h>
#include<windows.h>
#include<iostream>
//#include<list>
using namespace std;


struct Point
{
	//数据域
	int x;
	int y;

	//指针域
	Point* next;
};


class Snake
{
public:
	enum
	{
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
	};

	Snake(Wall& tmpwall, Food& tmpfood);

	~Snake();

	void InitSnake();

	//销毁蛇
	void destorySnake();

	//添加蛇节点
	void addPoint(int x, int y);

	//移动蛇
	bool move(char key);

	//删除尾节点
	void delPoint();

	//获取蛇的移动时间
	int getSleepTime();

	//获取蛇的长度
	int countList();

	//获取分数
	int getScore();

	//保存
	void saveGame(char key);

	//读取
	void readGame(char * key);

private:
	//蛇头结点
	Point* pHead;
	//list<pair<int, int>> lSnake;
	Wall& wall;
	Food& food;
	bool rool = false;
};

#endif // !_SNAKE_HEAD


