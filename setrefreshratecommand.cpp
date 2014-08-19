#include "setrefreshratecommand.h"

SetRefreshRateCommand::SetRefreshRateCommand(ICamera *camera, ICommandSender *sender) : ICommand(camera, sender)
{

}

const char* SetRefreshRateCommand::commandName() const
{
    return "set-refresh-rate";
}

void SetRefreshRateCommand::action()
{
    std::stringstream stringStream;

    if (!this->arguments().empty()) {
        unsigned short newRefreshRate;

        std::stringstream ss(this->arguments());
        newRefreshRate = ss >> newRefreshRate ? newRefreshRate : 0;

        this->camera()->ledController()->setRefreshRate(newRefreshRate);

        stringStream << "OK " << this->camera()->ledController()->refreshRate() << std::endl;

    } else {
        stringStream << "FAILED" << std::endl;
    }

    this->sender()->send(stringStream.str());
}
