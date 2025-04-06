#ifndef MONOM_H
#define MONOM_H
#include <iostream>
#include <string>
struct Monom {
    double coef;
    int degree;
    Monom() :coef(0), degree(-1) {};
    Monom(double cf, int dg) :coef(cf)
    {
        if (dg >= 0 && dg <= 999)
            degree = dg;
        else
            throw std::exception("Incorrect degree");
    };
    Monom(const Monom& mon):coef(mon.coef), degree(mon.degree) {};
    std::string Monom_to_str() const;

    const Monom operator+(const Monom& p);
    const Monom operator-(const Monom& p);
    const Monom operator*(const Monom& p);
    const Monom operator*(double p) const;

    double operator()(double x, double y, double z) const;

    const Monom& operator=(const Monom& m);
    bool operator==(const Monom& m) const
    {
        return (coef == m.coef && degree == m.degree);
    }
    bool operator!=(const Monom& m) const
    {
        return(!(operator==(m)));
    }
    bool operator>=(const Monom& m) const;
    bool operator<=(const Monom& m) const;
    bool operator>(const Monom& m) const;
    bool operator<(const Monom& m) const;
};

#endif // !MONOM_H
