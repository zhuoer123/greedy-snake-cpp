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
	Point* pcur = pHead;
	while (pHead != NULL)
	{
		pcur = pHead->next;
		delete pHead;
		pHead = pcur;
	}
	//while (lSnake.empty() != true)
	//{
	//	//���������ַ���Ϊ" "
	//	pair<int, int> p = lSnake.front();
	//	lSnake.pop_front();
	//}
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

	/*pair<int, int> p;
	p.first = x;
	p.second = y;
	if (lSnake.empty() != true)
	{
		p = lSnake.front();
		wall.setWall(p.first, p.second, '=');
	}

	lSnake.push_front(make_pair(x,y));
	p = lSnake.front();
	wall.setWall(p.first, p.second, '@');*/
}

//�ƶ���  �ɹ��ƶ���ʧ���ƶ�
bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;

	/*pair<int, int> p = lSnake.front();
	int x = p.first;
	int y = p.second;*/

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

	//pair<int, int> cur = lSnake.back(); //��β
	//if (cur.first == x && cur.second == y)
	//{
	//	rool = true;
	//}
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
			cout << "�÷֣�" << getScore() << endl;
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
	/*pair<int, int> p = lSnake.back();
	wall.setWall(p.first, p.second, ' ');
	lSnake.pop_back();*/

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

//��ȡ�ߵ��ƶ�ʱ�䣬�ı���Ϸ�ٶ�
int Snake::getSleepTime()
{
	int sTime = 0;
	int size = countList();

	if (size < 5)
	{
		sTime = 300;
	}
	else if (size >= 5 && size <= 100)
	{
		sTime = 200;
	}
	else
	{
		sTime = 100;
	}
	return sTime;
}

//��ȡ�ߵĳ���
int Snake::countList()
{
	int size = 0;
	Point* curP = pHead;
	while (curP != NULL)
	{
		size++;
		curP = curP->next;
	}
	return size;
}

//��ȡ����
int Snake::getScore()
{
	int score = 0;
	int size = countList();
	score = (size - 3) * 100;
	return score;
}


//����
void Snake::saveGame(char key)
{
	InfoFile file;
	//����
	file.key = key;

	//ʳ������
	file.foodX = food.getFoodX();
	file.foodY = food.getFoodY();
	
	//�߳���
	file.num = countList();

	//�߽ڵ�
	Point* pCur = pHead;
	for (int i = 0; i < file.num; i++)
	{
		file.snakeX[i] = pCur->x;
		file.snakeY[i] = pCur->y;
		pCur = pCur->next;
	}

	file.saveInfo();
}

//��ȡ
void Snake::readGame(char* key)
{
	wall.InitWall();

	InfoFile file;
	file.readInfo();

	*key = file.key;

	wall.setWall(file.foodX, file.foodY, '#');

	//��ȡ��
	if (pHead != NULL)
	{
		destorySnake();
		pHead = NULL;
	}

	//�߳�
	int num = file.num;

	//���ýڵ�
	for (int i = 0; i < num; i++)
	{
		addPoint(file.snakeX[num - 1 - i], file.snakeY[num - 1 - i]);
	}

}

Snake::~Snake(){}