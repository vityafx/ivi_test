#ifndef ILED_H
#define ILED_H

#include <sstream>
#include <string>

#include "color.h"

class ILed
{
public:
    ILed() {}

    virtual void setRefreshRate(unsigned short) = 0;
    virtual unsigned short refreshRate() const = 0;

    virtual void setColor(Color *) = 0;
    virtual Color* color() const = 0;

    virtual void setEnabled(bool) = 0;
    virtual bool isEnabled() const = 0;

    virtual std::string status() const = 0;
};

#endif // ILED_H
