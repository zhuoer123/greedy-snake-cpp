#include "food.h"

//��ʼ���б�
Food::Food(Wall& tmpwall):wall(tmpwall)
{
	while (1)
	{
		//ʳ������λ��
		foodX = rand() % (wall.COL - 2) + 1;
		foodY = rand() % (wall.ROW - 2) + 1;

		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			break;
		}
	}
}

void Food::setFood()
{

}