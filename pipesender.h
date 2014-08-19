#ifndef PIPESENDER_H
#define PIPESENDER_H

#include <string>
#include <unistd.h>

#include "icommandsender.h"

class PipeSender : public ICommandSender
{
private:
    int _fifo;
protected:
    void setFifo(int);

    PipeSender();
    PipeSender(int);
public:
    void send(std::string);
};

#endif // PIPESENDER_H
