#include "ringlist.h"
#include "polinom.h"
#include "headlist.h"

void main()
{
    std::string ina = "2*x+y";
    std::string inb = "2*y+z";
    std::string res = "4*x*y+2*x*z+2*y^2+y*z";
    Polinom a(ina);
    Polinom b(inb);
    Polinom result(res);
    Polinom fil = a * b;
    std::cout <<a<<"\n" << fil << "\n" << result << "\n";    
}