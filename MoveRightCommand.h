#ifndef MOVERIGHTCOMMAND_H
#define MOVERIGHTCOMMAND_H
#include "Command.h"
class MoveRightCommand : public Command
{
public:
	MoveRightCommand() {}
	void execute() override
	{
		std::cout << "Move right" << std::endl;
	}
	void undo() override
	{
		std::cout << "Undo move right" << std::endl;
	}
};
#endif
