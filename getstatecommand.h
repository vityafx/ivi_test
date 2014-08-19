#ifndef GETSTATECOMMAND_H
#define GETSTATECOMMAND_H

#include <sstream>
#include <string>

#include "icommand.h"
#include "icamera.h"
#include "icommandsender.h"

class GetStateCommand : public ICommand
{
public:
    GetStateCommand(ICamera *, ICommandSender *);

    void action();
    const char* commandName() const;
};

#endif // GETSTATECOMMAND_H
