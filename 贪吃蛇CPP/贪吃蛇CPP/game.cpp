#include<iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;

int pauseScreen()
{
	int ret = -1;
	while (true)
	{
		system("cls");
		cout << "1.继续游戏" << endl;
		cout << "2.保存游戏" << endl;
		cout << "3.读取游戏存档" << endl;
		cout << "0.退出游戏" << endl;
		cout << "请输入操作：" << endl;

		cin >> ret;
		if (ret == 0 || ret == 1 || ret == 2 || ret == 3)
		{
			return ret;
		}

		cin.clear(); //重置错误输入
		cin.sync();  //清空缓冲区
	}
}

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
	
	cout << "得分：" << snake.getScore() << endl;

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
					cout << "得分：" << snake.getScore() << endl;
					Sleep(snake.getSleepTime());  //睡眠
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else if(key == ' ')
			{
				int userSelect = pauseScreen();
				switch (userSelect)
				{
				case 1: //继续
					system("cls");
					wall.draw();
					cout << "得分：" << snake.getScore() << endl;
					key = preKey;
					break;
				case 2: //保存
					snake.saveGame(preKey);
					system("cls");
					cout << "存档完成！" << endl;
					system("pause");
					break;
				case 3: //读取
					snake.readGame(&key);
					preKey = key;
					system("cls");
					wall.draw();
					cout << "得分：" << snake.getScore() << endl;
					break;
				case 0: //退出
					exit(0);
					break;
				default:
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