#include <iostream>
#include <thread>
#include <string>

#include <SDL.h>
#include "InputHandler.h"
#include "Commands.h"

using namespace std;

int main(int argc, char** argv)
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	InputHandler inputHandler;
	bool running;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("Command Pattern", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 405, SDL_WINDOW_INPUT_FOCUS);

		if (window != 0)
		{
			//Window creation success
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0)
			{
				//Renderer creation success
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			}
			else
			{
				//Renderer init fail
				return 0;
			}
		}
		else
		{
			//Window init fail
			return 0;
		}
	}
	else
	{
		//INIT fail
		return 0;
	}

	//set up
	running = true;

	inputHandler.bind(SDLK_UP, new JumpCommand);
	inputHandler.bind(SDLK_w, new JumpCommand);
	inputHandler.bind(SDLK_SPACE, new JumpCommand);

	inputHandler.bind(SDLK_d, new MoveRightCommand);
	inputHandler.bind(SDLK_s, new CrouchCommand);
	inputHandler.bind(SDLK_a, new MoveLeftCommand);

	inputHandler.bind(SDLK_ESCAPE, new ExitCommand(running));
	
	//game loop
	while(running)
	{
		inputHandler.handleInput();
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	return 0;
}


