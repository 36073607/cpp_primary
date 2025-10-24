#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//����ָ�����֪ʶ

//1.��ȡ�����ĵ�ַ��
//ֻ��ʹ�ú�����(���治������)����   eg:func()��һ����������func���Ǹú����ĵ�ַ
//ע�����ִ��ݵ��Ǻ����ĵ�ַ���Ǻ����ķ���ֵ
//process(func);  ���ﴫ�ݵ��Ǻ���func()�ĵ�ַ
//process(func());  ���ﴫ�ݵ��Ǻ���func()�ķ���ֵ

//2.��������ָ��
//��������ָ��Ӧָ�������ķ������ͺͲ����б�
//eg: double pam(int);  ���Ǻ���ԭ��
//    double (*pf)(int);  ���Ǻ���ָ��
//�����ܽ᣺�Ѻ����ķ������ͺͲ����б��������������͵Ķ������������������ָ�����һ��
//int* p;
//double (*pf)(int);  �����double��(int)����һ�����壬��Ϊһ�����ͣ�*pf�������������µ�ָ�����

//3.ʹ��ָ�������ú���
//(*pf)���ݵĽ�ɫ�뺯������ͬ�����ʹ��(*pf)ʱ��ֻ�轫����������������
//(*pf)�Ǻ�����pf���Ǻ���ָ��
void func(int a)
{
	return;
}
int main()
{
	int a = 0;
	//����һ
	void (*pf1)(int) = func;//������һ������ָ��pf1����ʼ��
	func(a);
	(*pf1)(a);//���ú���

	//������
	void (*pf2)(int);//������һ������ָ��
	pf2 = func;//��ʼ��
	(*pf2)(a);//���ú���
	pf2(a);//���ú���

	//������ʷ���߼�ԭ��
	//����� pf2 �� (*pf2) �ȼ�

	return 0;
}


//����̽�ֺ���ָ��
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
	cout << p1(array, 3) << "\t" << *(p1(array, 3)) << endl;//���ú���ʱp1��(*p1)�ȼ�
	cout << p2(array, 3) << "\t" << *(p2(array, 3)) << endl;


	const double* (*pa[3])(const double*, int) = { f1,f2,f3 };//���int* pa[3] = {p1,p2,p3};
	//[]���ȼ���*��
	//��һ��[]�൱�ڽ�����(*)һ��
	auto pb = pa;
	//const double* (*(*pb))(const double*, int) = pa;
	//pa�Ǻ���ָ����������*pb��Ӧpa��*(*pb)��Ӧ�����е�Ԫ��----������ַ    (*pf)=func;
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


	auto pc = &pa;//&pa����������ĵ�ַ
	//pa������һ������ָ�룬��pa�ĵ�ַ��pc,��pc������ָ��
	//
	//const double* (*(*pc)[3])(const double*, int) = &pa;
	// (*pc[3])��Ӧ &pa  ,*(*pc)[3]��Ӧ�����е�Ԫ��----������
	//ע��
	//*pd[3]  ��һ��������ָ�������
	//(*pd)[3]  ��һ��ָ��ӵ������Ԫ�ص������ָ��
	cout << "Address\tvalue\n";
	for (int i = 0; i < 3; i++)
	{
		cout << (*pc)[i](array, 3) << "\t" << *(*pc)[i](array, 3) << endl;
	}

	return 0;
}