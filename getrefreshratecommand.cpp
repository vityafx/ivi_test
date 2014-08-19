#include "getrefreshratecommand.h"

GetRefreshRateCommand::GetRefreshRateCommand(ICamera *camera, ICommandSender *sender) : ICommand(camera, sender)
{
}

const char* GetRefreshRateCommand::commandName() const
{
    return "get-refresh-rate";
}

void GetRefreshRateCommand::action()
{
    std::stringstream stringStream;
    stringStream << "OK " << this->camera()->ledController()->refreshRate() << std::endl;

    this->sender()->send(stringStream.str());
}
