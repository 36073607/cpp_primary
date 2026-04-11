#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <cstdio>

struct FileDeleter
{
	void operator()(FILE* fp) const
	{
		if (fp)
		{
			std::cout << "Closing file." << std::endl;
			fclose(fp);
		}
	}
};

int main()
{
	{
		std::shared_ptr<FILE> filePtr(fopen("example1.txt", "w"), FileDeleter());
		if (filePtr)
		{
			std::cout << "File opened successfully." << std::endl;
			//使用filePtr操作文件
			fprintf(filePtr.get(), "Hello World\n");
		}
	}//自动关闭文件

	std::cout << "Exiting main..." << std::endl;

	return 0;
}