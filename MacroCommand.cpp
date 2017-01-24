#include "MacroCommand.h"

MacroCommand::MacroCommand()
{
}

void MacroCommand::add(Command * command)
{
	m_commands.push_back(command);
}

void MacroCommand::remove(Command * command)
{
	m_commands.remove(command);
}

void MacroCommand::execute()
{
	std::list<Command*>::iterator it = m_commands.begin();
	std::list<Command*>::iterator end = m_commands.end();
	for (; it != end; ++it)
		(*it)->execute();
}

void MacroCommand::undo()
{
	std::list<Command*>::reverse_iterator it = m_commands.rbegin();
	std::list<Command*>::reverse_iterator end = m_commands.rend();
	for (; it != end; ++it)
		(*it)->undo();
	m_commands.clear();
}
