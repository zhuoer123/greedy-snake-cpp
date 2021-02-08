#include "snake.h"

//光标移动
void gotoxy(HANDLE hout, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hout, pos);
}
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //定义显示器句柄变量

Snake::Snake(Wall& tmpwall, Food& tmpfood):wall(tmpwall), food(tmpfood)
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
	Point* pcur = pHead;
	while (pHead != NULL)
	{
		pcur = pHead->next;
		delete pHead;
		pHead = pcur;
	}
	//while (lSnake.empty() != true)
	//{
	//	//将数组中字符设为" "
	//	pair<int, int> p = lSnake.front();
	//	lSnake.pop_front();
	//}
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
		gotoxy(hout, pHead->y * 2, pHead->x);
		cout << "=";
	}

	//新的节点添加至链表头部
	newP->next = pHead;
	pHead = newP;
	wall.setWall(pHead->x, pHead->y, '@');
	gotoxy(hout, pHead->y * 2, pHead->x);
	cout << "@";

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

//移动蛇  成功移动与失败移动
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

	//判断身体是否吃掉尾巴
	Point* pre = pHead;
	Point* cur = pHead->next;
	//找到尾节点
	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = pre->next;
	}

	//pair<int, int> cur = lSnake.back(); //蛇尾
	//if (cur.first == x && cur.second == y)
	//{
	//	rool = true;
	//}
	if (cur->x == x && cur->y == y)
	{
		rool = true; //rool表示是否是循环状态
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
			cout << "得分：" << getScore() << endl;
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
			gotoxy(hout, y * 2, x);
			cout << "@";
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
	/*pair<int, int> p = lSnake.back();
	wall.setWall(p.first, p.second, ' ');
	lSnake.pop_back();*/

	//两个节点以上删除
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}

	//用两个临时节点，一个是前一个节点pre，一个是当前节点cur
	Point* pre = pHead;
	Point* cur = pHead->next;

	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = pre->next;
	}

	//尾节点修改内容
	wall.setWall(cur->x, cur->y, ' ');
	gotoxy(hout,cur->y * 2, cur->x);
	cout << ' ';

	delete cur;
	cur = NULL;
	pre->next = NULL;
}

//获取蛇的移动时间，改变游戏速度
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

//获取蛇的长度
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

//获取分数
int Snake::getScore()
{
	int score = 0;
	int size = countList();
	score = (size - 3) * 100;
	return score;
}


//保存
void Snake::saveGame(char key)
{
	InfoFile file;
	//方向
	file.key = key;

	//食物坐标
	file.foodX = food.getFoodX();
	file.foodY = food.getFoodY();
	
	//蛇长度
	file.num = countList();

	//蛇节点
	Point* pCur = pHead;
	for (int i = 0; i < file.num; i++)
	{
		file.snakeX[i] = pCur->x;
		file.snakeY[i] = pCur->y;
		pCur = pCur->next;
	}

	file.saveInfo();
}

//读取
void Snake::readGame(char* key)
{
	wall.InitWall();

	InfoFile file;
	file.readInfo();

	*key = file.key;

	wall.setWall(file.foodX, file.foodY, '#');

	//获取蛇
	if (pHead != NULL)
	{
		destorySnake();
		pHead = NULL;
	}

	//蛇长
	int num = file.num;

	//设置节点
	for (int i = 0; i < num; i++)
	{
		addPoint(file.snakeX[num - 1 - i], file.snakeY[num - 1 - i]);
	}

}



Snake::~Snake(){}