#include "getstatecommand.h"

GetStateCommand::GetStateCommand(ICamera *camera, ICommandSender *sender) : ICommand(camera, sender)
{
}

const char* GetStateCommand::commandName() const
{
    return "get-state";
}

void GetStateCommand::action()
{
    std::stringstream stringStream;
    stringStream << "OK " << this->camera()->ledController()->isEnabled() << std::endl;

    this->sender()->send(stringStream.str());
}
