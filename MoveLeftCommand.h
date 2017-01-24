#ifndef MOVELEFTCOMMAND_H
#define MOVELEFTCOMMAND_H
#include "Command.h"
class MoveLeftCommand : public Command
{
public:
	MoveLeftCommand() {}
	void execute() override
	{
		std::cout << "Move left" << std::endl;
	}
	void undo() override
	{
		std::cout << "Undo move left" << std::endl;
	}
};
#endif
