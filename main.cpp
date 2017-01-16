#include <iostream>
#include <thread>
#include <string>

#include <SDL.h>

#include "Game.h"

using namespace std;

int main(int argc, char** argv)
{
	Game* game = new Game();

	game->initialize("DGPP Skelatol", 1280, 720, SDL_WINDOW_INPUT_FOCUS);
	
	while(game->isRunning())
	{
		game->handleEvents();
	}

	game->cleanUp();
	
	return 0;
}


