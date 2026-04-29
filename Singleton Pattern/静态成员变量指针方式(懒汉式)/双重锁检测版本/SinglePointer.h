#pragma once

#include <iostream>
#include <mutex>

class SinglePointer
{
private:
	SinglePointer() {}
	SinglePointer(const SinglePointer& other) = delete;
	SinglePointer& operator=(const SinglePointer& other) = delete;

public:
	~SinglePointer()
	{
		std::cout << "SinglePointer Destructed" << std::endl;
	}

	//双重锁检测，但可能造成严重初始化错误
	//new分为三步：
	//1. calloc 开辟空间
	//2. 调用构造函数
	//3. 将构造好的对象赋值给single
	//
	//由于编译器可能调换2、3步的顺序，即：
	//1. calloc 开辟空间
	//2. 将开辟的空间地址给到single
	//3. 之后采取构造空间的内容
	//
	//所以，其他线程可能返回构造空间好的但没有来得及构造内容的single
	//会造成 1.数据混乱 2.core dump
	static SinglePointer* GetInst()
	{
		if (single != nullptr) return single;
		
		s_mutex.lock();
		if (single != nullptr)//加锁的时候可能其他线程已经初始化好了
		{
			s_mutex.unlock();
			return single;
		}

		single = new SinglePointer();
		s_mutex.unlock();
		return single;
	}

private:
	static SinglePointer* single;
	static std::mutex s_mutex;

};
