#include "snake.h"
#include "wall.h"

Snake::Snake(Wall& tmpwall):wall(tmpwall)
{
	pHead = NULL;
}

void Snake::InitSnake()
{
	//����ԭ���Ľڵ�
	destorySnake();

	//��ʼ����
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

//������
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

//����߽ڵ�
void Snake::addPoint(int x, int y)
{
	//�����½ڵ�
	Point* newP = new Point;
	if (newP == NULL)
	{
		return;
	}

	//�½ڵ㸳ֵ
	newP->x = x;
	newP->y = y;
	newP->next = NULL;

	if (pHead != NULL)
	{
		//���õ�ǰͷ�ڵ�Ϊ����
		wall.setWall(pHead->x, pHead->y, '=');
	}

	//�µĽڵ����������ͷ��
	newP->next = pHead;
	pHead = newP;
	wall.setWall(pHead->x, pHead->y, '@');
}

Snake::~Snake(){}