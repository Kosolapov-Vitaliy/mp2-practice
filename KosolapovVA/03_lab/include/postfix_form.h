#ifndef Postfix_form_H
#define Postfix_form_H

#include "stack.h"
#include <map>



ArrStack<std::string> InfToPost(std::string inf);
bool check_Symb(char s);
bool check_Numb(char s);
bool check_Oper(char s);
void StackToStack(ArrStack<std::string> &s1, ArrStack<std::string> &s2);
void GetValue(std::map<std::string, double>& variety, ArrStack<std::string> temp);
double Counting(std::map<std::string, double>& variety, ArrStack<std::string>& temp);

#endif // !Postfix_form_H




