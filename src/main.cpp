#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "Math.hpp"
#include "RenderWindow.hpp"
#include "Utils.hpp"
using namespace std;

int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		cout << "SDL_INIT HAS FAILED. SDL_ERROR:" << SDL_GetError() << endl;
	}

	if(!(IMG_Init(IMG_INIT_PNG)))
	{
		cout << "IMG_INIT HAS FAILED. ERROR:" << SDL_GetError() << endl;

	}


	RenderWindow window("GAME", 640, 480);

	SDL_Texture* background = window.loadTexture("res/gfx/bg.png");
	SDL_Texture* floor = window.loadTexture("res/gfx/floor.png");
	SDL_Texture* playerTex = window.loadTexture("res/gfx/plr.png");

	std::vector<Entity> entityArray = {
		Entity(Vector2f(64*0, 416), floor),
		Entity(Vector2f(64*1, 416), floor),
		Entity(Vector2f(64*2, 416), floor),
		Entity(Vector2f(64*3, 416), floor),
		Entity(Vector2f(64*4, 416), floor),
		Entity(Vector2f(64*5, 416), floor),
		Entity(Vector2f(64*6, 416), floor),
		Entity(Vector2f(64*7, 416), floor),
		Entity(Vector2f(64*8, 416), floor),
		Entity(Vector2f(64*9, 416), floor),
	};

	{
		Entity player(Vector2f(10, 10), playerTex);
		entityArray.push_back(player);

	}

	
	bool gameRunning = true;

	SDL_Event event;

	while(gameRunning)
	{


		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();




		window.render(background);


		for (Entity& e : entityArray)
		{
			window.render(e);
		}

		window.display();


	}

	
	window.cleanUp();

	SDL_Quit();


	return 0;
}