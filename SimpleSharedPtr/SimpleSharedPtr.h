#pragma once

#ifndef __SimpleSharedPtr__
#define __SimpleSharedPtr__

//注：
//在 C++ 中，模板的实例化（Instantiation）是在编译阶段完成的，而不是链接阶段。
//编译器在处理模板时，有一个特殊机制：
// 它只有在看到模板被具体使用（比如传入了 Test 类型）时，才会根据模板定义去生成对应的真正代码（比如生成 SimpleSharedPtr<Test> 的类和函数）。

//将模板的实现全部移到头文件中（行业标准做法）

struct ControlBlock
{
	int ref_count;
	ControlBlock();
};

template <typename T>
class SimpleSharedPtr
{
private:
	T* ptr;
	ControlBlock* control;
	void release();

public:
	SimpleSharedPtr();
	explicit SimpleSharedPtr(T* p);
	~SimpleSharedPtr();
	SimpleSharedPtr(const SimpleSharedPtr& s);
	SimpleSharedPtr& operator=(const SimpleSharedPtr& s);
	SimpleSharedPtr(SimpleSharedPtr&& other) noexcept;
	SimpleSharedPtr& operator=(SimpleSharedPtr&& other) noexcept;
	T* operator ->() const;
	T& operator *() const;
	T* get() const;
	int use_count() const;
	void reset(T* p = nullptr);
};



ControlBlock::ControlBlock() : ref_count(1) {}

template <typename T>
void SimpleSharedPtr<T>::release()
{
	if (ptr)
	{
		--control->ref_count;
		if (control->ref_count == 0)
		{
			delete ptr;
			ptr = nullptr;
			delete control;
			control = nullptr;
		}
	}
}

template<typename T>
SimpleSharedPtr<T>::SimpleSharedPtr() :ptr(nullptr), control(nullptr) {}

template<typename T>
SimpleSharedPtr<T>::SimpleSharedPtr(T* p) : ptr(p)
{
	if (p)
		control = new ControlBlock;
	else
		control = nullptr;
}

template<typename T>
SimpleSharedPtr<T>::~SimpleSharedPtr()
{
	release();
}

//这个时候用的是浅拷贝，之前的课说过深拷贝和浅拷贝没有好坏之分，要看实际需求
template<typename T>
SimpleSharedPtr<T>::SimpleSharedPtr(const SimpleSharedPtr& s) : ptr(s.ptr), control(s.control)
{
	if (control)
		++control->ref_count;
}

template<typename T>
SimpleSharedPtr<T>& SimpleSharedPtr<T>::operator=(const SimpleSharedPtr& s)
{
	if (this != &s)
	{
		release();
		ptr = s.ptr;
		control = s.control;
		if (control)
			++control->ref_count;
	}
	return *this;
}

template<typename T>
SimpleSharedPtr<T>::SimpleSharedPtr(SimpleSharedPtr&& other) noexcept
	:ptr(other.ptr), control(other.control)
{
	other.ptr = nullptr;
	other.control = nullptr;
}

template<typename T>
SimpleSharedPtr<T>& SimpleSharedPtr<T>::operator=(SimpleSharedPtr&& other) noexcept
{
	if (this != &other)
	{
		release();
		ptr = other.ptr;
		control = other.control;
		other.control = nullptr;
		other.ptr = nullptr;
	}
	return *this;
}

template<typename T>
T* SimpleSharedPtr<T>::operator->() const
{
	return ptr;
}

template<typename T>
T& SimpleSharedPtr<T>::operator*() const
{
	return *ptr;
}

template<typename T>
T* SimpleSharedPtr<T>::get() const
{
	return ptr;
}

template<typename T>
int SimpleSharedPtr<T>::use_count() const
{
	return control ? control->ref_count : 0;
}

template<typename T>
void SimpleSharedPtr<T>::reset(T* p)
{
	release();
	ptr = p;
	if (p)
		control = new ControlBlock;
	else
		control = nullptr;
}



#endif // !SimpleSharedPtr_
