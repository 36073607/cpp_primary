#pragma once

#include <iostream>
#include <string>
#include <type_traits>

//通用类模板
template <typename T,typename Enable = void>
class Logger
{
public:
	static void log(const T& value)
	{
		std::cout << "General Logger: " << value << std::endl;
	}
};

// 类模板偏特化：当 T 是指针类型
template<typename T>
class Logger < T, typename std::enable_if<std::is_pointer<T>::value, void>::type>
{
public:
	static void log(T value)//在这里，T 本身已经是一个指针类型了，而按值传递指针是非常廉价且安全的，使用引用反而没有好处，甚至会降低可读性。
	{
		if (value)
			std::cout << "Pointer Logger: " << *value << std::endl;
		else
			std::cout << "Pointer Logger: nullptr" << std::endl;
	}
};

// 类模板全特化：当 T 是 std::string
template<>
class Logger<std::string>
{
public:
	static void log(const std::string& value)
	{
		std::cout << "String Logger: \"" << value << "\"" << std::endl;
	}
};

// 函数模板，用于递归调用 Logger::log
template<typename T>
void logOne(const T& value)
{
	Logger<T>::log(value);
}

// 使用模板折叠表达式实现多参数日志记录
template<typename... Args>
void logAll(const Args&... args)
{
	(logOne(args), ...);//右折叠
}

