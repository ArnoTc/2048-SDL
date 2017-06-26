#pragma once

#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2main.lib")

#include <SDL.h>

#include <stdexcept>
#include <string>

class Picture
{
public:
	Picture(SDL_Renderer *Ren);
	~Picture();

	//Load an image
	SDL_Texture * Picture::LoadImage(const std::string & file);
	void delimage(SDL_Texture* image);

private:
	SDL_Renderer *Renderer=nullptr;

public:
	 SDL_Texture *begin =nullptr;
	 SDL_Texture *escape = nullptr;

	 SDL_Texture *num2 = nullptr;
	 SDL_Texture *num4 = nullptr;
	 SDL_Texture *num8 = nullptr;
	 SDL_Texture *num16 = nullptr;
	 SDL_Texture *num32 = nullptr;
	 SDL_Texture *num64 = nullptr;
	 SDL_Texture *num128 = nullptr;
	 SDL_Texture *num256 = nullptr;
	 SDL_Texture *num512 = nullptr;
	 SDL_Texture *num1024 = nullptr;
	 SDL_Texture *num2048 = nullptr;
};

