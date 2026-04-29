#define _CRT_SECURE_NO_WARNINGS

#include "SinglePointer.h"

//给静态成员变量初始化 并直接创建一个实例，让多线程启用时获得的实例是唯一的
SinglePointer* SinglePointer::single = SinglePointer::GetInst();

std::mutex SinglePointer::s_mutex;