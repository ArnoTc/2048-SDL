#include "Scene.h"

Scene::Scene(Window *win) :win(win)
{
	state = Begin;

	isover = false;
}


Scene::~Scene()
{
}

void Scene::enent()
{
	while (SDL_PollEvent(&events))
	{
		//If user closes the window
		if (events.type == SDL_QUIT)
		{
			isover = true;
			return;
		}

		if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			mouseevent();
		}

		if (events.type == SDL_KEYDOWN)
		{
			keyevent();
		}
	}
}

void Scene::update()
{
	if (state == Gaming)
	{
		//还原负值
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				if (map[x][y] < 0)
					map[x][y] *= -1;
		if (isEnd())
		{
			state = End;
		}
	}
}

bool Scene::isOver()
{
	return isover;
}

void Scene::rend()
{
	win->Clear();

	switch (state)
	{
	case Scene::Begin:
		rend_BeginFace();
		break;
	case Scene::Gaming:
		rend_GameingBackGround();
		rend_Number();
		break;
	case Scene::End:
		rend_EndFace();
		break;
	default:
		break;
	}
	win->Present();
}

void Scene::mouseevent()
{
	int x, y;
	x = events.motion.x;
	y = events.motion.y;

	if (events.button.button == SDL_BUTTON_LEFT)
	{
		if (state == Begin)
		{
			Init();
			return;
		}
		else if (state == Gaming)
		{
			if ((x - 230)*(x - 230) + (y - 650)*(y - 650) <= 2500)
			{
				if (score > readHiScore("data/Save/score.txt"))
					saveHiScore(score, "data/Save/score.txt");
				Init();
			}
		}
		else
		{
			if (((x - 130)*(x - 130) + (y - 600)*(y - 600) <= 2500))
			{
				Init();
				return;
			}
			if (((x - 320)*(x - 320) + (y - 600)*(y - 600) <= 2500))
			{
				isover = true;
				return;
			}
		}
	}

	if (events.button.button == SDL_BUTTON_RIGHT)
	{
		if (state == Begin)
		{
			Init();
			return;
		}
	}
}

void Scene::keyevent()
{
	if (state == Begin || state == End)
	{
		if (events.key.keysym.sym == SDLK_ESCAPE)
			isover = true;
		else
		{
			state = Gaming;
			Init();
		}
	}
	else
	{
		int t = 0;
		switch (events.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (score > readHiScore("data/Save/score.txt"))
				saveHiScore(score, "data/Save/score.txt");
			Init();
			break;
		case SDLK_ESCAPE:
			isover = true;
			break;
		case SDLK_UP:
		case SDLK_w:
			for (int y = 0; y < 4; y++)
				for (int x = 0; x < 4; x++)
					if (map[x][y] > 0)
					{
						for (int i = x - 1; i >= 0; i--)
							if (map[i][y] != 0)
							{
								if (map[i][y] == map[x][y])
								{
									map[i][y] = 0;
									score += map[x][y] * 2;
									map[x][y] *= -2;
									t++;
									win->mMusic->ding->play();
								}
								break;
							}
						for (int i = 0; i < x; i++)
							if (map[i][y] == 0)
							{
								map[i][y] = map[x][y];
								map[x][y] = 0;
								t++;
								break;
							}
					}
			if (t > 0)
				newNum('w');
			break;
		case SDLK_DOWN:
		case SDLK_s:
			for (int y = 0; y < 4; y++)
				for (int x = 3; x >= 0; x--)
					if (map[x][y] > 0)
					{
						for (int i = x + 1; i <= 3; i++)
							if (map[i][y] != 0)
							{
								if (map[i][y] == map[x][y])
								{
									map[i][y] = 0;
									score += map[x][y] * 2;
									map[x][y] *= -2;
									t++;
									win->mMusic->ding->play();
								}
								break;
							}
						for (int i = 3; i > x; i--)
							if (map[i][y] == 0)
							{
								map[i][y] = map[x][y];
								map[x][y] = 0;
								t++;
								break;
							}
					}
						if (t > 0)
							newNum('s');
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			for (int x = 0; x < 4; x++)
				for (int y = 3; y >= 0; y--)
					if (map[x][y] > 0)
					{
						for (int i = y + 1; i <= 3; i++)
							if (map[x][i] != 0)
							{
								if (map[x][i] == map[x][y])
								{
									map[x][i] = 0;
									score += map[x][y] * 2;
									map[x][y] *= -2;
									t++;
									win->mMusic->ding->play();
								}
								break;
							}
						for (int i = 3; i > y; i--)
							if (map[x][i] == 0)
							{
								map[x][i] = map[x][y];
								map[x][y] = 0;
								t++;
								break;
							}
					}
						if (t > 0)
							newNum('d');
			break;
		case SDLK_LEFT:
		case SDLK_a:
			for (int x = 0; x < 4; x++)
				for (int y = 0; y < 4; y++)
					if (map[x][y] > 0)
					{
						for (int i = y - 1; i >= 0; i--)
							if (map[x][i] != 0)
							{
								if (map[x][i] == map[x][y])
								{
									map[x][i] = 0;
									score += map[x][y] * 2;
									map[x][y] *= -2;
									t++;
									win->mMusic->ding->play();
								}
								break;
							}
						for (int i = 0; i < y; i++)
							if (map[x][i] == 0)
							{
								map[x][i] = map[x][y];
								map[x][y] = 0;
								t++;
								break;
							}
					}
						if (t > 0)
							newNum('a');
			break;
		default:
			break;
		}
	}
}

