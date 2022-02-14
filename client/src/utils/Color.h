#pragma once
#include <vector>
#include <sstream>
#include <regex>

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

    Color() : _r(0),
              _g(0),
              _b(0),
              _a(255)
    {
    }

    Color(int r, int g, int b, int a = 255)
    {
        _r = (r < 0 || r > 255) ? 0 : r;
        _g = (g < 0 || g > 255) ? 0 : g;
        _b = (b < 0 || b > 255) ? 0 : b;
        _a = (a < 0 || a > 255) ? 0 : a;
    }

    Color(std::string s)
    {
        const std::regex pattern("^#[0-9a-f]{6}(?:[0-9a-f]{2})?$");
        if (!regex_match(s, pattern))
            throw std::invalid_argument("string \"" + s + "\" is not in a valid color format (expected #000000 or #00000000)");

        _r = std::stoi(s.substr(1, 2), nullptr, 16);
        _g = std::stoi(s.substr(3, 2), nullptr, 16);
        _b = std::stoi(s.substr(5, 2), nullptr, 16);
        if (s.length() == 9)
            _a = std::stoi(s.substr(7, 2), nullptr, 16);
        else
            _a = 255;
    };

    operator std::string() const;

    bool operator==(const Color &c) const
    {
        return _r == c._r && _g == c._g && _b == c._b && _a == c._a;
    }

    bool operator!=(const Color &c) const
    {
        return !(*this == c);
    }

    friend std::ostream &operator<<(std::ostream &os, const Color &c);
};

inline std::ostream &operator<<(std::ostream &os, const Color &c)
{
    return os << (std::string)c;
}