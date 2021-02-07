#include "snake.h"

Snake::Snake(Wall& tmpwall, Food& tmpfood):wall(tmpwall), food(tmpfood)
{
	//pHead = NULL;
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
	/*Point* pCur = pHead;
	while (pHead != NULL)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}*/
	while (lSnake.empty() != true)
	{
		//将数组中字符设为" "
		pair<int, int> p = lSnake.front();
		lSnake.pop_front();
	}
}

//添加蛇节点
void Snake::addPoint(int x, int y)
{
	//创建新节点
	//Point* newP = new Point;
	//if (newP == NULL)
	//{
	//	return;
	//}

	////新节点赋值
	//newP->x = x;
	//newP->y = y;
	//newP->next = NULL;

	//if (pHead != NULL)
	//{
	//	//设置当前头节点为身子
	//	wall.setWall(pHead->x, pHead->y, '=');
	//}

	////新的节点添加至链表头部
	//newP->next = pHead;
	//pHead = newP;
	//wall.setWall(pHead->x, pHead->y, '@');

	pair<int, int> p;
	p.first = x;
	p.second = y;
	if (lSnake.empty() != true)
	{
		p = lSnake.front();
		wall.setWall(p.first, p.second, '=');
	}

	lSnake.push_front(make_pair(x,y));
	p = lSnake.front();
	wall.setWall(p.first, p.second, '@');
}

//移动蛇  成功移动与失败移动
bool Snake::move(char key)
{
	/*int x = pHead->x;
	int y = pHead->y;*/

	pair<int, int> p = lSnake.front();
	int x = p.first;
	int y = p.second;

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

	//判断身体是否吃掉尾巴
	//Point* pre = pHead;
	//Point* cur = pHead->next;
	////找到尾节点
	//while (cur->next != NULL)
	//{
	//	pre = pre->next;
	//	cur = pre->next;
	//}

	pair<int, int> cur = lSnake.back(); //蛇尾
	if (cur.first == x && cur.second == y)
	{
		rool = true;
	}
	//if (cur->x == x && cur->y == y)
	//{
	//	rool = true; //rool表示是否是循环状态
	//}
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
	//吃到食物
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
		//未吃到食物
		else
		{
			//正常移动
			addPoint(x, y);
			delPoint();
		}
		
	}
	return true;
}

//删除尾节点
void Snake::delPoint()
{
	pair<int, int> p = lSnake.back();
	wall.setWall(p.first, p.second, ' ');
	lSnake.pop_back();

	//两个节点以上删除
	//if (pHead == NULL || pHead->next == NULL)
	//{
	//	return;
	//}

	////用两个临时节点，一个是前一个节点pre，一个是当前节点cur
	//Point* pre = pHead;
	//Point* cur = pHead->next;

	//while (cur->next != NULL)
	//{
	//	pre = pre->next;
	//	cur = pre->next;
	//}

	////尾节点修改内容
	//wall.setWall(cur->x, cur->y, ' ');
	//delete cur;
	//cur = NULL;
	//pre->next = NULL;
}

Snake::~Snake(){}