#ifndef CROUCHCOMMAND_H
#define CROUCHCOMMAND_H
#include "Command.h"
class CrouchCommand : public Command
{
public:
	CrouchCommand() {}
	void execute() override
	{
		std::cout << "Crouching" << std::endl;
	}
	void undo() override
	{
		std::cout << "Undo crouching" << std::endl;
	}
};
#endif
