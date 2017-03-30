#pragma once
#include "Texture.h"
#include "Vector2.h"

class Element
{
	Texture texture;
	Vector2 position;
public:
	Element();
	~Element();
	void loop();
	void render();
};

