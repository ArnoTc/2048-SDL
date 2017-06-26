#include "Picture.h"

#pragma comment(lib,"SDL2_image.lib")
#include <SDL_image.h>
#include <stdexcept>

Picture::Picture(SDL_Renderer *Ren) :Renderer(Ren)
{
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	begin = LoadImage("data/Picture/button/begin.png");
	escape = LoadImage("data/Picture/button/escape.png");

	num2 = LoadImage("data/Picture/number/2.jpg");
	num4 = LoadImage("data/Picture/number/4.jpg");
	num8 = LoadImage("data/Picture/number/8.jpg");
	num16 = LoadImage("data/Picture/number/16.jpg");
	num32 = LoadImage("data/Picture/number/32.jpg");
	num64 = LoadImage("data/Picture/number/64.jpg");
	num128 = LoadImage("data/Picture/number/128.jpg");
	num256 = LoadImage("data/Picture/number/256.jpg");
	num512 = LoadImage("data/Picture/number/512.jpg");
	num1024 = LoadImage("data/Picture/number/1024.jpg");
	num2048 = LoadImage("data/Picture/number/2048.jpg");
}


Picture::~Picture()
{
	delimage(begin);
	delimage(escape);

	delimage(num2);
	delimage(num4);
	delimage(num8);
	delimage(num16);
	delimage(num32);
	delimage(num64);
	delimage(num128);
	delimage(num256);
	delimage(num512);
	delimage(num1024);
	delimage(num2048);
}

/**
*  Loads an image directly to texture using SDL_image's
*  built in function IMG_LoadTexture
*  @param file The image file to load
*  @return SDL_Texture* to the loaded texture
*/
SDL_Texture * Picture::LoadImage(const std::string & file)
{
	SDL_Texture *texture = IMG_LoadTexture(Renderer, file.c_str());
	if (texture == nullptr) {
		throw std::runtime_error("LoadTexture");
	}
	return texture;
}

void Picture::delimage(SDL_Texture * image)
{
	SDL_DestroyTexture(image);
}
