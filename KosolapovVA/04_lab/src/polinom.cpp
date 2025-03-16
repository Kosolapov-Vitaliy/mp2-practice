#include "polinom.h"


bool check_Symb(char s) //
{
    return(s=='x'||s=='y'||s=='z');
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
    if (!(tmp_1.CheckKey(temp_degree)))
    {
        if(tmp_1.IsEmpty())
            tmp_1.PushBack(Monom(temp_coef, temp_degree), temp_degree);
        else
        {
            tmp_1.Reset();
            while ((!(tmp_1.Is_End()))) 
            {
                if (tmp_1.GetCurr().degree > temp_degree)
                {
                    tmp_1.PushBeforeCurr(Monom(temp_coef, temp_degree), temp_degree);
                    return;
                }
                tmp_1.Next();               
            }
            tmp_1.PushBack(Monom(temp_coef, temp_degree), temp_degree);
        }
    }        
    else if (tmp_1.CheckKey(temp_degree))
    {
        tmp_1.SearchKey(temp_degree);
        temp_coef += tmp_1.GetCurr().coef;       
        tmp_1.Next();
        tmp_1.PopBeforeCurr();
        tmp_1.PushBeforeCurr(Monom(temp_coef, temp_degree), temp_degree);
    }
}

void Check_start(int& l_symb, char str, double& temp_coef, char& l_var, std::string& tmp_2, int&sgn)
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
void Check_after_coef(int& l_symb, char str, std::string& tmp_2, double &temp_coef, int& temp_degree, RingList<Monom>&tmp_1, int&sgn)
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
            sgn=-1;
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


Polinom::Polinom(const std::string& str)
{
    RingList<Monom> tmp_1;
    int l_symb = -1;
    int flag;
    std::string tmp_2;
    double temp_coef=0;
    int temp_degree=0;
    char l_var;
    int sgn = 1;
    for (int i = 0; i < str.size(); i++)          
    {                                                   //-1 start  // 5 ^  
        flag = l_symb;                                  // 1 coef   // 6 symb         
        switch (flag)                                   // 2 oper   
        {                                               // 3 degree    
        case -1:      
            Check_start(l_symb,str[i],temp_coef, l_var, tmp_2, sgn);            
            break;
        case 1:
            Check_after_coef(l_symb, str[i], tmp_2, temp_coef, temp_degree, tmp_1, sgn);   
            break;
        case 2:
            Check_after_oper(l_symb, str[i], temp_coef, l_var, tmp_2);
            break;
        case 3:
            Check_after_degree(l_symb, str[i], temp_coef, temp_degree, tmp_1, sgn);            
            break;
        case 4:
            Check_after_mul(l_symb, str[i], l_var);
            break;
        case 5:
            Check_after_exp(l_symb, str[i], l_var, temp_degree);            
            break;
        case 6:
            Check_after_symb(l_symb, str[i], l_var, temp_coef, temp_degree, tmp_1, sgn);            
            break;
        }
        if (i == (str.size() - 1))
        {
            if (l_symb == -1)
                throw std::exception("Error: Empty infex form or empty after '('");
            if (l_symb == 2 || l_symb == 4 || l_symb == 5)
                throw std::exception("Incorrect infex form");
            if (l_symb == 1)
            {
                temp_coef = std::stod(tmp_2);
                tmp_2.clear();
                temp_degree = 0;
                Monom_to_list(temp_coef, temp_degree, tmp_1, sgn);
            }
            if (l_symb == 3)
            {
                Monom_to_list(temp_coef, temp_degree, tmp_1, sgn);
            }
            if (l_symb == 6)
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
            }
        }
        
    }        
    monom = tmp_1;
    set_str();
}

