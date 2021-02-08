#include<iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;

//����ƶ�
void gotoxy3(HANDLE houtMain, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(houtMain, pos);
}
HANDLE houtMain = GetStdHandle(STD_OUTPUT_HANDLE); //������ʾ���������

int pauseScreen()
{
	int ret = -1;
	while (true)
	{
		system("cls");
		cout << "1.������Ϸ" << endl;
		cout << "2.������Ϸ" << endl;
		cout << "3.��ȡ��Ϸ�浵" << endl;
		cout << "0.�˳���Ϸ" << endl;
		cout << "�����������" << endl;

		cin >> ret;
		if (ret == 0 || ret == 1 || ret == 2 || ret == 3)
		{
			return ret;
		}

		cin.clear(); //���ô�������
		cin.sync();  //��ջ�����
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.InitWall();	
	wall.draw();
	
	Food food(wall);	
	food.setFood();

	Snake snake(wall, food);
	snake.InitSnake();

	gotoxy3(houtMain, 0, wall.ROW);
	cout << "�÷֣�" << snake.getScore() << endl;

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
					/*system("cls");
					wall.draw();*/
					gotoxy3(houtMain, 0, wall.ROW);
					cout << "�÷֣�" << snake.getScore() << endl;
					Sleep(snake.getSleepTime());  //˯��
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
				case 1: //����
					system("cls");
					wall.draw();
					cout << "�÷֣�" << snake.getScore() << endl;
					key = preKey;
					break;
				case 2: //����
					snake.saveGame(preKey);
					system("cls");
					cout << "�浵��ɣ�" << endl;
					system("pause");
					break;
				case 3: //��ȡ
					snake.readGame(&key);
					preKey = key;
					system("cls");
					wall.draw();
					cout << "�÷֣�" << snake.getScore() << endl;
					break;
				case 0: //�˳�
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
		} while (!_kbhit()); //��û�м�������ʱ����0
		
	}


	system("pause");
	return 0;
}