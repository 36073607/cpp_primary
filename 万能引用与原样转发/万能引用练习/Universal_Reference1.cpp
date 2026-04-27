#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <type_traits>


template<typename T>
void deduce_type(T&&)
{
	std::cout << std::boolalpha;
	std::cout << "Is T an lvalue reference? " << std::is_lvalue_reference<T>::value << std::endl;
	std::cout << "Is T an rvalue reference? " << std::is_rvalue_reference<T>::value << std::endl;
}

int main()
{
	int a = 5;
	const int& ref = a;

	deduce_type(a);            // T被推导为 int&
	deduce_type(10);           // T被推导为 int
	deduce_type(ref);          // T被推导为 const int&
	deduce_type(std::move(a)); // T被推导为 int

	return 0;
}