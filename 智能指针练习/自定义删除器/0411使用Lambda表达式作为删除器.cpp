#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <cstdio>

int main()
{
	{
		auto fileDeleter = [](FILE* fp) {
			if (fp)
			{
				std::cout << "Closing file via lambda." << std::endl;
				fclose(fp);
			}
			};

		std::unique_ptr<FILE, decltype(fileDeleter)> filePtr(fopen("example2.txt", "w"), fileDeleter);
		if (filePtr)
		{
			std::cout << "File opened successfully." << std::endl;
			fprintf(filePtr.get(), "Hello, Lambda!\n");
		}
	}//自动关闭文件

	std::cout << "Exiting main..." << std::endl;

	return 0;
}