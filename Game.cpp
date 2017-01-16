#include <Game.h>
#include <iostream>
#include <thread>


Game::Game() : m_running(false)
{
}

bool Game::initialize(const char* title, int width, int height, int flags)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (!m_renderer.initialize(title, width, height, flags))
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	m_running = true;

	return true;
}

void Game::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch(event.type)
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					m_running = false;
					break;
				case SDLK_UP:
					std::cout << "Up Key Pressed" << std::endl;
					m_renderer.setDrawColour(255, 0, 0, 255);
					break;
				case SDLK_DOWN:
					std::cout << "Down Key Pressed" << std::endl;
					m_renderer.setDrawColour(0, 255, 0, 255);
					break;
				case SDLK_LEFT:
					std::cout << "Left Key Pressed" << std::endl;
					m_renderer.setDrawColour(0, 0, 255, 255);
					break;
				case SDLK_RIGHT:
					std::cout << "Right Key Pressed" << std::endl;
					m_renderer.setDrawColour(255, 255, 255, 255);
					break;
				default:
					m_renderer.setDrawColour(0, 0, 0, 255);
					break;
				}
	}
}

bool Game::isRunning()
{
	return m_running;
}

void Game::cleanUp()
{
	m_renderer.cleanUp();
	SDL_Quit();
}
