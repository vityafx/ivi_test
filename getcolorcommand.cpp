#include "getcolorcommand.h"

GetColorCommand::GetColorCommand(ICamera *camera, ICommandSender *sender) : ICommand(camera, sender)
{
}

const char* GetColorCommand::commandName() const
{
    return "get-color";
}

void GetColorCommand::action()
{
    std::stringstream stringStream;
    stringStream << "OK " << this->camera()->ledController()->color()->toString() << std::endl;

    this->sender()->send(stringStream.str());
}
