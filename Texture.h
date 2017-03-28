#pragma once
#include <SDL.h>
#include "Vector2.h"
class Texture
{
public:
	Texture();
	~Texture();
	bool loadFromFile(char* path, SDL_Renderer* renderer);  //load texture from file
	void free(); //dealocate texture
	void setColor(Uint8 r, Uint8 g, Uint8 b);
	void render(Vector2 pos, SDL_Renderer* renderer); //render at point (pos.x,pos.y)
	void centerRender(Vector2 pos, SDL_Renderer* renderer); //render from center, not top-left
	int getHeight();
	int getWidth();
private:
	SDL_Texture* intTexture;
	int height;
	int width;
};

