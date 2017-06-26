#pragma once
#include "Window.h"

#pragma comment(lib,"SDL2_gfx.lib")

#include <SDL2_gfxPrimitives.h>

//���ڳߴ�
#define Win_L 461
#define Win_H 731

//path
#define Font_kaiti "data/Font/simkai.ttf"
#define Save_score "data/Save/score.txt"

void mainloop(Window *win);

void saveHiScore(int score, const std::string & str);
int readHiScore(const std::string & str);

int Myrand(int max, int min = 0);
