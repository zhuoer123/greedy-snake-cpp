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

	char key; //�߷���

	int foodX;
	int foodY; //ʳ������

	int num; //�߳���

	//�߽ڵ�
	int snakeX[600];
	int snakeY[600];

	//������Ϸ
	void saveInfo();

	//��ȡ��Ϸ
	void readInfo();
};
#endif