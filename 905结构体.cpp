#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1. �ṹ���������
//�ṹ�������û��Զ�����������ͣ������û����治ͬ����������

//2. �ṹ�崴��
#include <string>
struct student
{
	string name;
	int age;
	int score;

}a3;//3.
int main()
{
	//1.
	struct student a1;
	a1.name = "����";
	a1.age = 18;
	a1.score = 13;

	//2.
	struct student a2 = { "����",18,22 };

	//3.
	a3.name = "����";
	a3.age = 10;
	a3.score = 44;

	cout << a1.name << a1.age << a1.score;

	return 0;
}
//ע��
//1.����ṹ�����ʱ�Ĺؼ���struct������ʡ��
//2.�����ṹ�����ʱ���ؼ���struct����ʡ��
//�ṹ��������ò�������.�����ʳ�Ա


//3 .�ṹ������
struct s1
{
	string name;
	int age;

};
int main()
{
	s1 arr[3] =
	{
		{"����",18},
		{"����",22}
	};

	//�޸Ľṹ����������
	arr[0].age = 23;
	arr[1].name = "����";

	//�����ṹ������
	for (int i = 0; i < 2; i++)
	{
		cout << "������" << arr[i].name << "���䣺" << arr[i].age;
	}

	return 0;
}


//4. �ṹ��ָ��
struct student 
{
	string name;
	int age;
	int score;

};
int main()
{
	struct student s1 = { "zs",18,100 };

	struct student* p = &s1;

	cout << p->name << p->age << p->score;

	return 0;
}


//5. �ṹ��Ƕ��
struct teacher
{
	string name;
	int age;
};

struct student
{
	string name;
	int age;
	int score;
	struct teacher kp;

};
int main()
{
	struct student s1 = { "ls",18,99,{"ss",66}};


	student s2;
	s2.name = "mk";
	s2.age = 19;
	s2.score = 98;
	s2.kp.name = "kj";
	s2.kp.age = 67;

	return 0;
}



//6. �ṹ������������
struct student
{
	string name;
	int age;
	int score;
};
void print1(struct student p)
{
	cout << p.name << p.age << p.score;
}
void print2(struct student* p)
{
	cout << p->name << p->age << p->score;
}
int main()
{
	student s = { "ss",19,90 };
	print1(s);
	print2(&s);

	return 0;
}


//7. �ṹ���е�const
//���ã���const��ֹ�����
struct student
{
	string name;
	int age;
	int score;
};
void print2(const student* p)
{
	//p->name = "jk";  err    ����const����Է�ֹ��ַʱ��С�İѲ����ı�
	cout << p->name << p->age << p->score;
}
int main()
{
	student s = { "ss",19,90 };
	
	print2(&s);

	return 0;
}


//8. ����һ
#include <iostream>
#include<string>
using namespace std;
struct student
{
	string name;
	int score;
};
struct teacher
{
	string name;
	student s[5];
};

int main()
{
	teacher t[3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> t[i].name >> t[i].s[j].name >> t[i].s[i].score;
		}
		cout << "\n";
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << t[i].name << t[i].s[j].name << t[i].s[i].score;
		}
		cout << "\n";
	}

	return 0;
}

#include <iostream>
#include<string>
#include<ctime>
using namespace std;
struct student
{
	string name;
	int score;
};
struct teacher
{
	string name;
	student s[5];
};
//����ʦ��ѧ����ֵ�ĺ���
void allocatespace(struct teacher* p, int sz)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < sz; i++)
	{
		p[i].name = "teacher_";
		p[i].name += nameseed[i]; //����� + �Ų��Ǽӷ�������������ַ����������������ʾ��ǰ�������ַ������ӳ�һ���ַ�����

		for (int j = 0; j < 5; j++)
		{
			p[i].s[j].name = "student_";
			p[i].s[j].name += nameseed[j];

			p[i].s[j].score = rand() % 61 + 40;
		}

	}


}
//��ӡ������Ϣ�ĺ���
void print(struct teacher p[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cout << p[i].name << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << p[i].s[j].name << " " << p[i].s[j].score << endl;
		}
		cout << "\n";
	}

}
int main()
{
	//�������������
	srand((unsigned int)time(NULL));

	teacher tch[3];
	int sz = sizeof(tch) / sizeof(tch[0]);
	allocatespace(tch, sz);
	print(tch, sz);

	return 0;
}


//������:ͨ��ð�����򣬽������е���1����������������������մ�ӡ�����Ľ��
#include <iostream>
#include<string>
#include<ctime>
using namespace std;
struct hero
{
	string name;
	int age;
	string sex;
};
void change(hero p[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (p[j].age > p[j + 1].age)
			{
				int tmp = p[j].age;
				p[j].age = p[j + 1].age;
				p[j + 1].age = tmp;

				string tmp2 = p[j].name;
				p[j].name = p[j + 1].name;
				p[j + 1].name = tmp2;

				string tmp3 = p[j].sex;
				p[j].sex = p[j + 1].sex;
				p[j + 1].sex = tmp3;
			}

		}

	}
}

int main()
{
	hero sanguo[5];
	for (int x = 0; x < 5; x++)
	{
		cin >> sanguo[x].name >> sanguo[x].age >> sanguo[x].sex;
	}
	int sz = sizeof(sanguo) / sizeof(sanguo[0]);
	change(sanguo, sz);
	for (int y = 0; y < 5; y++)
	{
		cout << sanguo[y].name << sanguo[y].age << sanguo[y].sex << endl;
	}

	return 0;
}

#include <iostream>
#include<string>
#include<ctime>
using namespace std;
struct hero
{
	string name;
	int age;
	string sex;
};
void change(hero p[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (p[j].age > p[j + 1].age)
			{
				struct hero tmp = p[j];//�Ż���ע������д��
				p[j] = p[j + 1];
				p[j + 1] = tmp;

			}

		}

	}
}

int main()
{
	hero sanguo[5];
	for (int x = 0; x < 5; x++)
	{
		cin >> sanguo[x].name >> sanguo[x].age >> sanguo[x].sex;
	}
	int sz = sizeof(sanguo) / sizeof(sanguo[0]);
	change(sanguo, sz);
	for (int y = 0; y < 5; y++)
	{
		cout << sanguo[y].name << sanguo[y].age << sanguo[y].sex << endl;
	}

	return 0;
}
