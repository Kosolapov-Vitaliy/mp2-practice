#include "polinom.h"

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
                throw std::exception("Error: Empty string");
            if (l_symb == 2 || l_symb == 4 || l_symb == 5)
                throw std::exception("Incorrect polinom form");
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
    polinom = str;
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
    RingList<Monom> tmp1(pol.monom);
    Polinom res(*this);
    tmp1.Reset();
    while (!tmp1.Is_End())
    {
        res = res + tmp1.GetCurr();
        tmp1.Next();
    }       
    res.set_str();
    return res;
}
Polinom Polinom::operator-(const Polinom& pol)
{
    RingList<Monom> tmp1(pol.monom);
    Polinom res(*this);
    tmp1.Reset();
    while (!tmp1.Is_End())
    {
        res = res - tmp1.GetCurr();
        tmp1.Next();
    }
    res.set_str();
    return res;
}
Polinom Polinom::operator*(const Polinom& pol)
{
    Polinom tmp(*this);
    Polinom res;
    RingList<Monom> tmp1(pol.monom);
    tmp1.Reset();
    while (!tmp1.Is_End())
    {
        res = res+(tmp * tmp1.GetCurr());
        tmp1.Next();
    }
    res.set_str();
    return res;
}


Polinom Polinom::operator+(const Monom& m)
{
    Polinom res;
    RingList<Monom> monoms(monom);
    int tmp_k = m.degree;
    if (monoms.SearchKey(m.degree)!=nullptr)
    {
        monoms.SearchKey(m.degree);
        Monom mres = monoms.GetCurr() + m;
        monoms.Next();
        int key_ac=monoms.GetCurr().degree;
        monoms.Remove(mres.degree);
        if (mres.coef != 0)
        {
            if (key_ac != -1)
                monoms.PushBeforeKey(mres, mres.degree, key_ac);
            else
                monoms.PushBack(mres, mres.degree);
        }            
    }
    else
    {
        double coef = m.coef;
        Monom_to_list(coef, tmp_k, monoms, 1);
    }
    res.monom = monoms;
    res.set_str();
    return res;
}
Polinom Polinom::operator-(const Monom& m)
{
    Polinom res;
    RingList<Monom> monoms(monom);
    int tmp_k = m.degree;
    if (monoms.SearchKey(m.degree) != nullptr)
    {
        monoms.SearchKey(m.degree);
        Monom mres = monoms.GetCurr() - m; 
        monoms.Next();
        int key_ac = monoms.GetCurr().degree;
        monoms.Remove(mres.degree);
        if (mres.coef != 0)
        {
            if (key_ac != -1)
                monoms.PushBeforeKey(mres, mres.degree, key_ac);
            else
                monoms.PushBack(mres, mres.degree);
        }
    }
    else
    {
        double coef = m.coef;
        Monom_to_list(coef, tmp_k, monoms, -1);
    }
    res.monom = monoms;
    res.set_str();
    return res;
}
Polinom Polinom::operator*(const Monom& m)
{
    Polinom res;
    RingList<Monom> tmp1(monom);
    tmp1.Reset();
    RingList<Monom> monoms;
    while (!tmp1.Is_End())
    {
        Monom tmp_m = tmp1.GetCurr() * m;
        monoms.PushBack(tmp_m, tmp_m.degree);
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
    if (tmp1.SearchKey(0)!=nullptr)
    {
        tmp1.SearchKey(0);
        tres = tres + tmp1.GetCurr();
        tmp1.Remove(0);
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
    if (tmp1.SearchKey(0) != nullptr)
    {
        tmp1.SearchKey(0);
        tres = tres + tmp1.GetCurr();
        tmp1.Remove(0);
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
        monoms.PushBack(tmp1.GetCurr() * c, tmp1.GetCurr().degree);
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
double Polinom::operator()(double x, double y, double z)
{
    RingList<Monom> tmp1(monom);
    double res = 0;
    tmp1.Reset();
    for (int i = 0; i < tmp1.GetSZ(); i++)
    {
        res += tmp1.GetCurr()(x, y, z);
        tmp1.Next();
    }
    return res;
}