#include "MenuScene.h"
#include "State.h"
#include "Button.h"
#include <iostream>


MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::loop(State* state)
{
	Vector2 clickSpot;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			clickSpot.x = e.button.x;
			clickSpot.y = e.button.y;
		}
	}
	if (&clickSpot != NULL)
	{
		for each (Element* el in elements)
		{
			Button* dynCast = dynamic_cast<Button*>(el);
			if (dynCast!=NULL)
			{
				if (dynCast->wasClicked(clickSpot))
				{
					*state = dynCast->type;
				}
			}
		}
	}
	for each (Element* el in elements)
	{
		el->tick();
	}
	renderElements();
}