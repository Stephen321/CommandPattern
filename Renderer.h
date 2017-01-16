#ifndef RENDERER_H
#define RENDERER_H
#include <SDL.h>

class Drawable; //TODO: remove this
class Renderer 
{
public:
	Renderer();
	void cleanUp();
	void setDrawColour(int r, int g, int b, int a) const;
	bool initialize(const char* title, int width, int height, int flags);
	void clear();
	void present();
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

};

#endif