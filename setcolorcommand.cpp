#include "setcolorcommand.h"

SetColorCommand::SetColorCommand(ICamera *camera, ICommandSender *sender) : ICommand(camera, sender)
{
}

const char* SetColorCommand::commandName() const
{
    return "set-color";
}

void SetColorCommand::action()
{
    std::stringstream stringStream;

    try {
        Color *newColor = ColorFactory::createColor(this->arguments());

        this->camera()->ledController()->setColor(newColor);

        stringStream << "OK " << this->camera()->ledController()->color()->toString() << std::endl;
    } catch (UndefinedColor &) {
        stringStream << "FAILED" << std::endl;
    }

    this->sender()->send(stringStream.str());
}
