#include "testled.h"


TestLed::TestLed()
{
    this->setColor(new RedColor());
}

void TestLed::setRefreshRate(unsigned short refreshRate) {
    if (refreshRate > TestLed::MAX_REFRESH_RATE) {
        refreshRate = TestLed::MAX_REFRESH_RATE;
    }

    this->_refreshRate = refreshRate;
}

unsigned short TestLed::refreshRate() const {
    return this->_refreshRate;
}

void TestLed::setColor(Color *color) {
    this->_color = color;
}

Color* TestLed::color() const {
    return this->_color;
}

void TestLed::setEnabled(bool isEnabled) {
    this->_isEnabled = isEnabled;
}

bool TestLed::isEnabled() const {
    return this->_isEnabled;
}

std::string TestLed::status() const {
    std::stringstream statusStream;
    statusStream    << "Refresh rate: " << this->refreshRate() << std::endl
                    << "Color: " << this->color()->toString() << std::endl
                    << "Enabled: " << this->isEnabled() << std::endl;


    return statusStream.str();
}
