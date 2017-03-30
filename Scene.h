#pragma once
#include <SDL.h>
#include <vector>
#include "Element.h"

class Scene
{
	std::vector<Element> elements; //Vector of all of the various in-game elements
	SDL_Renderer* renderer;

public:
	Scene();
	~Scene();
	void loop(); //Carries out all operations of the frame
	void render(); //Render all onscreen elements
};

