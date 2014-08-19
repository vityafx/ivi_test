#ifndef TESTLED_H
#define TESTLED_H

#include "iled.h"

class TestLed : public ILed
{
private:
    static const unsigned short MAX_REFRESH_RATE = 5;

    unsigned short _refreshRate;
    Color * _color;
    bool _isEnabled;

public:
    TestLed();

    void setRefreshRate(unsigned short);
    unsigned short refreshRate() const;

    void setColor(Color *);
    Color* color() const;

    void setEnabled(bool);
    bool isEnabled() const;

    std::string status() const;
};

#endif // TESTLED_H
