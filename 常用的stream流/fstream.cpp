#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// 创建一个 fstream 对象，并以读写模式打开文件 "data.txt"
	std::fstream file("data.txt", std::ios::in | std::ios::out | std::ios::app);

	// 检查文件是否成功打开
	if (!file) {
		std::cerr << "无法打开文件进行读写" << std::endl;
		return 1;
	}

	// 向文件追加一条新内容
	file << "追加的一条内容。\n";

	// 把读取指针拉回开头，然后从头开始读文件里的内容
	file.seekg(0, std::ios::beg);

	std::string line;
	std::cout << "文件内容如下：" << std::endl;

	//读取文件内容并书橱
	while (getline(file, line)) {
		std::cout << line << std::endl;
	}

	file.close();

	return 0;
}