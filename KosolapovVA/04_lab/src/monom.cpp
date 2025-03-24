#include "monom.h"
#include <sstream>

Monom Monom::operator+(const Monom& mon)
{
    if (degree == mon.degree) {
        return Monom(coef + mon.coef, degree);
    }
    else {
        throw std::exception("Diff degree");
    }
}
Monom Monom::operator-(const Monom& mon)
{
    if (degree == mon.degree) {
        return Monom(coef - mon.coef, degree);
    }
    else {
        throw std::exception("Diff degree");
    }
}
Monom Monom::operator*(const Monom& mon)
{
    int temp_x =degree/100+mon.degree/100;
    int temp_y = ((degree / 10) % 10) + ((mon.degree / 10) % 10);
    int temp_z=((degree%100)%10) + ((mon.degree % 100) % 10);
    if (temp_x > 9 || temp_y > 9 || temp_z > 9
        || temp_x < 0 || temp_y < 0 || temp_z < 0)
        throw std::exception("Incorrect degree");
    return Monom(coef * mon.coef, (temp_z + temp_y*10 + temp_x*100));
}

Monom Monom::operator*(double c)
{
    return Monom(coef * c, degree);
}


const Monom& Monom::operator=(const Monom& mon)
{
    coef = mon.coef;
    degree = mon.degree;
    return *this;
}

std::string Monom::Monom_to_str() {
    std::string res;
    if (coef > 0) {
        res += "+";
        std::ostringstream stream;
        stream << coef;
        if(coef==1 && degree==0)
            res += stream.str();
        if (coef != 1) {
            res += stream.str();
        }

    }
    else if (coef < 0) {

        std::ostringstream stream;
        stream << coef;
        if(coef==-1&&degree!=0)
            res += "-";        
        if (coef != -1) {
            res += stream.str();
        }
        if (coef == -1 && degree == 0)
            res += stream.str();
    }
    else {
        return "";
    }
    int tmp = degree;
    if (tmp / 100!=0) {

        if ((tmp / 100) == 1) {
            res += "x";
        }
        else 
        {
            std::string x_d = "x^";
            x_d += std::to_string(tmp / 100);
            res += x_d;
        }
    }
    if ((tmp/10)%10!=0) {

        if (((tmp / 10) % 10) == 1) {
            res += "y";
        }
        else {
            std::string y_d = "y^";
            y_d += std::to_string(((tmp / 10) % 10));
            res += y_d;
        }
    }
    if (tmp % 100%10!=0) {
        if ((tmp % 100%10) == 1) {
            res += "z";
        }
        else {
            std::string zd = "z^";
            zd += std::to_string( tmp % 100%10);
            res += zd;
        }
    }
    return res;
}

double Monom::operator()(double x, double y, double z)
{
    double res=coef;
    int tmp = degree;
    if (tmp / 100) {
        res *= pow(x, tmp / 100);
    }
    if ((tmp - 100 * (tmp / 100)) / 10) {
        res *= pow(y, ((tmp - 100 * (tmp / 100)) / 10));
    }
    if (tmp % 10) {
        res *= pow(z, tmp % 10);
    }
    return res;
}

bool Monom::operator>=(const Monom& m)
{
    return(degree >= m.degree);
}
bool Monom::operator<=(const Monom& m)
{
    return(degree <= m.degree);
}
bool Monom::operator>(const Monom& m)
{
    return(degree > m.degree);
}
bool Monom::operator<(const Monom& m)
{
    return(degree < m.degree);
}