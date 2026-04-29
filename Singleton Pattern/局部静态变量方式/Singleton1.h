#pragma once

#include <iostream>

class Single
{
private:
	Single(){}
	Single(const Single& other) = delete;
	Single& operator=(const Single& other) = delete;

public:
	~Single()
	{
		std::cout << "Single Destructed" << std::endl;
	}

	static Single& GetInst()
	{
		static Single single;
		return single;
	}
};
