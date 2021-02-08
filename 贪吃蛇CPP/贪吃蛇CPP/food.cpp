#include "food.h"

//光标移动
void gotoxy2(HANDLE houtFood, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(houtFood, pos);
}
HANDLE houtFood = GetStdHandle(STD_OUTPUT_HANDLE); //定义显示器句柄变量

//初始化列表
Food::Food(Wall& tmpwall):wall(tmpwall)
{
	
}

void Food::setFood()
{
	while (1)
	{
		//食物的随机位置
		foodX = rand() % (wall.COL - 2) + 1;
		foodY = rand() % (wall.ROW - 2) + 1;

		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			gotoxy2(houtFood,foodY * 2, foodX);
			cout << "#";
			break;
		}
	}
}



int Food::getFoodX()
{
	return this->foodX;
}


int Food::getFoodY()
{
	return this->foodY;
}

Food::~Food() {}