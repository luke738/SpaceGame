#pragma once
#include <SDL.h>
#include "Texture.h"
#include "Vector2.h"

class Element
{
	Texture texture;
	Vector2 position;

public:
	Element();
	~Element();
	void tick(); //Update element. Functionality comes from child classes.
	void render(SDL_Renderer* renderer);
};

