#pragma once
#include <SDL.h>
#include "Texture.h"
#include "Vector2.h"

class Element
{
protected:
	Texture texture;
	Vector2 position;

public:
	Element();
	Element(Vector2 pos, Texture tex);
	Element(Vector2 pos, char* texturePath, SDL_Renderer* renderer);
	~Element();
	virtual void tick(); //Update element. Functionality comes from child classes.
	void renderSelf(SDL_Renderer* renderer);
	Vector2 getTopLeft();
	Vector2 getBottomRight();
};

