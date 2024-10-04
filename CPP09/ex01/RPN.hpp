

#ifndef RPN_HPP
#define RPN_HPP

#include "iostream"
#include <stack>

void calculate(std::stack<int>& stck, char symbol);
void clearAll(std::stack<int>& stck);
void reading(std::stack<int>& stck, std::string input);

#endif