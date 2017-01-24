#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H
#include "Command.h"
class ExitCommand : public Command
{
public:
	ExitCommand(bool& running) : m_running(running) {}
	void execute() override
	{
		std::cout << "exiting" << std::endl;
		m_running = false;
	}
	void undo() override
	{
		std::cout << "Undo exiting" << std::endl;
	}
private:
	bool& m_running;
};
#endif
