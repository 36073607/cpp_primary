#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>

//1.普通函数
int add(int a, int b)
{
	return a + b;
}

//2.仿函数(Functors)
struct Multiply
{
	int operator()(int a, int b) const
	{
		return a * b;
	}
};

//3.Lambda表达式
auto subtract = [](int a, int b) {
	return a - b;
};

//4.类定义
class Calculator
{
public:
	int subtract(int a, int b) const
	{
		return a - b;
	}

	void displayOperation(const std::string& op, int result) const
	{
		std::cout << op << "结果：" << result << std::endl;
	}
};

//5.静态成员函数
class Logger
{
public:
	static void log(const std::string& message)
	{
		std::cout << "Log: " << message << std::endl;
	}
};

int main()
{
	// 1. 函数指针
	int (*funcPtr)(int, int) = &add;
	std::cout << "Add (Function Pointer): " << funcPtr(10, 5) << std::endl;

	// 2. 仿函数（Functors）
	Multiply multiply;
	std::cout << "Multiply (Functors): " << multiply(10, 5) << std::endl;

	// 3. Lambda表达式
	std::cout << "Subtract (Lambda): " << subtract(10, 5) << std::endl;

	// 4. std::function 封装不同可调用对象
	std::function<int(int, int)> funcAdd = add;
	std::function<int(int, int)> funcMultiply = multiply;
	std::function<int(int, int)> funcSubtract = subtract;

	std::cout << "Add (std::function): " << funcAdd(20, 10) << std::endl; 
	std::cout << "Subtract (std::function): " << funcSubtract(20, 4) << std::endl;
	std::cout << "Multiply (std::function): " << funcMultiply(4, 5) << std::endl; 

	// 5. std::bind 绑定部分参数
	auto add_bind = std::bind(add, 5, std::placeholders::_1);
	auto multiply_bind = std::bind(multiply, 2, std::placeholders::_1);
	std::cout << "5 + 10 = " << add_bind(10) << std::endl;
	std::cout << "2 * 10 = " << multiply_bind(10) << std::endl;

	// 6. 绑定类成员函数
	Calculator calc;
	// 使用 std::bind 绑定成员函数 subtract
	auto boundSubtract = std::bind(&Calculator::subtract, &calc, 15, 5);
	std::cout << "15 - 5 = " << boundSubtract() << std::endl;
	// 使用 std::bind 绑定成员函数 displayOperation
	auto boundDisplayOperation = std::bind(&Calculator::displayOperation, &calc, "Add", std::placeholders::_1);
	boundDisplayOperation(funcAdd(7, 8));
	std::cout << std::endl;

	// 7. 绑定静态成员函数
	auto logFunc = std::bind(&Logger::log, std::placeholders::_1);
	logFunc("This is a static log message.");

	// 8. 使用 std::function 存储混合可调用对象
	std::vector<std::function<void()>> operations;
	operations.emplace_back([&]() {std::cout << "Lambda Opperations" << std::endl; });
	operations.emplace_back(std::bind(&Calculator::displayOperation, calc, "Multiply", 30));
	operations.emplace_back([&]() {std::cout << multiply(10, 2) << std::endl; });
	operations.emplace_back([]() {Logger::log("Lambda-based log message."); });

	for (auto& ele : operations)
		ele();


	return 0;
}