#include "setstatecommand.h"

SetStateCommand::SetStateCommand(ICamera *camera, ICommandSender *sender) : ICommand(camera, sender)
{
}

const char* SetStateCommand::commandName() const
{
    return "set-state";
}

void SetStateCommand::action()
{
    std::stringstream stringStream;

    if (!this->arguments().compare("on")) {
        this->camera()->ledController()->setEnabled(true);

        stringStream << "OK " << this->camera()->ledController()->isEnabled() << std::endl;

        this->sender()->send(stringStream.str());
    } else if (!this->arguments().compare("off")) {
        this->camera()->ledController()->setEnabled(false);

        stringStream << "OK " << this->camera()->ledController()->isEnabled() << std::endl;

        this->sender()->send(stringStream.str());
    } else {
        stringStream << "FAILED" << std::endl;

        this->sender()->send(stringStream.str());
    }
}
