#pragma once
#include <vector>
#include <sstream>

class Color
{
public:
    int _r, _g, _b, _a;
    static const Color BLUE;
    static const Color RED;
    static const Color BLACK;
    static const Color GREEN;
    static const Color YELLOW;
    static const Color CYAN;

    Color() :
        _r(0),
        _g(0),
        _b(0),
        _a(0)
    {}

    Color(int r, int g, int b, int a)
    {
        _r = (r < 0 || r > 255) ? 0 : r;
        _g = (g < 0 || g > 255) ? 0 : g;
        _b = (b < 0 || b > 255) ? 0 : b;
        _a = (a < 0 || a > 255) ? 0 : a;
    }

    friend std::ostream& operator<<(std::ostream& os, const Color& c);
};

inline std::ostream& operator<<(std::ostream& os, const Color& c)
{
    return os << "r : " << c._r << "g : " << c._g << "b : " << c._b << "a : " << c._a;
}