#include <iostream>
using namespace std;
//һ �ο�ʼ�ĵط�
int main()
{
	cout << "hello world" << endl;
	system("pause");//��������֤����仰���п���

	return 0;
}


//�� ע��


//�� ����
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	cout << "a=" << a << endl;

	system("pause");
	return 0;
}


//�� ����
//1.#define �곣��: #define ������ ����ֵ
// ͨ�����ļ��Ϸ����壬��ʾһ������
//2.const���εı���: const �������� ������ = ����ֵ
// ͨ���ڱ�������1ǰ�ӹؼ���const�����θñ���Ϊ�����������޸�
//��һ
#include <iostream>
using namespace std;
#define Trial 7
int main()
{
	cout << "һ���ܹ��У�" << Trial << "��" << endl;

	system("pause");
	return 0;
}
//���
#include <iostream>
using namespace std;
int main()
{
	const int week = 7;
	cout << "��" << week << "��" << endl;

	system("pause");
	return 0;
}



//�� �ؼ���


//�� ��ʶ����������
//1.��ʶ�������ǹؼ���
//2.��ʶ��ֻ������ĸ�����֡��»������
//3.��һ���ַ�����Ϊ��ĸ���»���
//4.��ʶ������ĸ���ִ�Сд
//���飺������������ʱ������ܹ���������֪��