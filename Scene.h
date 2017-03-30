#pragma once
#include <SDL.h>
#include <vector>
#include "Element.h"

class Scene
{
	std::vector<Element> elements;
	SDL_Renderer* renderer;
public:
	Scene();
	~Scene();
	void loop();
	void render();
};

