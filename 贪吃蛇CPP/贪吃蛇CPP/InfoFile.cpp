#include "infoFile.h"

InfoFile::InfoFile()
{}

//保存游戏
void InfoFile::saveInfo()
{
	ofstream ofs(_FILE_PATH);
	if (!ofs.is_open())
	{
		return;
	}

	ofs << key << endl; //运行方向
	ofs << foodX << "|"; //食物
	ofs << foodY << endl;

	ofs << num << endl; //蛇长度

	for (int i = 0; i < num; i++)
	{
		ofs << snakeX[i] << "|";
		ofs << snakeY[i] << endl;
	}
	ofs.close();
}

//读取游戏
void InfoFile::readInfo()
{
	ifstream ifs(_FILE_PATH);
	if (!ifs.is_open())
	{
		return;
	}
	char buf[256];
	ifs.getline(buf, sizeof(buf));

	//运行方向
	key = buf[0];

	//食物索引
	memset(buf, 0, sizeof(0));
	ifs.getline(buf, sizeof(buf));
	char* str = strtok(buf, "|"); //利用strtok获取分割的字符串
	foodX = atoi(str);
	str = strtok(NULL, "|");
	foodY = atoi(str);

	//蛇长度
	memset(buf, 0, sizeof(0));
	ifs.getline(buf, sizeof(buf));
	num = atoi(buf);

	//蛇节点
	for (int i = 0; i < num; i++)
	{
		memset(buf, 0, sizeof(0));
		ifs.getline(buf, sizeof(buf));
		char* str2 = strtok(buf, "|");
		snakeX[i] = atoi(str2);
		str2 = strtok(NULL, "|");
		snakeY[i] = atoi(str2);
	}
	ifs.close();
}

InfoFile::~InfoFile()
{}

