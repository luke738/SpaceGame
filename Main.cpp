#include <iostream>
#include <vector>
#include "Vector2.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include <cmath>
#include "Scene.h"
#include "Element.h"
#include "MenuScene.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//SDL variables
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

//Current game state
enum State {mainMenu=0, game, pauseMenu};
State state = mainMenu;
//Scenes
std::vector<Scene> scenes;

bool initSDL();
void quitSDL();
Vector2 getVec(double a, double b);
void createScenes();

int main(int argc, char* args[])
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
		createScenes();
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
			scenes[state].loop();
			SDL_RenderPresent(renderer);
		}
	}

	quitSDL();
	//std::cin.get();
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

void createScenes() //At some point this will load things from a file of some sort. Hardcoded for now.
{
	//Main Menu
	std::vector<Element*> e;
	Element *e0 = new Element(getVec(100, 200), "assets/images/dot.png", renderer);
	Element *e1 = new Element(getVec(200, 200), "assets/images/dot.png", renderer);
	e.push_back(e0);
	e.push_back(e1);
	Scene mainMenu = MenuScene(renderer, e);
	scenes.push_back(mainMenu);
}
