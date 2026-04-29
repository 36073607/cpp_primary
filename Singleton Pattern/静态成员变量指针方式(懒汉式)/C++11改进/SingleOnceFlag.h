#pragma once

#include <iostream>

class SingleOnceFlag
{
private:
	SingleOnceFlag(){}
	SingleOnceFlag(const SingleOnceFlag& other) = delete;
	SingleOnceFlag& operator=(const SingleOnceFlag& other) = delete;
	static SingleOnceFlag* _instance;

public:
	~SingleOnceFlag() {
		std::cout << "SingleOnceFlag Destructed" << std::endl;
	}

	static SingleOnceFlag* GetInst() {
		static std::once_flag flag;
		std::call_once(flag, []() {
			_instance = new SingleOnceFlag();
			});

		return _instance;
	}

};