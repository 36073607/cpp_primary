#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <type_traits>

template<typename T>
void display_type(T&& param)
{
	std::cout << "Type of T: "
		<< (std::is_lvalue_reference<T>::value ? "lvalue reference" : "rvalue reference")
		<< ","
		<< (std::is_integral<typename std::remove_reference<T>::type>::value ? "Integral" : "Non-Integral")
		<< std::endl;
}

int main() 
{
    int x = 10;
    const int& y = x;
    display_type(x);            // T被推导为 int&
    display_type(20);           // T被推导为 int&&
    display_type(y);            // T被推导为 const int&
    display_type(std::move(x)); // T被推导为 int&&

    return 0;
}