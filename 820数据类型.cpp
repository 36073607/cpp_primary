#define _CRT_SECURE_NO_WARNINGS
//��������
//1.���� �������͵�����
//short�������ͣ� ռ��2�ֽ�
//int�����ͣ� ռ��4�ֽ�
//long�������ͣ� windowsΪ4�ֽڣ�linuxΪ4�ֽڣ�32λ����8�ֽڣ�64λ��
//long long���������ͣ� 8�ֽ�
//ע��ռ�ÿռ��С��ͬ������ �洢����������ȡֵ�ķ�Χ ��ͬ
//����int ȡֵ��Χ ��-2^31 -- 2^31-1��



//2. sizeof�ؼ���
//���� ͳ������������ռ�ڴ��С
#include <iostream>
using namespace std;
int main()
{
	cout << "short��ռ�ڴ棺" << sizeof(short) << endl;
	cout << "int��ռ�ڴ棺" << sizeof(int) << endl;
	cout << "long��ռ�ڴ棺" << sizeof(long) << endl;
	cout << "long long��ռ�ڴ棺" << sizeof(long long) << endl;

	int num = 10;
	cout << sizeof(num) << endl;

	return 0;
}



//3. ʵ�ͣ������ͣ�
//������float ռ��4�ֽ�   ��Ч���ַ�Χ��7λ��Ч����
//˫����double ռ��8�ֽ�  ��Ч���ַ�Χ��15-16λ��Ч����
//Ĭ������� ���һ��С��������ʾ6λ��Ч����
#include <iostream>
using namespace std;
int main()
{
	float num1 = 0.0f;//Ĭ�ϸ�����Ϊ˫���ȣ���fʹ��Ϊ������
	double num2 = 0.0;

	//��ѧ������
	float f1 = 3e2;//3*10^2     300
	float f2 = 3e-2;//3*10^-2   0.03

	return 0;
}


//4. �ַ���
//���� �ַ��ͱ���������ʾ�����ַ�
//�﷨ char ch = 'a';

//ע��1:����ʾ�ַ��ͱ���ʱ���õ����Ž��ַ�����������Ҫ��˫����
//ע��2:��������ֻ����һ���ַ������������ַ�����������c�����������ã�

//c��cpp���ַ��ͱ���ֻռ��1���ֽ�
//�ַ��ͱ��������ǰ��ַ�����ŵ��ڴ��д洢�����ǽ���Ӧ��ASCII������뵽�洢��Ԫ

#include <iostream>
using namespace std;
int main()
{
	char ch = 'a';
	//�鿴�ַ��ͱ�����Ӧ��ASCII��
	cout << (int)ch << endl;

	//a-97  A-65     ���32

	return 0;
}


//5. ת���ַ�
#include <iostream>
using namespace std;
int main()
{
	//���з� \n

	cout << "hello" << endl;
	cout << "hello\n";

	//��б�� \\

	cout << "\\" << endl;  //��ӡ���Ϊ \

	//ˮƽ�Ʊ��:������������ʱ��ʽ����
	cout << "aaa\thello" << endl;// \t��֮ǰ���ַ���ռ8��λ�� aaa����ո�hello
	cout << "aaaa\thello" << endl;// aaaa�ĸ��ո�hello

	return 0;
}



//6. �ַ�����
//C����ַ�����char ch[] = "abcde";
//C++���string ch = "abcde";
#include <iostream>
#include <string>//C++���д��Ҫע������ͷ�ļ�
using namespace std;
int main()
{
	char arr[] = "abcde";
	cout << arr << endl;

	string arr1 = "abcdef";
	cout << arr1 << endl;//C++���д��Ҫע������ͷ�ļ�


	return 0;
}


//7. ��������   ռ��1���ֽ�
//true(������1)   false(������0)
#include <iostream>
using namespace std;
int main()
{
	bool flag = true;
	cout << flag << endl;

	flag = false;
	cout << flag << endl;


	return 0;
}


//8. ���ݵ�����(scanf)
//���� ���ڴӼ��̻�ȡ����
//�ؼ��� cin :   cin >> ����;
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a = 0;
	cout << "���a��ֵ" << endl;
	cin >> a;
	cout << "a=" << a << endl;

	string ch = "0";
	cin >> ch;
	cout << ch << endl;

	bool flag = false;
	cin >> flag;
	cout << flag << endl;//bool����ֻҪ�Ƿ����ֵ�������棬����Ӣ��ʱ���0

	return 0;
}
//�ܽ᣺cin --> c in
//      cout --> c out
