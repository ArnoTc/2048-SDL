#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void saveHiScore(int score,const std::string & str)
{
	FILE *fp;
	fp = fopen(str.c_str(), "w");	//��д�ķ�ʽ���ļ�
	if (fp)	//�򿪳ɹ�
	{
		fprintf(fp, "%d", score);	//����߷���д���ļ�
		fclose(fp);	//�ر��ļ�
	}
	else
		throw std::runtime_error("Score Write Failed");
}

int readHiScore(const std::string & str)
{
	FILE *fp;
	int score = 0;
	fp = fopen(str.c_str(), "r");	//�Զ��ķ�ʽ���ļ�
	if (fp)	//�򿪳ɹ�
	{
		fscanf(fp, "%d", &score);	//����߷������ļ��ж���
		fclose(fp);	//�ر��ļ�
	}
	else
		throw std::runtime_error("Score Read Failed");
	return score;
}

int Myrand(int max,int min)
{
	if (max < min)
		throw std::runtime_error("Myrand max<min");
	if(max==0)
		throw std::runtime_error("Myrand max==0");

	int num;
	srand((unsigned)time(NULL));//ѡȡ�����ļ�
	do
	{
		num = (int)rand() % max;
	} while (num < min || num > max);

	return num;
}
