#ifndef SETREFRESHRATECOMMAND_H
#define SETREFRESHRATECOMMAND_H

#include <sstream>
#include <string>

#include "icommand.h"
#include "icamera.h"
#include "icommandsender.h"

class SetRefreshRateCommand : public ICommand
{
public:
    SetRefreshRateCommand(ICamera *, ICommandSender *);

    void action();
    const char* commandName() const;
};

#endif // SETREFRESHRATECOMMAND_H
