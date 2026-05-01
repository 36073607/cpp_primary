#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <string>

int main() {
	// 使用 std::istringstream 读取数据
	std::string ipt = "2023 Bob 75.5";
	int year;
	std::string name;
	double score;

	std::istringstream iss(ipt);
	iss >> year >> name >> score;
	std::cout << "Parsed Data:" << std::endl;
	std::cout << "Year: " << year << ", Name: " << name << ", Score: " << score << std::endl;



	// 使用 std::ostringstream 构建字符串
	std::ostringstream oss;
	oss << "Year: " << year << ", Name: " << name << ", Score: " << score << std::endl;
	std::string output = oss.str();
	std::cout << "Formatted String: " << output << std::endl;

	return 0;
}