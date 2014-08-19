#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include <iostream>

#include "icommand.h"
#include "iled.h"

class ICommand;

class ICamera
{
private:
    ILed *_ledController;
    std::vector<ICommand*> _commands;

    std::string parseCommandName(std::string);
    std::string parseCommandArguments(std::string);

protected:
    ICamera();

public:
    void setLedController(ILed *);
    ILed* ledController();
    void addCommand(ICommand *);
    void processCommand(std::string);
};

#endif // CAMERA_H
