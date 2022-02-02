#include <string>
#include <string.h>

class Vecteur2D
{
public:
    double x, y;

    // ================== CONSTRUCTORS ==================
    // If no explicit, parameters from constructor can be converted implicitly by compiler to Vecteur2D
    Vecteur2D(const double &x = 0, const double &y = 0);
    Vecteur2D(const std::string &s);
    Vecteur2D *clone() const { return new Vecteur2D(*this); }

    virtual ~Vecteur2D() {}

    // ================== OPERATORS ==================
    const Vecteur2D operator+(const Vecteur2D &u) const;
    const Vecteur2D &operator+=(const Vecteur2D &u);
    const Vecteur2D operator-() const;
    const Vecteur2D operator-(const Vecteur2D &u) const;
    const Vecteur2D &operator-=(const Vecteur2D &u);
    const Vecteur2D operator*(const double &a) const;
    const Vecteur2D &operator*=(const double &a);
    const Vecteur2D operator/(const double &a) const;
    const Vecteur2D &operator/=(const double &a);
    operator std::string() const;
    bool operator==(const Vecteur2D &u) const;
    bool operator!=(const Vecteur2D &u) const;

    // ================== TOSTRING AND PRINT ==================
    std::string toString() const
    {
        return ""; // TODO @Avan0x
    }
    friend std::ostream &operator<<(std::ostream &os, const Vecteur2D &u);
};

inline std::ostream &operator<<(std::ostream &os, const Vecteur2D &u)
{
    return os << u.toString();
}