#include "icommand.h"

ICommand::ICommand(ICamera *camera, ICommandSender *sender)
{
    this->_camera = camera;
    this->_sender = sender;
}

std::string ICommand::arguments() const
{
    return this->_arguments;
}

ICamera *ICommand::camera() const
{
    return this->_camera;
}

void ICommand::check(std::string commandName, std::string arguments)
{
//    printf("Command=[%s], arguments=[%s]\n", commandName.c_str(), arguments.c_str());

    if (!commandName.compare(this->commandName())) {
        this->_arguments = arguments;

        this->action();
    }
}

ICommandSender* ICommand::sender() const
{
    return this->_sender;
}
