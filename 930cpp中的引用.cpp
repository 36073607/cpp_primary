#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1.���õĻ����﷨
//���õ����ã������������
//�﷨���������� &���� = ԭ��
int main()
{
	int a = 0;
	int& b = a;
	b = 20;
	cout << a << endl;//20

	return 0;
}

//2.���õ�ע������
//A.���ñ����ʼ��
//B.�����ڳ�ʼ���󣬲����Ըı�
int main()
{
	int a = 10;
	int b = 20;
	//int &c;   �������ñ����ʼ��
	int& c = a;//һ����ʼ���󣬾Ͳ����Ը���
	c = b;//���Ǹ�ֵ���������Ǹ�������

	return 0;
}

//3.��������������
//���ã���������ʱ�������������õļ������β�����ʵ��
//�ŵ㣺���Լ�ָ���޸�ʵ��
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
	cout << a << " " << b;//���ô��ݣ��βλ�����ʵ�ε�

	return 0;
}

//4.��������������ֵ
//���ã������ǿ�����Ϊ�����ķ���ֵ���ڵ�
//ע�⣺��Ҫ���ؾֲ���������
//�÷�������������Ϊ��ֵ
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
	cout << "ret=" << ret << endl;//��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ

	return 0;
}

//5.���õı���
//������c++�ڲ�ʵ����һ��ָ�볣��
void func(int& ref)//���������ã�ת��Ϊ int* const ref = &a;
{
	ref = 100;
}
int main()
{
	int a = 10;
	int& ref = a;//�Զ�ת��Ϊ��int* const ref = &a;ָ�볣����ָָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	cout << a << endl;
	func(a);
	cout << a << endl;

	return 0;
}

//6.��������
//����������Ҫ���������βΣ���ֹ�����
//�ں����β��б��У����Լ�const�����βΣ���ֹ�βθı�ʵ��
void showValue(const int& val)
{
	//val = 1000;  ����
	cout << "val = " << val;
}
int main()
{
	//int& ref = 10;  ����,���ñ�����һ��Ϸ����ڴ�ռ�

	const int& ref = 10;//����const֮�󣬱������������޸ģ�int temp = 10; const int& ref =temp;
	//ref = 20;  �������ʽ�����ǿ��޸ĵ���ֵ������const֮���Ϊֻ�����������޸�

	int a = 10;
	showValue(a);

	return 0;
}
