#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"

int main()
{
    int a = 10;
    double b = 3.14;
    std::string s = "Hello, World!";
    int* ptr = &a;
    double* pNull = nullptr;

    // 使用 Logger 类模板进行特化打印
    Logger<int>::log(a);          // 输出：General Logger: 10
    Logger<double*>::log(pNull);  // 输出：Pointer Logger: nullptr
    Logger<std::string>::log(s);  // 输出：String Logger: "Hello, World!"

    std::cout << "\nLogging multiple parameters:" << std::endl;
    logAll(a, b, s, ptr, pNull);

	return 0;
}