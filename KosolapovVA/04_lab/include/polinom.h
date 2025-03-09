#ifndef POLINOM_H
#define POLINOM_H

#include "ringlist.h"
#include "monom.h"
#include <string>
class Polinom
{
private:
	RingList<Monom> monom;
	std::string polinom;
public:
    Polinom()
    {
        monom = RingList<Monom>();
    };
	Polinom(const std::string& str);
	Polinom(const Polinom& pol) :monom(pol.monom), polinom(pol.polinom){};

    void set_str();
    double Calculate(double x, double y, double z);

    Polinom operator+(const Polinom& p);
    Polinom operator-(const Polinom& p);
    Polinom operator*(const Polinom& p);

    Polinom operator+(double c);
    Polinom operator-(double c);
    Polinom operator*(double c);

    bool operator==(const Polinom& p) const;
    bool operator!=(const Polinom& p) const;

    friend std::ostream& operator<<(std::ostream& out, Polinom& pol)
    {
        out << pol.polinom;
        return out;
    };
    friend std::istream& operator>>(std::istream& in, Polinom& pol)
    {
        std::string instr;
        in >> instr;
        pol = Polinom(instr);
        return in;
    };
};

#endif // !POLINOM_H
