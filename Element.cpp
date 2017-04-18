#include "Element.h"
#include <SDL.h>
#include <vector>

Element::Element() {}

Element::Element(Vector2 pos, Texture tex)
{
	position = pos;
	texture = tex;
}

Element::Element(Vector2 pos, char* texturePath, SDL_Renderer* renderer)
{
	position = pos;
	texture.loadFromFile(texturePath, renderer);
}

Element::~Element()
{
	texture.free();
}

void Element::tick()
{
	//does nothing, functionality defined by child classes
}

void Element::renderSelf(SDL_Renderer* renderer)
{
	texture.render(position, renderer);
}

Vector2 Element::getTopLeft()
{
	return position;
}

Vector2 Element::getBottomRight()
{
	Vector2 temp = Vector2(position.x + texture.getWidth(), position.y + texture.getHeight());
	return temp;
}