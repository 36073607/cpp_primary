#define _CRT_SECURE_NO_WARNINGS

#include "Singleton_hungry.h"

//给静态成员变量初始化 并直接创建一个实例，让多线程启用时获得的实例是唯一的
Single_hungry* Single_hungry::single = Single_hungry::GetInst();