void Scene::Init()
{
	int x, y;

	score = 0;
	state = Gaming;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			map[i][j] = 0;

	x = Myrand(4, 0);
	y = Myrand(4, 0);
	map[x][y] = Myrand(10, 0) > 5 ? 2 : 4;
	while (1)
	{
		x = Myrand(4, 0);
		y = Myrand(4, 0);
		if (map[x][y] == 0)
		{
			map[x][y] = Myrand(10, 0) > 5 ? 2 : 4;
			break;
		}
	}
}

void Scene::newNum(char ch)
{
	int nofb = 0;
	int x, y;
	for (x = 0; x < 4; x++)
		for (y = 0; y < 4; y++)
			if (map[x][y] > 0)
				nofb++;

	if (nofb < 16)
	{
		switch (ch)
		{
		case 'a':

			y = 3;
			x = Myrand(4,0);
			while (1)
			{
				if (map[x][y] == 0)
				{
					map[x][y] = Myrand(10, 0) > 5 ? 2 : 4;
					break;
				}
				x++;
				if (x == 4)
					x = 0;
			}
			break;
		case 'd':
			y = 0;
			x = Myrand(4, 0);
			while (1)
			{
				if (map[x][y] == 0)
				{
					map[x][y] = Myrand(10, 0) > 5 ? 2 : 4;
					break;
				}
				x++;
				if (x == 4)
					x = 0;
			}
			break;
		case 'w':
			y = Myrand(4, 0);
			x = 3;
			while (1)
			{
				if (map[x][y] == 0)
				{
					map[x][y] = Myrand(10, 0) > 5 ? 2 : 4;
					break;
				}
				y++;
				if (y == 4)
					y = 0;
			}
			break;
		case 's':
			y = Myrand(4, 0);
			x = 0;
			while (1)
			{
				if (map[x][y] == 0)
				{
					map[x][y] = Myrand(10, 0) > 5 ? 2 : 4;
					break;
				}
				y++;
				if (y == 4)
					y = 0;
			}
			break;
		}
	}
}

void Scene::rend_BeginFace()
{

	boxRGBA(win->getRenderer(), 0, 0, Win_L, Win_H, 0x00, 0xE5, 0xEE, 255);
	boxRGBA(win->getRenderer(), 0, 280, 461, 480, 0x96, 0xCD, 0xCD, 255);
	win->RenderText("2048", Font_kaiti, 150, 300, 80);
	win->RenderText("Press Any Key To Begin", Font_kaiti, 70, 400, 30);
}

