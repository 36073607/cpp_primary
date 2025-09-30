#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1.引用的基本语法
//引用的作用：给变量起别名
//语法：数据类型 &别名 = 原名
int main()
{
	int a = 0;
	int& b = a;
	b = 20;
	cout << a << endl;//20

	return 0;
}

//2.引用的注意事项
//A.引用必须初始化
//B.引用在初始化后，不可以改变
int main()
{
	int a = 10;
	int b = 20;
	//int &c;   错误，引用必须初始化
	int& c = a;//一旦初始化后，就不可以更改
	c = b;//这是赋值操作，不是更改引用

	return 0;
}

//3.引用做函数参数
//作用：函数传参时，可以利用引用的技术让形参修饰实参
//优点：可以简化指针修改实参
void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout << a << " " << b;//引用传递，形参会修饰实参的

	return 0;
}

//4.引用做函数返回值
//作用：引用是可以作为函数的返回值存在的
//注意：不要返回局部变量引用
//用法：函数调用作为左值
int& test()
{
	static int a = 10;
	return a;
}
int main()
{
	int& ret = test();
	cout << "ret=" << ret << endl;

	test() = 1000;
	cout << "ret=" << ret << endl;//如果函数的返回值是引用，这个函数调用可以作为左值

	return 0;
}

//5.引用的本质
//引用在c++内部实现是一个指针常量
void func(int& ref)//发现是引用，转换为 int* const ref = &a;
{
	ref = 100;
}
int main()
{
	int a = 10;
	int& ref = a;//自动转换为：int* const ref = &a;指针常量是指指针指向不可改，也说明为什么引用不可更改
	cout << a << endl;
	func(a);
	cout << a << endl;

	return 0;
}

//6.常量引用
//常量引用主要用来修饰形参，防止误操作
//在函数形参列表中，可以加const修饰形参，防止形参改变实参
void showValue(const int& val)
{
	//val = 1000;  报错
	cout << "val = " << val;
}
int main()
{
	//int& ref = 10;  错误,引用必须引一块合法的内存空间

	const int& ref = 10;//加上const之后，编译器将代码修改：int temp = 10; const int& ref =temp;
	//ref = 20;  报错：表达式必须是可修改的左值，加入const之后变为只读，不可以修改

	int a = 10;
	showValue(a);

	return 0;
}
