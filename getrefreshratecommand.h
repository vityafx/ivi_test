#ifndef GETREFRESHRATECOMMAND_H
#define GETREFRESHRATECOMMAND_H

#include <sstream>
#include <string>

#include "icommand.h"
#include "icamera.h"
#include "icommandsender.h"

class GetRefreshRateCommand : public ICommand
{
public:
    GetRefreshRateCommand(ICamera *, ICommandSender *);

    void action();
    const char* commandName() const;
};
#endif // GETREFRESHRATECOMMAND_H
