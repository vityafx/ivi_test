#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>

#include "icamera.h"
#include "icommandsender.h"

class ICamera;

class ICommand
{
private:
    std::string _arguments;
    ICamera *_camera;
    ICommandSender *_sender;

protected:
    ICommand(ICamera *_camera, ICommandSender *_sender);

    std::string arguments() const;
    ICamera *camera() const;

public:
    ICommandSender* sender() const;
    void check(std::string, std::string);
    virtual void action() = 0;
    virtual const char* commandName() const = 0;
};

#endif // ICOMMAND_H
