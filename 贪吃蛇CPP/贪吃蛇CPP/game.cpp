#include<iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include<ctime>
using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.InitWall();

	Snake snake(wall);
	snake.InitSnake();

	Food food(wall);
	food.setFood();


	wall.draw();

	system("pause");
	return 0;
}