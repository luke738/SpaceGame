#pragma once
#include "Scene.h"
#include "State.h"

class MenuScene : public Scene
{
	SDL_Event e;

public:
	using Scene::Scene;
	MenuScene();
	~MenuScene();
	void loop(State* state);
};

