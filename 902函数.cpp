#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//1. 函数的定义

//2. 函数的调用:使用定义好的函数

//3. 值传递、址传递

//4. 常见的样式
//1.无参无返
void test1()
{
	cout << "hello" << endl;
}
//2.有参无返
void test2(int a)
{
	cout << "a=" << a << endl;
}
//3.无参有反
int test3()
{
	cout << "hi" << endl;
	return 1000;
}
//4.有参有反
int test4(int a)
{
	cout << "a = " << a << endl;
	return a;

}
int main()
{
	//无参无返调用
	test1();

	//有参无返调用
	int a = 10;
	test2(a);

	//无参有反调用
	int ret = test3();
	cout << "ret = " << ret << endl;//注意这种无参有反的打印结果

	//有参有反调用
	int num = test4(1000);
	cout << "num = " << num << endl;


	return 0;
}


//5. 函数的声明
//作用：告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义
//注：函数的声明可以多次，但函数的定义只能有一次

int max(int x, int y);
int main()
{
	int a = 20;
	int b = 10;
	cout << max(a, b) << endl;

	return 0;
}
int max(int x, int y)
{
	return x > y ? x : y;
}


//6. 函数的分文件编写
//一般有4个步骤：
//1.创建后缀名为.h的头文件
//2.创建后缀名为.cpp的源文件
//3.在头文件中写函数的声明
//4.在源文件中写函数的定义
#include <iostream>
using namespace std;
#include "swap.h"
int main()
{
	int a = 20;
	int b = 10;
	cout << swap(a, b) << endl;
	return 0;
}
