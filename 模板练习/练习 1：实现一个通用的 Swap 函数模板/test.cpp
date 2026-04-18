#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "swap_template.h"

int main()
{
	int a = 3, b = 5;
	swapValues(a, b);
	std::cout << a << " " << b << std::endl;

	double x = 4.5, y = 9.6;
	swapValues(x, y);
	std::cout << x << " " << y << std::endl;

	std::string s1 = "abc", s2 = "rfg";
	swapValues(s1, s2);
	std::cout << s1 << " " << s2 << std::endl;

	return 0;
}