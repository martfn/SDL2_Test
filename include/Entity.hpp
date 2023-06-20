#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

class Entity // defines entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex); // attributes a position and texture
	Vector2f& getPos() // asks for the position
	{
		return pos; // indicates to return the position value
	}
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;

};
