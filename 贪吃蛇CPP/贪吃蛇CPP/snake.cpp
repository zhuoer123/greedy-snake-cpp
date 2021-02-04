#include "snake.h"

Snake::Snake(Wall& tmpwall, Food& tmpfood):wall(tmpwall), food(tmpfood)
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

//�ƶ���  �ɹ��ƶ���ʧ���ƶ�
bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;

	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		return true;
	}

	//�ж������Ƿ�Ե�β��
	Point* pre = pHead;
	Point* cur = pHead->next;
	//�ҵ�β�ڵ�
	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = pre->next;
	}
	if (cur->x == x && cur->y == y)
	{
		rool = true; //rool��ʾ�Ƿ���ѭ��״̬
	}
	else
	{
		if (wall.getWall(x, y) == '=' || wall.getWall(x, y) == '*')
		{
			addPoint(x, y);
			delPoint();
			system("cls");
			wall.draw();
			cout << "Game Over!" << endl;
			return false;
		}
	}
	//�Ե�ʳ��
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);
		food.setFood();
	}
	else
	{
		if (rool)
		{
			addPoint(x, y);
			delPoint();
			wall.setWall(x,y,'@');
		}
		//δ�Ե�ʳ��
		else
		{
			//�����ƶ�
			addPoint(x, y);
			delPoint();
		}
		
	}
	return true;
}

//ɾ��β�ڵ�
void Snake::delPoint()
{
	//�����ڵ�����ɾ��
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}

	//��������ʱ�ڵ㣬һ����ǰһ���ڵ�pre��һ���ǵ�ǰ�ڵ�cur
	Point* pre = pHead;
	Point* cur = pHead->next;

	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = pre->next;
	}

	//β�ڵ��޸�����
	wall.setWall(cur->x, cur->y, ' ');
	delete cur;
	cur = NULL;
	pre->next = NULL;
}

Snake::~Snake(){}