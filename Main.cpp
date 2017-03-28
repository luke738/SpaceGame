#include <iostream>
#include <vector>
#include "Vector2.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool initSDL();
void quitSDL();
Vector2 getVec(double a, double b);

int main(char* args[])
{
	bool quit = false;
	SDL_Event e;

	if (!initSDL())
	{
		std::cout << "initFail" << SDL_GetError();
		std::cin.get();
	}

	else
	{
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					if (e.key.keysym.sym == SDLK_ESCAPE)
					{
						quit = true;
					}
				}
			}
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
		}
	}

	quitSDL();
	std::cin.get();
	return 0;
}

bool initSDL()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << SDL_GetError();
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << SDL_GetError();
			success = false;
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				success = false;
				std::cout << "imgFail" << SDL_GetError();
				std::cin.get();
			}
			else
			{
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (renderer == NULL)
				{
					success = false;
					std::cout << "renderInitFail" << SDL_GetError();
					std::cin.get();
				}
				else
				{
					SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
				}
			}
		}
	}
	return success;
}

void quitSDL()
{
	//Destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
	IMG_Quit();
}

Vector2 getVec(double a, double b)
{
	Vector2 temp(a, b);
	return temp;
}
