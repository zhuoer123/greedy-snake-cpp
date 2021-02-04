#ifndef _SNAKE_HEAD
#define _SNAKE_HEAD
#include "wall.h"
#include<iostream>
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
	Snake(Wall& tmpwall);

	~Snake();

	void InitSnake();

	//销毁蛇
	void destorySnake();

	//添加蛇节点
	void addPoint(int x, int y);

private:
	//蛇头结点
	Point* pHead;
	Wall& wall;
};

#endif // !_SNAKE_HEAD


