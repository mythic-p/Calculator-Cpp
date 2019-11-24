#include "Calculator.h"

Calculator::Calculator(const char* toCalculateStr)
{
	calcStr = toCalculateStr;
}

int Calculator::calculate()
{
	
}

std::string Calculator::infixToPostfix(const char* infixStr)
{
	int len = strlen(infixStr);
	int num = 0, digit = 0;
	std::string resultStr;
	std::stack<char> tmpStack;
	for (int i = 0; i < len; i++)
	{
		if (isNumber(infixStr[i]))
		{
			num += (infixStr[i] - '0') * pow(10, digit++);
		}
		else if (isSpace(infixStr[i]))
		{
			if (num != 0)
			{
				char tmp[20];
				tmp = itoa(num, tmp, 10);
				resultStr.append(tmp);
				num = 0;
			}
		}
		else if (isOperator(infixStr[i]))
		{
			switch (infixStr[i])
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
				case '%':
					if (tmpStack.size() > 0)
					{
						int priCurOp = getPriority(infixStr[i]), priTopOp = getPriority(tmpStack.top());
						
					}
					else
					{
						tmpStack.push(infixStr[i]);
					}
			}
		}
	}
}

int Calculator::getPriority(char c)
{
	switch (c)
	{
		case '^':
			return 3;
		case '*':
		case '/':
		case '%':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

bool Calculator::isNumber(char c)
{
	return (c >= '0' && c <= '9');
}

bool Calculator::isOperator(char c)
{
	switch (c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
		case '(':
		case ')':
			return true;
		default:
			return false;
	}
}

bool Calculator::isSpace(char c)
{
	return c == ' ';
}
