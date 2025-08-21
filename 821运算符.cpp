#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1. 算术运算符：处理四则运算
int main()
{
	double a = 2.3;
	double b = 1.1;
	cout << a / b << endl;//2.09091
	//小数与小数相除，商可以是整数或者小数

	int num1 = 5;
	int num2 = 2;
	cout <<(double) num1 / num2 << endl;

	//两个小数不可以做取模运算

	int a1 = 10;
	int a2 = 10;
	int b1 = ++a1 * 10;
	int b2 = a2++ * 10;
	cout << "a1 = " << a1 << "b1 = " << b1 << endl;//11 110
	cout << "a2 = " << a2 << "b2 = " << b2 << endl;//11 100

	return 0;
}


//2. 赋值运算符
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int b = 3;
	cout << "a+=b = " << (a += b) << endl;
	cout << "a*=b = " << (a *= b) << endl;
	cout << "a/=b = " << (a /= b) << endl;
	//注意运算的优先级，加上(),否则会报错

	return 0;
}



//3. 比较运算符
int main()
{
	int a = 1;
	int b = 2;
	cout << (a == b) << endl;//0
	cout << (a != b) << endl;//1
	//注意这里的返回值

	return 0;
}

//4. 逻辑运算符
//非 !
int main()
{
	int a = 3;
	cout << !a << endl;//0
	cout << !!a << endl;//1

	return 0;
}
//与 &&
int main()
{
	int a = 10;
	int b = 13;
	cout << (a && b) << endl;//1

	a = 0;
	cout << (a && b) << endl;//0

	return 0;
}
//或 ||
