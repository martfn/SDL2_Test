#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Entity.hpp"
#include "Math.hpp"
#include "RenderWindow.hpp"
#include "Utils.hpp"
using namespace std;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) // calls the RenderWindow class with the parameters for a
:window(NULL), renderer(NULL)									  // title, width and height
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cout << "WINDOW FAILED TO INIT. ERROR:" << SDL_GetError() << endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if(texture == NULL)
		cout << "FAILED TO LOAD TEXTURE. ERROR:" << SDL_GetError() << endl;
	
	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex) // to render the background
{
	SDL_RenderCopy(renderer, p_tex, NULL, NULL);
}

void RenderWindow::render(Entity& p_entity) // to render the entities
{
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x;
	dst.y = p_entity.getPos().y;
	dst.w = p_entity.getCurrentFrame().w;
	dst.h = p_entity.getCurrentFrame().h;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);

}
void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

