#include <iostream>
#include<string>
using namespace std;
//1.�˵�
void menu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�Ƴ�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;

}
//��ϵ�˽ṹ��
struct Person
{
	string name;
	string sex;
	int age;
	string tele;
	string add;
};
//ͨѶ¼�ṹ��
#define MAX 1000//�������
struct Addressbooks
{
	struct Person personarray[MAX];//ͨѶ¼�б������ϵ������
	int max_size;//ͨѶ¼����Ա����
};
//1.�����ϵ�˵ĺ���
void addperson(struct Addressbooks* abs)
{
	if (abs->max_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[abs->max_size].name = name;
		//�Ա�
		string sex;
		cout << "�������Ա�" << endl;
		cin >> sex;
		abs->personarray[abs->max_size].sex = sex;
		//�绰
		string tele;
		cout << "������绰����" << endl;
		cin >> tele;
		abs->personarray[abs->max_size].tele = tele;
		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personarray[abs->max_size].age = age;
		//סַ
		string add;
		cout << "������סַ" << endl;
		cin >> add;
		abs->personarray[abs->max_size].add = add;

		//����ͨѶ¼����
		abs->max_size++;

		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}
//2.��ʾ������ϵ��
void display(struct Addressbooks* str)
{
	if (str->max_size == 0)
		cout << "��ǰδ�����ϵ��" << endl;
	else
	{
		for (int i = 0; i < str->max_size; i++)
		{
			cout << "������" << str->personarray[i].name << "\t";
			cout << "�Ա�" << str->personarray[i].sex << "\t";
			cout << "�绰��" << str->personarray[i].tele << "\t";
			cout << "���䣺" << str->personarray[i].age << "\t";
			cout << "סַ��" << str->personarray[i].add << endl;
		}

	}
	system("pause");
	system("cls");
}
//3.ɾ����ϵ��-��������
//�����Ƿ����
int check(struct Addressbooks* str,string test)
{
	for (int i = 0; i < str->max_size; i++)
	{
		if (test == str->personarray[i].name)//�ҵ���
		{
			return i;
		}
		
	}
	return -1;
}
//ɾ��
void my_delete(struct Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string cname;
	cin >> cname;
	int ret = check(abs, cname);//ע��abs�Ѿ���ԭ�ṹ���ָ�룬����û��Ҫ��&
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int j = ret; j < abs->max_size; j++)
		{
			abs->personarray[j] = abs->personarray[j + 1];
		}
		abs->max_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//4.������ϵ��
void find(struct Addressbooks* p)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string dname;
	cin >> dname;
	int ret = check(p, dname);
	if (ret== -1)
	{
		cout << "����ϵ�˲�����" << endl;
	}
	else
	{
		cout << "��ѯ�ɹ�" << endl;
		cout << "������" << p->personarray[ret].name << "\t";
		cout << "�Ա�" << p->personarray[ret].sex << "\t";
		cout << "�绰��" << p->personarray[ret].tele << "\t";
		cout << "���䣺" << p->personarray[ret].age << "\t";
		cout << "סַ��" << p->personarray[ret].add << "\t";

		
	}
	system("pause");
	system("cls");
}
//5.�޸���ϵ��
void changeperson(struct Addressbooks* p)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string testname;
	cin >> testname;
	int ret = check(p, testname);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		p->personarray[ret].name = name;
		//�Ա�
		string sex;
		cout << "�������Ա�" << endl;
		cin >> sex;
		p->personarray[ret].sex = sex;
		//�绰
		string tele;
		cout << "������绰����" << endl;
		cin >> tele;
		p->personarray[ret].tele = tele;
		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
		p->personarray[ret].age = age;
		//סַ
		string add;
		cout << "������סַ" << endl;
		cin >> add;
		p->personarray[ret].add = add;

		cout << "�޸ĳɹ�" << endl;

	}
		system("pause");
		system("cls");
}
//6.�����ϵ��
//ֻ�轫ͨѶ¼��¼����ϵ����������Ϊ0�����߼���ռ���
//������յĻ�ɾ���������һ��Ԫ�ص�ʱ��ᵼ���ܹ����ʵ�ԭ����û����յ��ڴ�
void cleanperson(struct Addressbooks* p)
{
	cout << "ȷ�������ϵ����(1-��/0-��)?" << endl;
	int judge;
	cin >> judge;
	if (judge == 1)
	{
		p->max_size = 0;
		cout << "��ճɹ�" << endl;
	}
	else
		return;

	system("pause");
	system("cls");
}
int main()
{
	int input = 0;
	struct Addressbooks arr;
	arr.max_size = 0;
	
	do
	{
		menu();
		cin >> input;
		switch (input)
	{
	case 1://1.�����ϵ��
		addperson(&arr);
		break;
	case 2://2.��ʾ��ϵ��
		display(&arr);
		break;
	case 3://3.ɾ����ϵ��
		my_delete(&arr);
		break;
	case 4://4.������ϵ��
		find(&arr);
		break;
	case 5://5.�޸���ϵ��
		changeperson(&arr);
		break;
	case 6://6.�����ϵ��
		cleanperson(&arr);
		break;
	case 0://0.�Ƴ�ͨѶ¼
		cout << "��ӭ�´�ʹ��" << endl;
		break;

	default:
		break;
	}
	} while (input);
	

	return 0;
}