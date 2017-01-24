#include "InputHandler.h"

InputHandler::InputHandler()
{
	m_macroCommand = new MacroCommand;
}

InputHandler::~InputHandler()
{
	std::unordered_map<SDL_Keycode, Command*>::iterator it = m_keybindings.begin();
	std::unordered_map<SDL_Keycode, Command*>::iterator end = m_keybindings.end();
	for (; it != end; ++it)
	{
		Command* c = it->second;
		delete c;
		c = nullptr;
	}
}

void InputHandler::handleInput()
{
	SDL_Event event;

	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (m_keybindings.find(event.key.keysym.sym) != m_keybindings.end()) //binding exists
			{
				m_keybindings.at(event.key.keysym.sym)->execute(); //call execute
				m_macroCommand->add(m_keybindings.at(event.key.keysym.sym)); //add command to macro
			}
			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_BACKSPACE)//onkey up and backspace then undo
			{
				m_macroCommand->undo();
			}
			break;
		}
	}
}

void InputHandler::bind(SDL_Keycode code, Command * command)
{
	if (m_keybindings.find(code) == m_keybindings.end())
	{
		m_keybindings.insert(std::pair<SDL_Keycode, Command*>(code, command));
	}
	else
	{
		Command* c = m_keybindings.at(code);
		delete c;
		c = nullptr; 
		m_keybindings.at(code) = command;
	}
}