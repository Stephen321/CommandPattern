#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H
#include "Command.h"
class JumpCommand : public Command
{
public:
	JumpCommand() {}
	void execute() override
	{
		std::cout << "Jump" << std::endl;
	}
	void undo() override
	{
		std::cout << "Undo jump" << std::endl;
	}
};
#endif
