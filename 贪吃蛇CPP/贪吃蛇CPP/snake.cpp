#include "snake.h"
#include "wall.h"

Snake::Snake(Wall& tmpwall):wall(tmpwall)
{
	pHead = NULL;
}

void Snake::InitSnake()
{
	//销毁原来的节点
	destorySnake();

	//初始化蛇
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

//销毁蛇
void Snake::destorySnake()
{
	Point* pCur = pHead;
	while (pHead != NULL)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

//添加蛇节点
void Snake::addPoint(int x, int y)
{
	//创建新节点
	Point* newP = new Point;
	if (newP == NULL)
	{
		return;
	}

	//新节点赋值
	newP->x = x;
	newP->y = y;
	newP->next = NULL;

	if (pHead != NULL)
	{
		//设置当前头节点为身子
		wall.setWall(pHead->x, pHead->y, '=');
	}

	//新的节点添加至链表头部
	newP->next = pHead;
	pHead = newP;
	wall.setWall(pHead->x, pHead->y, '@');
}

Snake::~Snake(){}