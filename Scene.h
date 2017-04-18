#pragma once
#include <SDL.h>
#include <vector>
#include "Element.h"
#include "State.h"

class Scene
{
protected:
	std::vector<Element*> elements; //Vector of all of the various in-game elements
	SDL_Renderer* renderer;

public:
	Scene();
	Scene(SDL_Renderer* render, std::vector<Element*> e);
	~Scene();
	virtual void loop(State* state); //Carries out all operations of the frame
	void renderElements(); //Render all onscreen elements
};

