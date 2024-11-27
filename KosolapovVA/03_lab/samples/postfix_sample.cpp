#include "postfix_form.h"


int main()
{
    try
    {
        std::cout << "Enter the expression: ";
        std::string inf;
        std::cin >> inf;
        std::map<std::string, double> variety;
        ArrStack<std::string> post(1);
        post = InfToPost(inf);
        GetValue(variety, post);
        double res = Counting(variety, post);
        std::cout << inf << "=" << res;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
    return 0;
}
