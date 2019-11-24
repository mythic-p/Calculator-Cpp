#include "Calculator.h"

Calculator::Calculator(const char* toCalculateStr)
{
	calcStr = toCalculateStr;
}

int Calculator::calculate()
{
	infixToPostfix(calcStr);
	int num = 0;
	while (postfixQueue.size() > 0)
	{
		std::string str = postfixQueue.front();
		postfixQueue.pop();
		char c = str.c_str()[0];
		if (isNumber(c))
		{
			numStack.push(atoi(str.c_str()));
		}
		else
		{
			int num1 = numStack.top();
			numStack.pop();
			int num2 = numStack.top();
			numStack.pop();
			int tmpNum;
			switch (c)
			{
				case '+':
					tmpNum = num2 + num1;
					break;
				case '-':
					tmpNum = num2 - num1;
					break;
				case '*':
					tmpNum = num2 * num1;
					break;
				case '/':
					tmpNum = num2 / num1;
					break;
				case '%':
					tmpNum = num2 % num1;
					break;
				case '^':
					tmpNum = pow(num2, num1);
					break;
			}
			numStack.push(tmpNum);
		}
	}
	if (numStack.size() == 1)
	{
		num = numStack.top();
		numStack.pop();
	}
	return num;
}

void Calculator::infixToPostfix(const char* infixStr)
{
	int len = strlen(infixStr);
	std::string num;
	std::stack<char> tmpStack;
	for (int i = 0; i < len; i++)
	{
		if (isNumber(infixStr[i]))
		{
			num.append(std::string(1, infixStr[i]));
		}
		else if (isSpace(infixStr[i]))
		{
			if (num != "")
			{
				postfixQueue.push(num);
				num.clear();
			}
		}
		else if (isOperator(infixStr[i]))
		{
			if (num != "")
			{
				postfixQueue.push(num);
				num.clear();
			}
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
						if (priCurOp >= priTopOp || tmpStack.top() == '(')
						{
							tmpStack.push(infixStr[i]);
						}
						else
						{
							postfixQueue.push(std::string(1, tmpStack.top()));
							tmpStack.pop();
							if (tmpStack.size() == 0)
							{
								tmpStack.push(infixStr[i]);
							}
							else
							{
								while (tmpStack.size() > 0)
								{
									priTopOp = getPriority(tmpStack.top());
									if (priCurOp >= priTopOp || tmpStack.top() == '(')
									{
										tmpStack.push(infixStr[i]);
										break;
									}
									else
									{
										postfixQueue.push(std::string(1, tmpStack.top()));
										tmpStack.pop();
									}
								}
							}
						}
					}
					else
					{
						tmpStack.push(infixStr[i]);
					}
					break;
				case '(':
					tmpStack.push(infixStr[i]);
					break;
				case ')':
					if (num != "")
					{
						postfixQueue.push(num);
						num.clear();
					}
					while (tmpStack.size() > 0)
					{
						char top = tmpStack.top();
						tmpStack.pop();
						if (top != '(')
						{
							postfixQueue.push(std::string(1, top));
						}
						else
						{
							break;
						}
					}
					break;
			}
		}
		else if (infixStr[i] == '#')
		{
			if (num != "")
			{
				postfixQueue.push(num);
				num.clear();
			}
		}
	}
	while (tmpStack.size() > 0)
	{
		postfixQueue.push(std::string(1, tmpStack.top()));
		tmpStack.pop();
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
