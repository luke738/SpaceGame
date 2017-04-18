#include "Button.h"



Button::Button()
{
}

Button::Button(Vector2 pos, char* texturePath, SDL_Renderer* renderer, State targetState)
{
	position = pos;
	texture.loadFromFile(texturePath, renderer);
	type = targetState;
}

Button::~Button()
{
}

bool Button::wasClicked(Vector2 v)
{
	Vector2 topIn = v - getTopLeft();
	Vector2 bottomIn = getBottomRight() - v;
	if (topIn.x >= 0 && topIn.y >= 0 && bottomIn.x >= 0 && bottomIn.y >= 0)
	{
		return true;
	}
	return false;
}
