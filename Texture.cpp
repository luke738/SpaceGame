#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Vector2.h"

Texture::Texture()
{
	intTexture = NULL;
	height = 0;
	width = 0;
}

Texture::~Texture()
{
	free();
}

bool Texture::loadFromFile(char* path, SDL_Renderer* renderer)
{
	free();
	SDL_Surface* rawSurface = IMG_Load(path);
	if (rawSurface == NULL)
	{
		std::cout << "loadFail" << SDL_GetError();
		std::cin.get();
	}
	else
	{
		SDL_SetColorKey(rawSurface, SDL_TRUE, SDL_MapRGB(rawSurface->format, 0, 0, 0));
		intTexture = SDL_CreateTextureFromSurface(renderer, rawSurface);
		if (intTexture == NULL)
		{
			std::cout << "convertFail" << SDL_GetError();
			std::cin.get();
		}
		else
		{
			height = rawSurface->h;
			width = rawSurface->w;
		}
		SDL_FreeSurface(rawSurface);
	}
	return intTexture != NULL;
}

void Texture::free()
{
	if (intTexture != NULL)
	{
		SDL_DestroyTexture(intTexture);
		intTexture = NULL;
		height = 0;
		width = 0;
	}
}

void Texture::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetTextureColorMod(intTexture, r, g, b);
}

void Texture::render(Vector2 pos, SDL_Renderer* renderer)
{
	SDL_Rect target = { pos.x,pos.y,width,height };
	SDL_RenderCopy(renderer, intTexture, NULL, &target);
}

void Texture::centerRender(Vector2 pos, SDL_Renderer* renderer)
{
	SDL_Rect target = { pos.x-width/2,pos.y-height/2,width,height };
	SDL_RenderCopy(renderer, intTexture, NULL, &target);
}

int Texture::getHeight()
{
	return height;
}

int Texture::getWidth()
{
	return width;
}
