#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void saveHiScore(int score,const std::string & str)
{
	FILE *fp;
	fp = fopen(str.c_str(), "w");	//以写的方式打开文件
	if (fp)	//打开成功
	{
		fprintf(fp, "%d", score);	//将最高分数写入文件
		fclose(fp);	//关闭文件
	}
	else
		throw std::runtime_error("Score Write Failed");
}

int readHiScore(const std::string & str)
{
	FILE *fp;
	int score = 0;
	fp = fopen(str.c_str(), "r");	//以读的方式打开文件
	if (fp)	//打开成功
	{
		fscanf(fp, "%d", &score);	//将最高分数从文件中读出
		fclose(fp);	//关闭文件
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
	srand((unsigned)time(NULL));//选取种子文件
	do
	{
		num = (int)rand() % max;
	} while (num < min || num > max);

	return num;
}
