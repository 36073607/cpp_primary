#pragma once

#include <iostream>
#include <memory>
#include <mutex>

class SingleOnceFlag_sptr
{
private:
	SingleOnceFlag_sptr() {}
	SingleOnceFlag_sptr(const SingleOnceFlag_sptr& other) = delete;
	SingleOnceFlag_sptr& operator=(const SingleOnceFlag_sptr& other) = delete;
	static std::shared_ptr<SingleOnceFlag_sptr> _instance;

public:
	~SingleOnceFlag_sptr()
	{
		std::cout << "SingleOnceFlag_sptr Destructed" << std::endl;
	}

	static std::shared_ptr<SingleOnceFlag_sptr> GetInst() {
		static std::once_flag flag;
		std::call_once(flag, []() {
			// 修改这里：不再使用 make_shared，而是直接使用 new
			// 因为静态成员函数内部可以访问 private 构造函数
			// 而std::make_shared 是一个外部的模板函数，它不是你类的成员函数，也没有被声明为类的友元（friend），
			// 因此它没有权限调用你的私有构造函数 SingleOnceFlag_sptr()。
			_instance = std::shared_ptr<SingleOnceFlag_sptr>(new SingleOnceFlag_sptr());
			});

		return _instance;
	}

};