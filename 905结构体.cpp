#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1. 结构体基本概念
//结构体属于用户自定义的数据类型，允许用户储存不同的数据类型

//2. 结构体创建
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
	a1.name = "张三";
	a1.age = 18;
	a1.score = 13;

	//2.
	struct student a2 = { "李四",18,22 };

	//3.
	a3.name = "王五";
	a3.age = 10;
	a3.score = 44;

	cout << a1.name << a1.age << a1.score;

	return 0;
}
//注：
//1.定义结构体变量时的关键字struct，不可省略
//2.创建结构体变量时，关键字struct可以省略
//结构体变量利用操作符“.”访问成员


//3 .结构体数组
struct s1
{
	string name;
	int age;

};
int main()
{
	s1 arr[3] =
	{
		{"张三",18},
		{"李四",22}
	};

	//修改结构体数组内容
	arr[0].age = 23;
	arr[1].name = "王五";

	//遍历结构体数组
	for (int i = 0; i < 2; i++)
	{
		cout << "姓名：" << arr[i].name << "年龄：" << arr[i].age;
	}

	return 0;
}


//4. 结构体指针
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


//5. 结构体嵌套
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



//6. 结构体做函数参数
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


//7. 结构体中的const
//作用：用const防止误操作
struct student
{
	string name;
	int age;
	int score;
};
void print2(const student* p)
{
	//p->name = "jk";  err    加入const后可以防止传址时不小心把参数改变
	cout << p->name << p->age << p->score;
}
int main()
{
	student s = { "ss",19,90 };
	
	print2(&s);

	return 0;
}


//8. 案例一
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
//给老师和学生赋值的函数
void allocatespace(struct teacher* p, int sz)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < sz; i++)
	{
		p[i].name = "teacher_";
		p[i].name += nameseed[i]; //这里的 + 号不是加法运算符，而是字符串连接运算符，表示把前后两个字符串连接成一个字符串！

		for (int j = 0; j < 5; j++)
		{
			p[i].s[j].name = "student_";
			p[i].s[j].name += nameseed[j];

			p[i].s[j].score = rand() % 61 + 40;
		}

	}


}
//打印所有信息的函数
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
	//经典随机数种子
	srand((unsigned int)time(NULL));

	teacher tch[3];
	int sz = sizeof(tch) / sizeof(tch[0]);
	allocatespace(tch, sz);
	print(tch, sz);

	return 0;
}


//案例二:通过冒泡排序，将数组中的人1按照年龄进行升序排序，最终打印排序后的结果
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
				struct hero tmp = p[j];//优化，注意这种写法
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
