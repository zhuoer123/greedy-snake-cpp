#ifndef _SNAKE_HEAD
#define _CRT_SECURE_NO_WARNINGS
#define _SNAKE_HEAD
#include "wall.h"
#include "food.h"
#include "infoFile.h"
#include<iostream>
//#include<list>
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

	//������
	void destorySnake();

	//����߽ڵ�
	void addPoint(int x, int y);

	//�ƶ���
	bool move(char key);

	//ɾ��β�ڵ�
	void delPoint();

	//��ȡ�ߵ��ƶ�ʱ��
	int getSleepTime();

	//��ȡ�ߵĳ���
	int countList();

	//��ȡ����
	int getScore();

	//����
	void saveGame(char key);

	//��ȡ
	void readGame(char * key);

private:
	//��ͷ���
	Point* pHead;
	//list<pair<int, int>> lSnake;
	Wall& wall;
	Food& food;
	bool rool = false;
};

#endif // !_SNAKE_HEAD


