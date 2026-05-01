#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <string>

int main()
{
	int id = 19;
	std::string name = "zack";
	double score = 95.5;

	std::stringstream ss;
	ss << "ID: " << id << " Name: " << name << " Score: " << score;

	std::string result = ss.str();
	std::cout << result << std::endl;

	//清空stream流
	ss.clear();//清除流的“状态标志”，恢复为良好状态
	ss.str("");//真正清空流内部的缓冲区数据
	//缺一不可

	int num = 191;
	ss << num;
	std::cout << ss.str() << std::endl;

	std::cout << "*******************" << std::endl;

	std::string data = "2023 Tohn 87.4";
	int year;
	std::string name1;
	double grades;
	std::stringstream ss2(data);
	ss2 >> year >> name1 >> grades;

	std::cout << "Year: " << year << std::endl;
	std::cout << "Name: " << name1 << std::endl;
	std::cout << "Grade: " << grades << std::endl;

	return 0;
}