#ifndef SETSTATECOMMAND_H
#define SETSTATECOMMAND_H

#include <sstream>
#include <string>

#include "icommand.h"
#include "icamera.h"
#include "icommandsender.h"

class SetStateCommand : public ICommand
{
public:
    SetStateCommand(ICamera *, ICommandSender *);

    void action();
    const char* commandName() const;
};


#endif // SETSTATECOMMAND_H
