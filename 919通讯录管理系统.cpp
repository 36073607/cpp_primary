#include <iostream>
#include<string>
using namespace std;
//1.菜单
void menu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.推出通讯录  *****" << endl;
	cout << "**************************" << endl;

}
//联系人结构体
struct Person
{
	string name;
	string sex;
	int age;
	string tele;
	string add;
};
//通讯录结构体
#define MAX 1000//最大人数
struct Addressbooks
{
	struct Person personarray[MAX];//通讯录中保存的联系人数组
	int max_size;//通讯录中人员个数
};
//1.添加联系人的函数
void addperson(struct Addressbooks* abs)
{
	if (abs->max_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[abs->max_size].name = name;
		//性别
		string sex;
		cout << "请输入性别：" << endl;
		cin >> sex;
		abs->personarray[abs->max_size].sex = sex;
		//电话
		string tele;
		cout << "请输入电话号码" << endl;
		cin >> tele;
		abs->personarray[abs->max_size].tele = tele;
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personarray[abs->max_size].age = age;
		//住址
		string add;
		cout << "请输入住址" << endl;
		cin >> add;
		abs->personarray[abs->max_size].add = add;

		//更新通讯录人数
		abs->max_size++;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}
//2.显示所有联系人
void display(struct Addressbooks* str)
{
	if (str->max_size == 0)
		cout << "当前未添加联系人" << endl;
	else
	{
		for (int i = 0; i < str->max_size; i++)
		{
			cout << "姓名：" << str->personarray[i].name << "\t";
			cout << "性别：" << str->personarray[i].sex << "\t";
			cout << "电话：" << str->personarray[i].tele << "\t";
			cout << "年龄：" << str->personarray[i].age << "\t";
			cout << "住址：" << str->personarray[i].add << endl;
		}

	}
	system("pause");
	system("cls");
}
//3.删除联系人-按照姓名
//查找是否存在
int check(struct Addressbooks* str,string test)
{
	for (int i = 0; i < str->max_size; i++)
	{
		if (test == str->personarray[i].name)//找到了
		{
			return i;
		}
		
	}
	return -1;
}
//删除
void my_delete(struct Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string cname;
	cin >> cname;
	int ret = check(abs, cname);//注意abs已经是原结构体的指针，所以没必要加&
	if (ret == -1)
	{
		cout << "查无此入" << endl;
	}
	else
	{
		for (int j = ret; j < abs->max_size; j++)
		{
			abs->personarray[j] = abs->personarray[j + 1];
		}
		abs->max_size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
//4.查找联系人
void find(struct Addressbooks* p)
{
	cout << "请输入您要查找的联系人" << endl;
	string dname;
	cin >> dname;
	int ret = check(p, dname);
	if (ret== -1)
	{
		cout << "该联系人不存在" << endl;
	}
	else
	{
		cout << "查询成功" << endl;
		cout << "姓名：" << p->personarray[ret].name << "\t";
		cout << "性别：" << p->personarray[ret].sex << "\t";
		cout << "电话：" << p->personarray[ret].tele << "\t";
		cout << "年龄：" << p->personarray[ret].age << "\t";
		cout << "住址：" << p->personarray[ret].add << "\t";

		
	}
	system("pause");
	system("cls");
}
//5.修改联系人
void changeperson(struct Addressbooks* p)
{
	cout << "请输入您要修改的联系人" << endl;
	string testname;
	cin >> testname;
	int ret = check(p, testname);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		p->personarray[ret].name = name;
		//性别
		string sex;
		cout << "请输入性别：" << endl;
		cin >> sex;
		p->personarray[ret].sex = sex;
		//电话
		string tele;
		cout << "请输入电话号码" << endl;
		cin >> tele;
		p->personarray[ret].tele = tele;
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		p->personarray[ret].age = age;
		//住址
		string add;
		cout << "请输入住址" << endl;
		cin >> add;
		p->personarray[ret].add = add;

		cout << "修改成功" << endl;

	}
		system("pause");
		system("cls");
}
//6.清空联系人
//只需将通讯录记录的联系人数量重置为0，做逻辑清空即可
//这样清空的话删除数组最后一个元素的时候会导致能够访问到原来并没有清空的内存
void cleanperson(struct Addressbooks* p)
{
	cout << "确定清空联系人吗(1-是/0-否)?" << endl;
	int judge;
	cin >> judge;
	if (judge == 1)
	{
		p->max_size = 0;
		cout << "清空成功" << endl;
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
	case 1://1.添加联系人
		addperson(&arr);
		break;
	case 2://2.显示联系人
		display(&arr);
		break;
	case 3://3.删除联系人
		my_delete(&arr);
		break;
	case 4://4.查找联系人
		find(&arr);
		break;
	case 5://5.修改联系人
		changeperson(&arr);
		break;
	case 6://6.清空联系人
		cleanperson(&arr);
		break;
	case 0://0.推出通讯录
		cout << "欢迎下次使用" << endl;
		break;

	default:
		break;
	}
	} while (input);
	

	return 0;
}