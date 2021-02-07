#include "infoFile.h"

InfoFile::InfoFile()
{}

//������Ϸ
void InfoFile::saveInfo()
{
	ofstream ofs(_FILE_PATH);
	if (!ofs.is_open())
	{
		return;
	}

	ofs << key << endl; //���з���
	ofs << foodX << "|"; //ʳ��
	ofs << foodY << endl;

	ofs << num << endl; //�߳���

	for (int i = 0; i < num; i++)
	{
		ofs << snakeX[i] << "|";
		ofs << snakeY[i] << endl;
	}
	ofs.close();
}

//��ȡ��Ϸ
void InfoFile::readInfo()
{
	ifstream ifs(_FILE_PATH);
	if (!ifs.is_open())
	{
		return;
	}
	char buf[256];
	ifs.getline(buf, sizeof(buf));

	//���з���
	key = buf[0];

	//ʳ������
	memset(buf, 0, sizeof(0));
	ifs.getline(buf, sizeof(buf));
	char* str = strtok(buf, "|"); //����strtok��ȡ�ָ���ַ���
	foodX = atoi(str);
	str = strtok(NULL, "|");
	foodY = atoi(str);

	//�߳���
	memset(buf, 0, sizeof(0));
	ifs.getline(buf, sizeof(buf));
	num = atoi(buf);

	//�߽ڵ�
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

