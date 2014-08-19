#ifndef ICOMMANDSENDER_H
#define ICOMMANDSENDER_H

#include <string>

class ICommandSender
{
public:
    virtual void send(std::string) = 0;
};

#endif // ICOMMANDSENDER_H
