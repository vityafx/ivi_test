#include "color.h"


Color::Color(LedColors::LedColors color) {
    this->_ledColor = color;
}

LedColors::LedColors Color::ledColor() const {
    return this->_ledColor;
}
