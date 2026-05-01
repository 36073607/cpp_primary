#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <sstream>
#include <string>

int main() {
	std::string csvData = "John,25,80.5";
	std::string name;
	int age;
	double score;

	std::stringstream ss(csvData);
	std::getline(ss, name, ',');// 使用逗号作为分隔符
	ss >> age;
	ss.ignore(1);//忽略 25 后面的 ','
	ss >> score;

	std::cout << "Name: " << name << " Age: " << age << " Score: " << score << std::endl;

	return 0;
}