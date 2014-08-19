#ifndef SETCOLORCOMMAND_H
#define SETCOLORCOMMAND_H

#include <sstream>
#include <string>

#include "color.h"
#include "icommand.h"
#include "icamera.h"
#include "icommandsender.h"

class SetColorCommand : public ICommand
{
public:
    SetColorCommand(ICamera *, ICommandSender *);

    void action();
    const char* commandName() const;
};


#endif // SETCOLORCOMMAND_H
