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
#include "State.h"
#include "Button.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//SDL variables
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

//Current game state
State state = mainMenu;
//Scenes
std::vector<Scene*> scenes;

bool initSDL();
void quitSDL();
Vector2 getVec(double a, double b);
void createScenes();

int main(int argc, char* args[])
{
	SDL_Event e;

	if (!initSDL())
	{
		std::cout << "initFail" << SDL_GetError();
		std::cin.get();
	}
	else
	{
		createScenes();
		while (state!=quit)
		{
			SDL_RenderClear(renderer);
			scenes[state]->loop(&state);
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
	Element* e0 = new Element(getVec(100, 200), "assets/images/dot.png", renderer);
	Element* e1 = new Button(getVec(200, 200), "assets/images/Quit.png", renderer, quit);
	e.push_back(e0);
	e.push_back(e1);
	Scene* mainMenu = new MenuScene(renderer, e);
	scenes.push_back(mainMenu);
}
