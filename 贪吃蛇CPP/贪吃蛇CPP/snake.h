#ifndef _SNAKE_HEAD
#define _SNAKE_HEAD
#include "wall.h"
#include "food.h"
#include<iostream>
#include<list>
using namespace std;


//struct Point
//{
//	//数据域
//	int x;
//	int y;
//
//	//指针域
//	Point* next;
//};


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

private:
	//蛇头结点
	//Point* pHead;
	list<pair<int, int>> lSnake;
	Wall& wall;
	Food& food;
	bool rool = false;
};

#endif // !_SNAKE_HEAD


