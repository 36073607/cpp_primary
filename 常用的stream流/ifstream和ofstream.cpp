#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// 创建一个ofstream对象，并打开文件 "output.txt"
	std::ofstream outfile("output.txt");
	// 检查文件是否成功打开
	if (!outfile) {
		std::cerr << "无法打开文件进行写入" << std::endl;
		return 1;
	}

	//  向文件中写入数据
	outfile << "这是第一行。\n";
	outfile << "这是第二行，数字：" << 100 << std::endl;
	outfile << "浮点数：" << 3.14159 << std::endl;
	
	//关闭文件
	outfile.close();
	std::cout << "数据已成功写入 output.txt 文件。" << std::endl;


	// 创建一个ifstream对象，并打开文件 "output.txt"
	std::ifstream infile("output.txt");
	// 检查文件是否成功打开
	if (!infile) {
		std::cerr << "无法打开文件进行写入" << std::endl;
		return 1;
	}

	std::string line;
	//逐行读取文件内容
	while (std::getline(infile, line)) {
		std::cout << line << std::endl;
	}

	//关闭文件
	infile.close();


	return 0;
}