void Scene::rend_GameingBackGround()
{
	boxRGBA(win->getRenderer(), 0, 0, Win_L, Win_H, 255, 255, 255, 255);

	boxRGBA(win->getRenderer(), 50, 200, 413, 563, 0x4F, 0x4F, 0x4F, 255);

	vlineRGBA(win->getRenderer(), 50, 200, 564, 255, 255, 255, 255);
	vlineRGBA(win->getRenderer(), 140, 200, 564, 255, 255, 255, 255);
	vlineRGBA(win->getRenderer(), 231, 200, 564, 255, 255, 255, 255);
	vlineRGBA(win->getRenderer(), 322, 200, 564, 255, 255, 255, 255);
	vlineRGBA(win->getRenderer(), 413, 200, 564, 255, 255, 255, 255);

	hlineRGBA(win->getRenderer(), 50, 414, 200, 255, 255, 255, 255);
	hlineRGBA(win->getRenderer(), 50, 414, 290, 255, 255, 255, 255);
	hlineRGBA(win->getRenderer(), 50, 414, 381, 255, 255, 255, 255);
	hlineRGBA(win->getRenderer(), 50, 414, 472, 255, 255, 255, 255);
	hlineRGBA(win->getRenderer(), 50, 414, 563, 255, 255, 255, 255);

	win->RenderText("Score", Font_kaiti, 170, 30, 50, SDL_Color{ 0x4F, 0x4F, 0x4F });

	char buffer[256];
	sprintf(buffer, "%d", score);
	win->RenderText(buffer, Font_kaiti, (Win_L - strlen(buffer) * 40) / 2, 80, 80, SDL_Color{ 0x4F, 0x4F, 0x4F });
	win->Draw(win->mPicture->begin, 180, 600);
}

void Scene::rend_EndFace()
{
	boxRGBA(win->getRenderer(), 0, 0, Win_L, Win_H, 0x00, 0xE5, 0xEE, 255);
	boxRGBA(win->getRenderer(), 0, 280, 461, 480, 0x96, 0xCD, 0xCD, 255);

	win->Draw(win->mPicture->begin, 80, 550);
	win->Draw(win->mPicture->escape, 270, 550);

	win->RenderText("Game Over!", Font_kaiti, 40, 100, 80);

	char buffer[256];

	if (score <= readHiScore(Save_score))
	{
		sprintf(buffer, "Final Score:%d", score);
		win->RenderText(buffer, Font_kaiti, 20, 300, 40);
		sprintf(buffer, "Highest Score:%d", readHiScore(Save_score));
		win->RenderText(buffer, Font_kaiti, 20, 380, 40);
	}
	else
	{
		sprintf(buffer, "New Record:%d", score);
		win->RenderText(buffer, Font_kaiti, 20, 350, 40);
	}

}

void Scene::rend_Number()
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			switch (map[y][x])
			{
			case 2:
				win->Draw(win->mPicture->num2, 50 + 91 * x, 200 + 91 * y);
				break;
			case 4:
				win->Draw(win->mPicture->num4, 50 + 91 * x, 200 + 91 * y);
				break;
			case 8:
				win->Draw(win->mPicture->num8, 50 + 91 * x, 200 + 91 * y);
				break;
			case 16:
				win->Draw(win->mPicture->num16, 50 + 91 * x, 200 + 91 * y);
				break;
			case 32:
				win->Draw(win->mPicture->num32, 50 + 91 * x, 200 + 91 * y);
				break;
			case 64:
				win->Draw(win->mPicture->num64, 50 + 91 * x, 200 + 91 * y);
				break;
			case 128:
				win->Draw(win->mPicture->num128, 50 + 91 * x, 200 + 91 * y);
				break;
			case 256:
				win->Draw(win->mPicture->num256, 50 + 91 * x, 200 + 91 * y);
				break;
			case 512:
				win->Draw(win->mPicture->num512, 50 + 91 * x, 200 + 91 * y);
				break;
			case 1024:
				win->Draw(win->mPicture->num1024, 50 + 91 * x, 200 + 91 * y);
				break;
			case 2048:
				win->Draw(win->mPicture->num2048, 50 + 91 * x, 200 + 91 * y);
				break;
			default:
				break;
			}
		}
}

bool Scene::isEnd()
{
	int nofb = 0;
	bool t = true;

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			if (map[x][y] > 0)
				nofb++;
	if (nofb == 16)
	{

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 3; x++)
				if (map[x][y] == map[x + 1][y])
					t = false;
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 3; y++)
				if (map[x][y] == map[x][y + 1])
					t = false;
	}
	else
		t = false;
	return t;
}