void Polinom::set_str()
{
    std::string res;
    RingList<Monom> temp(monom);
    monom.Reset();
    for (int i = 0; i < monom.GetSZ(); i++)
    {
        res += monom.GetCurr().Monom_to_str();
        monom.Next();
    }
    if (!res.empty()) {
        if (res[0] == '+') 
        {
            res.erase(0, 1);
        }

    }
    this->polinom = res;
}
Polinom Polinom::operator+(const Polinom& pol)
{
    Polinom res;
    RingList<Monom> tmp1(monom);
    RingList<Monom> tmp2(pol.monom);
    RingList<Monom> monoms;
    tmp1.Reset();
    while (!tmp1.Is_End())
    {
        int tmp_k = tmp1.CurrKey();
        if (tmp2.CheckKey(tmp_k))
        {
            tmp2.SearchKey(tmp_k);
            double coef = tmp2.GetCurr().coef + tmp1.GetCurr().coef;
            if (coef != 0)
                Monom_to_list(coef, tmp_k, monoms, 1);
            tmp2.Next();
            tmp2.PopBeforeCurr();
        }
        else if (!(tmp2.CheckKey(tmp_k)))
        {
            double coef =  tmp1.GetCurr().coef;
            Monom_to_list(coef, tmp_k, monoms, 1);
        }
        tmp1.Next();
    }    
    tmp2.Reset();
    while (!tmp2.Is_End())
    {
        int tmp_k = tmp2.CurrKey();
        double coef = tmp2.GetCurr().coef;
        Monom_to_list(coef, tmp_k, monoms, 1);
        tmp2.Next();
    }
    res.monom = monoms;
    res.set_str();
    return res;
}
Polinom Polinom::operator-(const Polinom& pol)
{
    Polinom res;
    RingList<Monom> tmp1(monom);
    RingList<Monom> tmp2(pol.monom);
    RingList<Monom> monoms;
    tmp1.Reset();
    while (!tmp1.Is_End())
    {
        int tmp_k = tmp1.CurrKey();
        if (tmp2.CheckKey(tmp_k))
        {
            tmp2.SearchKey(tmp_k);
            double coef = tmp1.GetCurr().coef - tmp2.GetCurr().coef;
            if(coef!=0)
                Monom_to_list(coef, tmp_k, monoms, 1);
            tmp2.Next();
            tmp2.PopBeforeCurr();
        }
        else if (!(tmp2.CheckKey(tmp_k)))
        {
            double coef = tmp1.GetCurr().coef;
            Monom_to_list(coef, tmp_k, monoms, 1);
        }
        tmp1.Next();
    }
    tmp2.Reset();
    while (!tmp2.Is_End())
    {
        int tmp_k = tmp2.CurrKey();
        double coef = tmp2.GetCurr().coef; 
        Monom_to_list(coef, tmp_k, monoms, -1);
        tmp2.Next();
    }
    res.monom = monoms;
    res.set_str();
    return res;
}
Polinom Polinom::operator*(const Polinom& pol)
{
    Polinom res;
    RingList<Monom> tmp1(monom);
    RingList<Monom> tmp2(pol.monom);
    RingList<Monom> monoms;
    tmp1.Reset();
    while (!tmp1.Is_End())
    {
        tmp2.Reset();
        while (!tmp2.Is_End())
        {
            Monom temp_res = tmp1.GetCurr()* tmp2.GetCurr();
            if (monoms.CheckKey(temp_res.degree))
            {
                monoms.SearchKey(temp_res.degree);
                temp_res =temp_res + monoms.GetCurr();
                monoms.Next();
                monoms.PopBeforeCurr();
            }
            Monom_to_list(temp_res.coef, temp_res.degree, monoms, 1);
            tmp2.Next();
        }
        tmp1.Next();
    }
    res.monom = monoms;
    res.set_str();
    return res;
}

Polinom Polinom::operator+(double c)
{
    Polinom res;
    RingList<Monom> tmp1(monom);
    Monom tres(c,0);
    if (tmp1.CheckKey(0))
    {
        tmp1.SearchKey(0);
        tres = tres + tmp1.GetCurr();
        tmp1.Next();
        tmp1.PopBeforeCurr();
    }
    tmp1.PushFront(tres, 000);
    res.monom = tmp1;
    res.set_str();
    return res;
}
Polinom Polinom::operator-(double c)
{
    Polinom res;
    RingList<Monom> tmp1(monom);
    Monom tres(-c, 0);
    if (tmp1.CheckKey(0))
    {
        tmp1.SearchKey(0);
        tres = tres + tmp1.GetCurr();
        tmp1.Next();
        tmp1.PopBeforeCurr();
    }
    tmp1.PushFront(tres, 000);
    res.monom = tmp1;
    res.set_str();
    return res;
}
Polinom Polinom::operator*(double c)
{
    Polinom res; 
    RingList<Monom> tmp1(monom);
    tmp1.Reset();
    RingList<Monom> monoms;
    while (!tmp1.Is_End())
    {
        monoms.PushBack(tmp1.GetCurr() * c, tmp1.CurrKey());
        tmp1.Next();
    }
    res.monom = monoms;
    res.set_str();
    return res;
}

bool Polinom::operator==(const Polinom& pol) const
{
    RingList<Monom> tmp1(pol.monom);
    RingList<Monom> tmp2(monom);
    if (tmp1.GetSZ() != tmp1.GetSZ())
        return 0;
    tmp1.Reset();
    for (int i = 0; i < tmp1.GetSZ(); i++)
    {        
        tmp2.SearchKey(tmp1.GetCurr().degree);
        if (tmp2.GetCurr() != tmp1.GetCurr())
            return 0;
        tmp1.Next();
    }
    return 1;
}
bool Polinom::operator!=(const Polinom& pol) const
{
    return(!(Polinom::operator==(pol)));
}
double Polinom::Calculate(double x, double y, double z)
{
    RingList<Monom> tmp1(monom);
    double res = 0;
    tmp1.Reset();
    for (int i = 0; i < tmp1.GetSZ(); i++)
    {
        res += tmp1.GetCurr().Calculate(x, y, z);
        tmp1.Next();
    }
    return res;
}