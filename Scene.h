#pragma once
#include <SDL.h>
#include <vector>
#include "Element.h"

class Scene
{
	std::vector<Element*> elements; //Vector of all of the various in-game elements
	SDL_Renderer* renderer;

public:
	Scene(SDL_Renderer* render, std::vector<Element*> e);
	~Scene();
	void loop(); //Carries out all operations of the frame
	void renderElements(); //Render all onscreen elements
};

