#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//1. �����Ķ���

//2. �����ĵ���:ʹ�ö���õĺ���

//3. ֵ���ݡ�ַ����

//4. ��������ʽ
//1.�޲��޷�
void test1()
{
	cout << "hello" << endl;
}
//2.�в��޷�
void test2(int a)
{
	cout << "a=" << a << endl;
}
//3.�޲��з�
int test3()
{
	cout << "hi" << endl;
	return 1000;
}
//4.�в��з�
int test4(int a)
{
	cout << "a = " << a << endl;
	return a;

}
int main()
{
	//�޲��޷�����
	test1();

	//�в��޷�����
	int a = 10;
	test2(a);

	//�޲��з�����
	int ret = test3();
	cout << "ret = " << ret << endl;//ע�������޲��з��Ĵ�ӡ���

	//�в��з�����
	int num = test4(1000);
	cout << "num = " << num << endl;


	return 0;
}


//5. ����������
//���ã����߱������������Ƽ���ε��ú�����������ʵ��������Ե�������
//ע���������������Զ�Σ��������Ķ���ֻ����һ��

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


//6. �����ķ��ļ���д
//һ����4�����裺
//1.������׺��Ϊ.h��ͷ�ļ�
//2.������׺��Ϊ.cpp��Դ�ļ�
//3.��ͷ�ļ���д����������
//4.��Դ�ļ���д�����Ķ���
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
