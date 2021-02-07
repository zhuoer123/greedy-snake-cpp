#ifndef _INFOFILE_HEAD
#define _INFOFILE_HEAD
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

#define _FILE_PATH "./file.txt"

class InfoFile
{
public:
	InfoFile();

	~InfoFile();

	char key; //蛇方向

	int foodX;
	int foodY; //食物索引

	int num; //蛇长度

	//蛇节点
	int snakeX[600];
	int snakeY[600];

	//保存游戏
	void saveInfo();

	//读取游戏
	void readInfo();
};
#endif