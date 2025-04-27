#pragma once
#ifndef POLINOM_HELPFUNC
#define POLINOM_HELPFUNC

#include "ringlist.h"
#include "monom.h"
#include <string>

bool check_Symb(char s);
bool check_Numb(char s);
bool check_Oper(char s);

void Monom_to_list(double& temp_coef, int& temp_degree, RingList<Monom>& tmp_1, int sgn);

void Check_start(int& l_symb, char str, double& temp_coef, char& l_var, std::string& tmp_2, int& sgn);
void Check_after_coef(int& l_symb, char str, std::string& tmp_2, double& temp_coef, int& temp_degree, RingList<Monom>& tmp_1, int& sgn);
void Check_after_oper(int& l_symb, char str, double& temp_coef, char& l_var, std::string& tmp_2);
void Check_after_degree(int& l_symb, char str, double& temp_coef, int& temp_degree, RingList<Monom>& tmp_1, int& sgn);
void Check_after_mul(int& l_symb, char str, char& l_var);
void Check_after_exp(int& l_symb, char str, char& l_var, int& temp_degree);
void Check_after_symb(int& l_symb, char str, char& l_var, double& temp_coef, int& temp_degree, RingList<Monom>& tmp_1, int& sgn);
#endif // !POLINOM_HELPFUNC
