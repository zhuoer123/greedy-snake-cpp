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

	void draw();  //�����黭������̨��

	void setWall(int x, int y, char key); //�����������ö�ά�����е�Ԫ��

	char getWall(int x, int y); //����������ȡ��ά�����е�Ԫ��


	~Wall();

private:
	char gameArray[ROW][COL];
};


#endif