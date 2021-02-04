#ifndef _SNAKE_HEAD
#define _SNAKE_HEAD
#include "wall.h"
#include<iostream>
using namespace std;


struct Point
{
	//������
	int x;
	int y;

	//ָ����
	Point* next;
};


class Snake
{
public:
	Snake(Wall& tmpwall);

	~Snake();

	void InitSnake();

	//������
	void destorySnake();

	//����߽ڵ�
	void addPoint(int x, int y);

private:
	//��ͷ���
	Point* pHead;
	Wall& wall;
};

#endif // !_SNAKE_HEAD


