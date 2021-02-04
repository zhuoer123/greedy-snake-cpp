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
	//��һ������
	char preKey = NULL;
	while (isDead != true)
	{
		char key = _getch();
		//��ʼ���������
		if (preKey == NULL && key == 'a')
		{
			continue;
		}
		do
		{
			if (key == 'w' || key == 's' || key == 'a' || key == 'd')
			{
				//�ж��Ƿ����һ�������г�ͻ
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
		} while (!_kbhit()); //��û�м�������ʱ����0
		
	}


	system("pause");
	return 0;
}