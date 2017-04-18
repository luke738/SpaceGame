#include "Scene.h"
#include <SDL.h>
#include <vector>
#include "Element.h"
#include <iostream>
#include <SDL_image.h>
#include "State.h"
#include <iostream>

Scene::Scene() {}

Scene::Scene(SDL_Renderer* render, std::vector<Element*> e)
{
	renderer = render;
	elements = e;
}

Scene::~Scene()
{
}

void Scene::loop(State* state)
{
	for each (Element* e in elements)
	{
		e->tick();
	}
	renderElements();
}

void Scene::renderElements()
{
	for each (Element* e in elements)
	{
		e->renderSelf(renderer);
	}
}
