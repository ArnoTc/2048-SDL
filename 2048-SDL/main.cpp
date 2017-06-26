//===============================
//程序名称：2048-SDL
//版本号：1.0
//制作人：杨新瑞
//
//创建时间：2017-6-18 21:53:39
//完工时间：2017-6-26 21:37:57
//代码量：1156行
//制作周期：3天
//
//===============================

#include "function.h"

int main(int argc, char **argv)
{
	Window *window = new Window;
	window->Init(u8"2048-SDL", Win_L, Win_H);//添加u8以支持中文

	mainloop(window);
	
	window->Quit();
	delete window;
	return 0;
}
