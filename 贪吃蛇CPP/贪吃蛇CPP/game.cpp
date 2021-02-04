#include<iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.InitWall();	
	
	Food food(wall);	
	food.setFood();

	Snake snake(wall, food);
	snake.InitSnake();

	wall.draw();

	bool isDead = false;
	//上一步按键
	char preKey = NULL;
	while (isDead != true)
	{
		char key = _getch();
		//初始激活不能用左
		if (preKey == NULL && key == 'a')
		{
			continue;
		}
		do
		{
			if (key == 'w' || key == 's' || key == 'a' || key == 'd')
			{
				//判断是否和上一个案件有冲突
				if ((key == 'w' && preKey == 's') || (key == 'a' && preKey == 'd')||
					(key == 's' && preKey == 'w') || (key == 'd' && preKey == 'a'))
				{
					key = preKey;
				}
				else 
				{
					preKey = key;
				}
				if (snake.move(key) == true)
				{
					system("cls");
					wall.draw();
					Sleep(300);
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;
			}
		} while (!_kbhit()); //当没有键盘输入时返回0
		
	}


	system("pause");
	return 0;
}