//===============================
//�������ƣ�2048-SDL
//�汾�ţ�1.0
//�����ˣ�������
//
//����ʱ�䣺2017-6-18 21:53:39
//�깤ʱ�䣺2017-6-26 21:37:57
//��������1156��
//�������ڣ�3��
//
//===============================

#include "function.h"

int main(int argc, char **argv)
{
	Window *window = new Window;
	window->Init(u8"2048-SDL", Win_L, Win_H);//���u8��֧������

	mainloop(window);
	
	window->Quit();
	delete window;
	return 0;
}
