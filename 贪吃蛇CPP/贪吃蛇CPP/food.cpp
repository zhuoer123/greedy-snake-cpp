#include "food.h"

//����ƶ�
void gotoxy2(HANDLE houtFood, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(houtFood, pos);
}
HANDLE houtFood = GetStdHandle(STD_OUTPUT_HANDLE); //������ʾ���������

//��ʼ���б�
Food::Food(Wall& tmpwall):wall(tmpwall)
{
	
}

void Food::setFood()
{
	while (1)
	{
		//ʳ������λ��
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