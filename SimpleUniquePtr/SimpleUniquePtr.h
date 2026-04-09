#pragma once

#ifndef _SimpleUniquePtr_
#define _SimpleUniquePtr_

template<typename T>
class SimpleUniquePtr
{
private:
	T* ptr;

public:
	SimpleUniquePtr();
	explicit SimpleUniquePtr(T* p);
	~SimpleUniquePtr();
	//删除拷贝构造和拷贝复制
	SimpleUniquePtr(const SimpleUniquePtr&) = delete;
	SimpleUniquePtr& operator=(const SimpleUniquePtr&) = delete;
	SimpleUniquePtr(SimpleUniquePtr&& other) noexcept;
	SimpleUniquePtr& operator=(SimpleUniquePtr&& other) noexcept;

	T* operator ->() const;
	T& operator *() const;
	T* get() const;
	//释放所有权
	T* release();
	//重新设定指针
	void reset(T* p = nullptr);

};

template<typename T>
SimpleUniquePtr<T>::SimpleUniquePtr() : ptr(nullptr) {}

template<typename T>
SimpleUniquePtr<T>::SimpleUniquePtr(T* p): ptr(p) {}

template<typename T>
SimpleUniquePtr<T>::~SimpleUniquePtr()
{
	delete ptr;
}

template<typename T>
SimpleUniquePtr<T>::SimpleUniquePtr(SimpleUniquePtr&& other) noexcept
	: ptr(other.ptr)
{
	other.ptr = nullptr;
}

template<typename T>
SimpleUniquePtr<T>& SimpleUniquePtr<T>::operator=(SimpleUniquePtr&& other) noexcept
{
	if (this != &other)
	{
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	return *this;
}

template<typename T>
T* SimpleUniquePtr<T>::operator->() const
{
	return ptr;
}

template<typename T>
T& SimpleUniquePtr<T>::operator*() const
{
	return *ptr;
}

template<typename T>
T* SimpleUniquePtr<T>::get() const
{
	return ptr;
}

template<typename T>
T* SimpleUniquePtr<T>::release()
{
	T* tmp = ptr;
	ptr = nullptr;
	return tmp;
}

template<typename T>
void SimpleUniquePtr<T>::reset(T* p)
{
	delete ptr;
	ptr = p;
}


#endif // !_SimpleUniquePtr_
