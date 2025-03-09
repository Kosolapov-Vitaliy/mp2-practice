#include "ringlist.h"
#include "polinom.h"
#include "headlist.h"

void main()
{
    try
    {
        std::cout << "Start workin polynoms.\n";
        int flag = 0;
        Polinom curr1;
        Polinom curr2;
        double temp_const;
        double res;
        double x, y, z;
        std::string instr;
        while (flag != -1)
        {
            switch (flag)
            {
            case 0:
                std::cout << "Enter 1st polynomial:\n";
                std::cin >> instr;
                std::cout << "\n";
                curr1 = Polinom(instr);
                std::cout << "Enter 2nd polynomial:\n"; 
                std::cin >> instr;
                std::cout << "\n";
                curr2 = Polinom(instr);
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add this polynomials\n"
                    << "2: if you want to substruct this polynomials\n" << "3: if you want to multiply this polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
                break;
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
               
                break;
            case 8:
                std::cout << "Cleaning...";
                std::cout << "";
                flag = 0;
                break;
            }

        }

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
}