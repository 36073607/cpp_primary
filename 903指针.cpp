#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//其他内容见c-指针

// 1. 指针的基本概念
//指针的作用：可以通过指针间接访问内存
//注：1.内存编号是从0开始记录的，一般用十六进制数字表示
//    2.可以利用指针变量保存地址

// 2.空指针：指针变量指向内存中编号为0的空间
//用途：初始化指针变量
//注意：空指针指向的内存是不可以访问的：0~255之间的内存编号是系统占用的，因此不可以访问

// 3.野指针

// 4.const修饰指针
//1.常量指针
//常量指针特点：指针的指向可以修改，但是指针指向的值不可以改
//eg:
int main()
{
	int a = 10;
	int b = 10;
	int* p = &a;

	//const int* p = &a;

	*p = 20;//错误：指针指向的值不可以改
	p = &b;//正确：指针指向可以改

	return 0;
}

//2.指针常量
//指针常量特点：指针的指向不可以改，指针指向的值可以改
//eg:
int main()
{
	int a = 10;
	int b = 10;
	int* p = &a;

	//int* const p = &a;
	*p = 20;//正确，指向的值可以改
	p = &b;//错误，指针的指向不可以改

	return 0;
}

//3.const既修饰指针，又修饰常量
//特点：指针的指向和指针指向的值都不可以改
//eg:
int main()
{
	int a = 10;
	int b = 10;
	int* p = &a;

	//const int* const p = &a;

	*p = 20;//错误
	p = &b;//错误

	return 0;
}

//记忆技巧：const中文意思为常量


// 5.指针和数组
//作用：利用指针访问数组中元素
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << *p+i<<" ";

		cout << *p << "";
		p++;
	}

	return 0;
}
