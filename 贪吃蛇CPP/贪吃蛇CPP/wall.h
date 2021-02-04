#ifndef _WALL_HEAD
#define _WALL_HEAD
#include<iostream>
using namespace std;



class Wall
{
public:
	enum
	{
		ROW = 26,
		COL = 26
	};

	Wall();

	void InitWall();

	void draw();  //将数组画到控制台中

	void setWall(int x, int y, char key); //根据索引设置二维数组中的元素

	char getWall(int x, int y); //根据索引获取二维数组中的元素


	~Wall();

private:
	char gameArray[ROW][COL];
};


#endif