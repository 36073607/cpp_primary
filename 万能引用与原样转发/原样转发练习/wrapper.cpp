#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <utility>

void process(const std::string& s)
{
	std::cout << "Processing lvalue: " << s << std::endl;
}

void process(std::string&& s)
{
	std::cout << "Processing rvalue: " << s << std::endl;
}


template<typename T>
void wrapper(T&& arg)
{
	process(std::forward<T>(arg));
}

int main()
{
    std::string name = "Alice";
    wrapper(name);                     // 传递左值，调用process(const std::string&)
    wrapper("Bob");                    // 传递右值，调用process(std::string&&)
    wrapper(std::move(name));          // 传递右值，调用process(std::string&&)

    return 0;
}
