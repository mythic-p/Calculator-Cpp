#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>

class Calculator
{
	public:
		Calculator(const char* toCalculateStr);
		int calculate();
	protected:
		
	private:
		void infixToPostfix(const char* infixStr);
		int getPriority(char c);
		bool isNumber(char c);
		bool isOperator(char c);
		bool isSpace(char c);
	private:
		const char* calcStr;
		std::stack<int> numStack;
		std::queue<std::string> postfixQueue;
};

#endif
