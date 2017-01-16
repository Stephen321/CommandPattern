#ifndef GAME_H
#define GAME_H
#include "Renderer.h"

class Game
{
public:
	Game();
	bool initialize(const char* title, int width, int height, int flags);
	void handleEvents();
	bool isRunning();
	void cleanUp();
private:
	Renderer m_renderer;
	bool m_running;
};
#endif

