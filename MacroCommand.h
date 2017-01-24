#ifndef  MACROCOMMAND_H
#define MACROCOMMAND_H
#include <list>
#include "Command.h"
class MacroCommand : public Command
{
public:
	MacroCommand();
	void add(Command* command);
	void remove(Command* command);
	void execute() override;
	void undo() override;
private:
	std::list<Command*> m_commands;
};
#endif 
