#define _CRT_SECURE_NO_WARNINGS

#include "SingleOnceFlag.h"

//给静态成员变量初始化 并直接创建一个实例，让多线程启用时获得的实例是唯一的
SingleOnceFlag* SingleOnceFlag::_instance = SingleOnceFlag::GetInst();

