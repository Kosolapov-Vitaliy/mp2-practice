#include "ringlist.h"
#include "polinom.h"
#include "headlist.h"

void main()
{
    try
    {
        std::cout << "Start workin polynoms.\n";
        int flag = 0;
        Polinom curr;
        Polinom temp;
        double temp_const;
        double res;
        double x, y, z;
        std::string instr;
        while (flag != -1)
        {
            switch(flag)
            {
            case 0:
                std::cout << "Enter polynomial:\n";
                std::cin >> instr;
                std::cout << "\n";
                curr = Polinom(instr);
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add a polynomial\n"
                    << "2: if you want to substruct a polynomial\n" << "3: if you want to multiply a polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
                break;
            case 1:         
                std::cout << "Enter polynomial:\n";
                std::cin >> instr;
                std::cout << "\n";
                temp = Polinom(instr);
                curr = curr + temp;
                std::cout << "Result\n"<<curr;
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add a polynomial\n"
                    << "2: if you want to substruct a polynomial\n" << "3: if you want to multiply a polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
                break;
            case 2:
                std::cout << "Enter polynomial:\n";
                std::cin >> instr;
                std::cout << "\n";
                temp = Polinom(instr);
                curr = curr - temp;
                std::cout << "Result\n" << curr;
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add a polynomial\n"
                    << "2: if you want to substruct a polynomial\n" << "3: if you want to multiply a polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
                break;
            case 3:
                std::cout << "Enter polynomial:\n";
                std::cin >> instr;
                std::cout << "\n";
                temp = Polinom(instr);
                curr = curr * temp;
                std::cout << "Result\n" << curr;
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add a polynomial\n"
                    << "2: if you want to substruct a polynomial\n" << "3: if you want to multiply a polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
                break;
            case 4:
                std::cout << "Enter constant:\n";
                std::cin >> temp_const;
                std::cout << "\n";
                curr = curr + temp_const;
                std::cout << "Result\n" << curr;
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add a polynomial\n"
                    << "2: if you want to substruct a polynomial\n" << "3: if you want to multiply a polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
                break;
            case 5:
                std::cout << "Enter constant:\n";
                std::cin >> temp_const;
                std::cout << "\n";
                curr = curr - temp_const;
                std::cout << "Result\n" << curr;
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add a polynomial\n"
                    << "2: if you want to substruct a polynomial\n" << "3: if you want to multiply a polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
                break;
            case 6:
                std::cout << "Enter constant:\n";
                std::cin >> temp_const;
                std::cout << "\n";
                curr = curr * temp_const;
                std::cout << "Result\n" << curr;
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add a polynomial\n"
                    << "2: if you want to substruct a polynomial\n" << "3: if you want to multiply a polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
                break;
            case 7:
                std::cout << "Enter x:" << "\n";
                std::cin >> x ;
                std::cout << "\n";
                std::cout << "Enter y:" << "\n";
                std::cin >> y;
                std::cout << "\n";
                std::cout << "Enter z:" << "\n";
                std::cin >> z;
                std::cout << "\n";
                res = curr.Calculate(x, y, z);
                std::cout<<"Calculation result: " << res<<"\n";
                std::cout << "Choose what you want to do:\n" << "Enter:\n" << "1: if you want to add a polynomial\n"
                    << "2: if you want to substruct a polynomial\n" << "3: if you want to multiply a polynomial\n"
                    << "4: if you want to add a constant\n" << "5: if you want to substruct a constant\n"
                    << "6: if you want to multiply a constant\n" << "7: if you want to calculate the current polynomial\n"
                    << "8: if you want to clear the current polynomial\n" << "-1: if you want to finish\n";
                std::cout << "Enter your selection: ";
                std::cin >> flag;
                std::cout << "\n";
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