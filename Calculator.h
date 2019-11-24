#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

class Calculator
{
	public:
		Calculator(const char* toCalculateStr);
		int calculate();
	protected:
		
	private:
		std::string infixToPostfix(const char* infixStr);
		int getPriority(char c);
		bool isNumber(char c);
		bool isOperator(char c);
		bool isSpace(char c);
	private:
		const char* calcStr;
		std::stack<double> numStack;
		std::stack<std::string> postfixStack;
};

#endif
