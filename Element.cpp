#include "Element.h"
#include <SDL.h>
#include <vector>

Element::Element()
{
}

Element::~Element()
{
}

void Element::tick()
{
	//does nothing, functionality defined by child classes
}

void Element::render(SDL_Renderer* renderer)
{
	texture.centerRender(position, renderer);
}