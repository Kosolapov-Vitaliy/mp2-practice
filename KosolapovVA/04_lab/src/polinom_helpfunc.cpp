#include "polinom_helpfunc.h"
bool check_Symb(char s) //
{
    return(s == 'x' || s == 'y' || s == 'z');
}
bool check_Numb(char s)
{
    return(s >= 48 && s <= 57);
}
bool check_Oper(char s) //
{
    return (s == '+' || s == '-');
}

void Monom_to_list(double& temp_coef, int& temp_degree, RingList<Monom>& tmp_1, int sgn)
{
    temp_coef *= sgn;
    if (tmp_1.SearchKey(temp_degree) != nullptr)
    {
        //tmp_1.SearchKey(temp_degree);
        temp_coef += tmp_1.GetCurr().coef;
        tmp_1.Remove(temp_degree);
    }
    if (tmp_1.IsEmpty())
        tmp_1.PushBack(Monom(temp_coef, temp_degree), temp_degree);
    else if(!(tmp_1.IsEmpty()))
    {
        tmp_1.Reset();
        while ((!(tmp_1.Is_End())))
        {
            int curr_key = tmp_1.GetCurr().degree;
            if (curr_key > temp_degree)
            {
                tmp_1.PushBeforeKey(Monom(temp_coef, temp_degree), temp_degree, curr_key);
                return;
            }
            tmp_1.Next();
        }
        tmp_1.PushBack(Monom(temp_coef, temp_degree), temp_degree);
    }
}

void Check_start(int& l_symb, char str, double& temp_coef, char& l_var, std::string& tmp_2, int& sgn)
{
    if (check_Numb(str))
    {
        tmp_2 += str;
        l_symb = 1;
    }
    else if (check_Oper(str))
    {
        if (str == '-')
            sgn = -1;
        if (str == '+')
            sgn = 1;
        l_symb = 2;
    }
    else if (check_Symb(str))
    {
        temp_coef = 1;
        l_var = str;
        l_symb = 6;
    }
    else
        throw std::exception("Incorrect polinom form");
}
void Check_after_coef(int& l_symb, char str, std::string& tmp_2, double& temp_coef, int& temp_degree, RingList<Monom>& tmp_1, int& sgn)
{
    if (check_Numb(str))
    {
        tmp_2 += str;
        l_symb = 1;
    }
    else if (check_Oper(str))
    {
        temp_coef = std::stod(tmp_2);
        tmp_2.clear();
        temp_degree = 0;
        Monom_to_list(temp_coef, temp_degree, tmp_1, sgn);
        temp_coef = 0;
        temp_degree = 0;
        if (str == '-')
            tmp_2 += str;
        l_symb = 2;
    }
    else if (str == '*')
    {
        temp_coef = std::stod(tmp_2);
        tmp_2.clear();
        l_symb = 4;
    }
    else
        throw std::exception("Incorrect polinom form");
}
void Check_after_oper(int& l_symb, char str, double& temp_coef, char& l_var, std::string& tmp_2)
{
    if (check_Numb(str))
    {
        tmp_2 += str;
        l_symb = 1;
    }
    else if (check_Symb(str))
    {
        temp_coef = 1;
        l_var = str;
        l_symb = 6;
    }
    else
    {
        throw std::exception("Incorrect polinom form");
    }
}
void Check_after_degree(int& l_symb, char str, double& temp_coef, int& temp_degree, RingList<Monom>& tmp_1, int& sgn)
{
    if (check_Oper(str))
    {
        Monom_to_list(temp_coef, temp_degree, tmp_1, sgn);
        temp_coef = 0;
        temp_degree = 0;
        if (str == '-')
            sgn = -1;
        if (str == '+')
            sgn = 1;
        l_symb = 2;
    }
    else if (str == '*')
    {
        l_symb = 4;
    }
    else
        throw std::exception("Incorrect polinom form");
}
void Check_after_mul(int& l_symb, char str, char& l_var)
{
    if (check_Symb(str))
    {
        l_var = str;
        l_symb = 6;
    }
    else
        throw std::exception("Incorrect polinom form");
}
void Check_after_exp(int& l_symb, char str, char& l_var, int& temp_degree)
{
    if (check_Numb(str))
    {
        if (l_var == 'x')
        {
            int tmp_numb = std::atoi(&str);
            temp_degree += tmp_numb * 100;
        }
        if (l_var == 'y')
        {
            int tmp_numb = std::atoi(&str);
            temp_degree += tmp_numb * 10;
        }
        if (l_var == 'z')
        {
            int tmp_numb = std::atoi(&str);
            temp_degree += tmp_numb;
        }
        l_symb = 3;
    }
    else
        throw std::exception("Incorrect polinom form");
}
void Check_after_symb(int& l_symb, char str, char& l_var, double& temp_coef, int& temp_degree, RingList<Monom>& tmp_1, int& sgn)
{
    if (str == '^')
    {
        l_symb = 5;
    }
    else if (str == '*')
    {
        if (l_var == 'x')
        {
            temp_degree += 100;
        }
        if (l_var == 'y')
        {
            temp_degree += 10;
        }
        if (l_var == 'z')
        {
            temp_degree += 1;
        }
        l_symb = 4;
    }
    else if (check_Oper(str))
    {
        if (l_var == 'x')
        {
            temp_degree += 100;
        }
        if (l_var == 'y')
        {
            temp_degree += 10;
        }
        if (l_var == 'z')
        {
            temp_degree += 1;
        }
        Monom_to_list(temp_coef, temp_degree, tmp_1, sgn);
        temp_coef = 0;
        temp_degree = 0;
        if (str == '-')
            sgn = -1;
        if (str == '+')
            sgn = 1;
        l_symb = 2;
    }

    else
        throw std::exception("Incorrect polinom form");
 }
