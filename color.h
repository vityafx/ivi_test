#ifndef COLOR_H
#define COLOR_H

#include <string>

namespace LedColors {
    enum LedColors {
        BLACK,
        RED,
        GREEN,
        BLUE
    };
}

class UndefinedColor : public std::exception {
    virtual const char* what() const throw() {
        return "Undefined color";
    }
};

class Color
{
private:
    LedColors::LedColors _ledColor;

protected:
    Color(LedColors::LedColors);

public:
    LedColors::LedColors ledColor() const;

    virtual const char* toString() const = 0;
};


class RedColor : public Color {
public:
    RedColor() : Color(LedColors::RED) {}

    const char* toString() const {
        return RedColor::name();
    }

    static const char* name() {
        return "red";
    }
};

class GreenColor : public Color {
public:
    GreenColor() : Color(LedColors::GREEN) {}

    const char* toString() const {
        return GreenColor::name();
    }

    static const char* name() {
        return "green";
    }
};

class BlueColor : public Color {
public:
    BlueColor() : Color(LedColors::BLUE) {}

    const char* toString() const {
        return BlueColor::name();
    }

    static const char* name() {
        return "blue";
    }
};

class ColorFactory {
public:

    static Color* createColor(std::string colorName) {
        Color *color;

        if (!colorName.compare(RedColor::name())) {
            color = new RedColor();
        } else if (!colorName.compare(GreenColor::name())) {
            color = new GreenColor();
        } else if (!colorName.compare(BlueColor::name())) {
            color = new BlueColor();
        } else {
            throw UndefinedColor();
        }

        return color;
    }

    static Color* createColor(LedColors::LedColors colorName) {
        Color *color;

        switch (colorName) {
            case LedColors::RED: {
                color = new RedColor();

                break;
            }

            case LedColors::GREEN: {
                color = new GreenColor();

                break;
            }

            case LedColors::BLUE: {
                color = new BlueColor();

                break;
            }

            default: {
                throw UndefinedColor();
            }
        }

        return color;
    }
};

#endif // COLOR_H
