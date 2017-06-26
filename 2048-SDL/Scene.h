#pragma once
#include "function.h"

class Scene
{
	enum State
	{
		Begin,
		Gaming,
		End
	};

public:
	Scene(Window *win);
	~Scene();

	void enent();
	void update();
	bool isOver();
	void rend();

private:
	void mouseevent();
	void keyevent();

	void Init();
	void newNum(char ch);

	void rend_BeginFace();
	void rend_GameingBackGround();
	void rend_EndFace();
	void rend_Number();

	bool isEnd();

private:
	Window *win;
	SDL_Event events;
	bool isover;

	State state;
	int score;
	int map[4][4];
};

