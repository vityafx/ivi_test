#include "icamera.h"

ICamera::ICamera()
{
}

void ICamera::addCommand(ICommand *command) {
    if (command != NULL) {
        this->_commands.push_back(command);
    }
}

std::string ICamera::parseCommandName(std::string textString)
{
    textString.erase(std::remove(textString.begin(), textString.end(), '\n'), textString.end());
    std::size_t separatorIndex = textString.find(' ');

    if (separatorIndex == std::string::npos) {
        return textString;
    }

    return std::string(textString, 0, separatorIndex);
}
std::string ICamera::parseCommandArguments(std::string textString)
{
    textString.erase(std::remove(textString.begin(), textString.end(), '\n'), textString.end());
    std::size_t separatorIndex = textString.find(' ');

    if (separatorIndex == std::string::npos) {
        return "";
    }

    return std::string(textString, separatorIndex + 1, textString.length() - 1);
}

void ICamera::processCommand(std::string textString) {
    for (unsigned short i = 0; i < this->_commands.size(); i++) {
        this->_commands[i]->check(this->parseCommandName(textString), this->parseCommandArguments(textString));
    }
}

void ICamera::setLedController(ILed *newLedController) {
    this->_ledController = newLedController;
}

ILed* ICamera::ledController() {
    return this->_ledController;
}
