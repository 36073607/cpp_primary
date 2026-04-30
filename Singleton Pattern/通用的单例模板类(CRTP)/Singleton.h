#pragma once

#include <iostream>
#include <mutex>
#include <memory>

template<typename T>
class Singleton {
protected:
	Singleton() = default;
	Singleton(const Singleton<T>& other) = delete;
	Singleton& operator=(const Singleton<T>& other) = delete;
	static std::shared_ptr<T> _instance;

public:
	~Singleton() = default;

	static std::shared_ptr<T> GetInst() {
		static std::once_flag flag;
		std::call_once(flag, []() {
			_instance = std::shared_ptr<T>(new T());
			});
		return _instance;
	}
};

template<typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;



class SingleNet : public Singleton<SingleNet> {
	//SingleNet的构造是private,使用友元让基类可以访问派生类的构造函数
	friend class Singleton<SingleNet>;

private:
	SingleNet() = default;

public:
	~SingleNet() {
		std::cout << "SingleNet Destructed" << std::endl;
	}
};