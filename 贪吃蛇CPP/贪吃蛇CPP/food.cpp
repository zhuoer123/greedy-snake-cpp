#include "food.h"

//初始化列表
Food::Food(Wall& tmpwall):wall(tmpwall)
{
	while (1)
	{
		//食物的随机位置
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