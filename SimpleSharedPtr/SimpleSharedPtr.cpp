


//此文件无用，仅做警示！




//#define _CRT_SECURE_NO_WARNINGS
//
//#include "SimpleSharedPtr.h"
//
//ControlBlock::ControlBlock() : ref_count(1) {}
//
//template <typename T>
//void SimpleSharedPtr<T>::release()
//{
//	if (ptr)
//	{
//		--control->ref_count;
//		if (control->ref_count == 0)
//		{
//			delete ptr;
//			ptr = nullptr;
//			delete control;
//			control = nullptr;
//		}
//	}
//}
//
//template<typename T>
//SimpleSharedPtr<T>::SimpleSharedPtr():ptr(nullptr),control(nullptr) {}
//
//template<typename T>
//SimpleSharedPtr<T>::SimpleSharedPtr(T* p) : ptr(p)
//{
//	if (p)
//		control = new ControlBlock;
//	else
//		control = nullptr;
//}
//
//template<typename T>
//SimpleSharedPtr<T>::~SimpleSharedPtr()
//{
//	release();
//}
//
////这个时候用的是浅拷贝，之前的课说过深拷贝和浅拷贝没有好坏之分，要看实际需求
//template<typename T>
//SimpleSharedPtr<T>::SimpleSharedPtr(const SimpleSharedPtr& s) : ptr(s.ptr),control(s.control)
//{
//	if (control)
//		++control->ref_count;
//}
//
//template<typename T>
//SimpleSharedPtr<T>& SimpleSharedPtr<T>::operator=(const SimpleSharedPtr& s)
//{
//	if (this != &s)
//	{
//		release();
//		ptr = s.ptr;
//		control = s.control;
//		if (control)
//			++control->ref_count;
//	}
//	return *this;
//}
//
//template<typename T>
//SimpleSharedPtr<T>::SimpleSharedPtr(SimpleSharedPtr&& other) noexcept
//	:ptr(other.ptr),control(other.control)
//{
//	other.ptr = nullptr;
//	other.control = nullptr;
//}
//
//template<typename T>
//SimpleSharedPtr<T>& SimpleSharedPtr<T>::operator=(SimpleSharedPtr&& other) noexcept
//{
//	if (this != &other)
//	{
//		release();
//		ptr = other.ptr;
//		control = other.control;
//		other.control = nullptr;
//		other.ptr = nullptr;
//	}
//	return *this;
//}
//
//template<typename T>
//T* SimpleSharedPtr<T>::operator->() const
//{
//	return ptr;
//}
//
//template<typename T>
//T& SimpleSharedPtr<T>::operator*() const
//{
//	return *ptr;
//}
//
//template<typename T>
//T* SimpleSharedPtr<T>::get() const
//{
//	return ptr;
//}
//
//template<typename T>
//int SimpleSharedPtr<T>::use_count() const
//{
//	return control ? control->ref_count : 0;
//}
//
//template<typename T>
//void SimpleSharedPtr<T>::reset(T* p)
//{
//	release();
//	ptr = p;
//	if (p)
//		control = new ControlBlock;
//	else
//		control = nullptr;
//}
//
