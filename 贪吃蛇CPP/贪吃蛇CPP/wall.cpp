#include "wall.h"

Wall::Wall(){}

void Wall::InitWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
			{
				gameArray[i][j] = '*';
			}
			else
			{
				gameArray[i][j] = ' ';
			}
		}
	}
}

//将数组画到控制台中
void Wall::draw()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << gameArray[i][j] << " ";
		}	

		if (i == 5)
		{
			cout << "  Greedy Snake v1.0" << " ";
		}
		if (i == 6)
		{
			cout << "  Created by Wanpi" << " ";
		}
		if (i == 7)
		{
			cout << "  up   : w" << " ";
		}
		if(i == 8)
		{
			cout << "  down   : s" << " ";
		}
		if (i == 9)
		{
			cout << "  left   : a" << " ";
		}
		if (i == 10)
		{
			cout << "  right   : d" << " ";
		}
		cout << endl;
	}
}

//根据索引设置二维数组中的元素
void Wall::setWall(int x, int y, char key)
{
	gameArray[x][y] = key;
}


//根据索引获取二维数组中的元素
char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}

Wall::~Wall(){}