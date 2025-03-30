#include "ringlist.h"
#include "polinom.h"
#include "headlist.h"

void main()
{
    std::string ina = "4*x^2*y*z^3+5*x^3*y*z^2-3*x*y^2+y*z^2-x^3*y";
    std::string inb = "10*x^3*y^3*z^3+4*x^2*y*z^3-2*x^3*y*z^2+x*y*z";
    Polinom a(ina);
    Polinom b(inb);
    Polinom fil = a - b;
    std::cout  << fil << "\n";   
}