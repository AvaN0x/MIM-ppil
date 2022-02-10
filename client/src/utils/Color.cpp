#include "Color.h"
#include <sstream>
#include <iomanip>

using namespace std;

const Color Color::BLUE = Color(0, 0, 255, 255);
const Color Color::RED = Color(255, 0, 0, 255);
const Color Color::BLACK = Color(0, 0, 0, 255);
const Color Color::GREEN = Color(0, 255, 0, 255);
const Color Color::YELLOW = Color(255, 255, 0, 255);
const Color Color::CYAN = Color(0, 255, 255, 255);

Color::operator std::string() const
{
    ostringstream s;
    s << "#"
      << hex << setfill('0') << setw(2) << _r
      << hex << setfill('0') << setw(2) << _g
      << hex << setfill('0') << setw(2) << _b
      << hex << setfill('0') << setw(2) << _a;
    return s.str();
}
