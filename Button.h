#pragma once
#include "Element.h"
#include "State.h"

class Button : public Element
{
public:
	State type;
	Button();
	Button(Vector2 pos, char* texturePath, SDL_Renderer* renderer, State targetState);
	~Button();
	bool wasClicked(Vector2 v);
};

