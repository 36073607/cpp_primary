#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//函数指针基础知识

//1.获取函数的地址：
//只需使用函数名(后面不跟参数)即可   eg:func()是一个函数，则func就是该函数的地址
//注：区分传递的是函数的地址还是函数的返回值
//process(func);  这里传递的是函数func()的地址
//process(func());  这里传递的是函数func()的返回值

//2.声明函数指针
//声明函数指针应指定函数的返回类型和参数列表
//eg: double pam(int);  这是函数原型
//    double (*pf)(int);  这是函数指针
//个人总结：把函数的返回类型和参数列表当作类似数据类型的东西，其余跟创建正常指针变量一致
//int* p;
//double (*pf)(int);  这里把double和(int)看作一个整体，视为一种类型，*pf就是这种类型下的指针变量

//3.使用指针来调用函数
//(*pf)扮演的角色与函数名相同，因此使用(*pf)时，只需将它看作函数名即可
//(*pf)是函数，pf就是函数指针
void func(int a)
{
	return;
}
int main()
{
	int a = 0;
	//方法一
	void (*pf1)(int) = func;//创建了一个函数指针pf1并初始化
	func(a);
	(*pf1)(a);//调用函数

	//方法二
	void (*pf2)(int);//创建了一个函数指针
	pf2 = func;//初始化
	(*pf2)(a);//调用函数
	pf2(a);//调用函数

	//由于历史与逻辑原因
	//这里的 pf2 和 (*pf2) 等价

	return 0;
}


//深入探讨函数指针
const double* f1(const double* arr, int sz)
{
	return arr;
}

const double* f2(const double arr[], int sz)
{
	return arr + 1;
}

const double* f3(const double* arr, int sz)
{
	return arr + 2;
}

int main()
{
	double array[3] = { 1112.3,1542.6,2227.9 };

	const double* (*p1)(const double*, int) = f1;
	auto p2 = f2;
	//const double* (*p2)(const double*, int) = f2;
	cout << "Address\tvalue\n";
	cout << (*p1)(array, 3) << "\t" << *((*p1)(array, 3)) << endl;
	cout << p1(array, 3) << "\t" << *(p1(array, 3)) << endl;//调用函数时p1与(*p1)等价
	cout << p2(array, 3) << "\t" << *(p2(array, 3)) << endl;


	const double* (*pa[3])(const double*, int) = { f1,f2,f3 };//类比int* pa[3] = {p1,p2,p3};
	//[]优先级比*高
	//用一次[]相当于解引用(*)一次
	auto pb = pa;
	//const double* (*(*pb))(const double*, int) = pa;
	//pa是函数指针数组名，*pb对应pa，*(*pb)对应数组中的元素----函数地址    (*pf)=func;
	cout << "Address\tvalue\n";
	for (int i = 0; i < 3; i++)
	{
		cout << (*(pa[i]))(array, 3) << "\t" << *(*(pa[i]))(array, 3) << endl;
		//cout << pa[i](array, 3) << *(pa[i](array, 3)) << endl;
	}
	cout << "Address\tvalue\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pb[i](array, 3) << "\t" << *(pb[i](array, 3)) << endl;
	}


	auto pc = &pa;//&pa是整个数组的地址
	//pa本就是一个二级指针，将pa的地址给pc,则pc是三级指针
	//
	//const double* (*(*pc)[3])(const double*, int) = &pa;
	// (*pc[3])对应 &pa  ,*(*pc)[3]对应数组中的元素----函数名
	//注：
	//*pd[3]  是一个有三个指针的数组
	//(*pd)[3]  是一个指向拥有三个元素的数组的指针
	cout << "Address\tvalue\n";
	for (int i = 0; i < 3; i++)
	{
		cout << (*pc)[i](array, 3) << "\t" << *(*pc)[i](array, 3) << endl;
	}

	return 0;
}