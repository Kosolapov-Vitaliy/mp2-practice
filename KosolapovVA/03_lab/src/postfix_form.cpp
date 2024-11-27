#include "postfix_form.h"

bool check_Symb(char s)
{
    std::string Symb = "QqWwEeRrTtYyUuIiOoPpAaSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm";
    for (int i = 0; i < Symb.length(); i++)
    {
        if (s == Symb[i])
            return 1;
    }
    return 0;
}

bool check_Numb(char s)
{
    std::string Numb = "1234567890";
    for (int i = 0; i < Numb.length(); i++)
    {
        if (s == Numb[i])
            return 1;
    }
    return 0;
}

bool check_Oper(char s)
{
    std::string Oper = "+-*/";
    for (int i = 0; i < Oper.length(); i++)
    {
        if (s == Oper[i])
            return 1;
    }
    return 0;
}

void StackToStack(ArrStack<std::string>& s1, ArrStack<std::string>& s2)
{
    while (!(s2.IsEmpty()))
    {
        s1.Push(s2.Top());
        s2.Pop();
    }
}

ArrStack<std::string> InfToPost(std::string inf)
{
    int l_symb = -1;
    ArrStack<std::string> stack_1(5);
    ArrStack<std::string> stack_2(5);
    std::map<char, int> priority = { { '+' , 1},{'-', 1},{'*', 2},{'/', 2},{'(',3}};
    std::map<std::string, int> priority_s = { { "+"  , 1},{"-", 1},{"*", 2},{"/", 2},{"(",3}};
    std::string var;
    int flag;
    for (int i = 0; i < inf.size(); i++)
    {
        flag = l_symb;
        switch (flag)
        {
        case -1:
            if (check_Oper(inf[i]))
                throw std::exception("Error");
            if (check_Numb(inf[i]))
            {
                l_symb = 3;
                var += inf[i];
            }
            if (check_Symb(inf[i]))
            {
                l_symb = 2;
                var += inf[i];
            }
            if (inf[i] == '(')
            {
                l_symb = 1;
                stack_2.Push("(");
            }
            if (inf[i] == ' ')
                l_symb = -1;
            break;
        case 1:
            if (check_Oper(inf[i]))
                throw std::exception("Error");
            if (check_Numb(inf[i]))
            {
                l_symb = 3;
                stack_2.Push(var);
                var.clear();
                var += inf[i];
            }
            if (check_Symb(inf[i]))
            {
                l_symb = 2;
                stack_2.Push(var);
                var.clear();
                var += inf[i];
            }
            if (inf[i] == '(')
            {
                l_symb = 1;
                stack_2.Push("(");
            }
            if (inf[i] == ' ')
                l_symb = 1;
            break;
        case 2:
            if (check_Oper(inf[i]))
            {
                l_symb = 1;
                stack_1.Push(var);
                if (!stack_2.IsEmpty())
                {
                    if (priority[inf[i]] < priority_s[stack_2.Top()])
                    {
                        while (priority[inf[i]] < priority_s[stack_2.Top()])
                        {
                            stack_1.Push(stack_2.Top());
                            stack_2.Pop();
                        }
                    }
                }
                var.clear();
                var += inf[i];
            }
            if (check_Symb(inf[i]))
            {
                l_symb = 2;
                var += inf[i];
            }
            if (check_Numb(inf[i]))
            {
                l_symb = 2;
                var += inf[i];
            }
            if (inf[i] == '(')
                throw std::exception("Error");
            if (inf[i] == ')')
            {
                while (!stack_2.IsEmpty())
                {
                    while (stack_2.Top() != "(")
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                }
                if (stack_2.IsEmpty())
                    throw std::exception("Error");
                if (stack_2.Top() == "(")
                    stack_2.Pop();
            }
            if (inf[i] == ' ')
                l_symb = 2;
            break;
        case 3:
            if (check_Oper(inf[i]))
            {
                l_symb = 1;
                stack_1.Push(var);
                if (!stack_2.IsEmpty())
                {
                    while (priority[inf[i]] < priority_s[stack_2.Top()])
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                }
                var.clear();
                var += inf[i];
            }
            if (check_Symb(inf[i]))
            {
                throw std::exception("Error");
            }
            if (check_Numb(inf[i]))
            {
                l_symb = 3;
                var += inf[i];
            }
            if (inf[i] == '(')
                throw std::exception("Error");
            if (inf[i] == ')')
            {
                while (!stack_2.IsEmpty())
                {
                    while (stack_2.Top() != "(")
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                }
                if (stack_2.IsEmpty())
                    throw std::exception("Error");
                if (stack_2.Top() == "(")
                    stack_2.Pop();
            }
            if (inf[i] == ' ')
                l_symb = 3;
            break;
        }
        if (i == inf.size() - 1)
        {
            if (l_symb == 2 || l_symb == 3)
            {
                stack_1.Push(var);
            }
        }
        
    }
    StackToStack(stack_1, stack_2);
    stack_1.Mirror_Stack();
    return stack_1;
}

void GetValue(std::map<std::string, double>& variety, ArrStack<std::string> temp)
{
    while (!(temp.IsEmpty()))
    {
        if (!(check_Oper(temp.Top()[0])))
        {
            if (variety.find(temp.Top()) == variety.end())
            {
                std::cout << "Enter value for " << temp.Top()<<": ";
                std::cin >> variety[temp.Top()];
            }
        }
        temp.Pop();
    }
}

double Counting(std::map<std::string, double>& variety, ArrStack<std::string>& temp)
{
    ArrStack<double> res(1);
    double a1, a2, a3;
    while (!(temp.IsEmpty()))
    {
        if (!check_Oper(temp.Top()[0]))
        {
            res.Push(variety[temp.Top()]);
            temp.Pop();
        }
        else
        {
            a2 = res.Top();
            res.Pop();
            a1 = res.Top();
            res.Pop();
            switch (temp.Top()[0])
            {
            case '+':
                a3 = a1 + a2;
                break;
            case '-':
                a3 = a1 - a2;
                break;
            case '*':
                a3 = a1 * a2;
                break;
            case '/':
                a3 = a1 / a2;
                break;
            }
            res.Push(a3);
            temp.Pop();
        }
    }
    return res.Top();
}