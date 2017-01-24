#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <unordered_map>
#include "SDL_events.h"
#include "Command.h"
#include "MacroCommand.h"
class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void handleInput();
	void bind(SDL_Keycode code, Command* command);
private:
	MacroCommand* m_macroCommand;
	std::unordered_map<SDL_Keycode, Command*> m_keybindings;
};
#endif