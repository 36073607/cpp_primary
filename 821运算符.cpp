#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1. �����������������������
int main()
{
	double a = 2.3;
	double b = 1.1;
	cout << a / b << endl;//2.09091
	//С����С��������̿�������������С��

	int num1 = 5;
	int num2 = 2;
	cout <<(double) num1 / num2 << endl;

	//����С����������ȡģ����

	int a1 = 10;
	int a2 = 10;
	int b1 = ++a1 * 10;
	int b2 = a2++ * 10;
	cout << "a1 = " << a1 << "b1 = " << b1 << endl;//11 110
	cout << "a2 = " << a2 << "b2 = " << b2 << endl;//11 100

	return 0;
}


//2. ��ֵ�����
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int b = 3;
	cout << "a+=b = " << (a += b) << endl;
	cout << "a*=b = " << (a *= b) << endl;
	cout << "a/=b = " << (a /= b) << endl;
	//ע����������ȼ�������(),����ᱨ��

	return 0;
}



//3. �Ƚ������
int main()
{
	int a = 1;
	int b = 2;
	cout << (a == b) << endl;//0
	cout << (a != b) << endl;//1
	//ע������ķ���ֵ

	return 0;
}

//4. �߼������
//�� !
int main()
{
	int a = 3;
	cout << !a << endl;//0
	cout << !!a << endl;//1

	return 0;
}
//�� &&
int main()
{
	int a = 10;
	int b = 13;
	cout << (a && b) << endl;//1

	a = 0;
	cout << (a && b) << endl;//0

	return 0;
}
//�� ||
