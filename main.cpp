#include <iostream>
#include "Calculator.h"
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	std::string str;
	std::cout << "Input an infix expression: ";
	std::getline(std::cin, str);
	str.append("#");
	Calculator calculator(str.c_str());
	std::cout << "Result is: " << calculator.calculate();
	return 0;
}
