#pragma once

#include <iostream>

class Single_hungry
{
private:
	Single_hungry(){}
	Single_hungry(const Single_hungry& other) = delete;
	Single_hungry& operator=(const Single_hungry& other) = delete;
	static Single_hungry* single;

public:
	~Single_hungry(){
		std::cout << "Single_hungry Destructed" << std::endl;
	}

	static Single_hungry* GetInst() {
		if (single == nullptr)
			single = new Single_hungry();
		return single;
	}
};
