#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

class RenderWindow 
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h); // says to render a window with a specific title, width and height
	SDL_Texture* loadTexture(const char* p_filePath);

	int getRefreshRate(); // asks for the refresh rate of the screen

	void cleanUp();
	void clear();
	void render(SDL_Texture* p_tex); // to render a single texture
	void render(Entity& p_entity); // renders the indicated entity(ies)
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
