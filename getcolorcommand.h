#ifndef GETCOLORCOMMAND_H
#define GETCOLORCOMMAND_H

#include <sstream>
#include <string>

#include "icommand.h"
#include "icamera.h"
#include "icommandsender.h"

class GetColorCommand : public ICommand
{
public:
    GetColorCommand(ICamera *, ICommandSender *);

    void action();
    const char* commandName() const;
};

#endif // GETCOLORCOMMAND_H
