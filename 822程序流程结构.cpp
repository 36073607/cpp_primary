#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1. 顺序结构：程序按顺序执行，不发生跳转
//2. 选择结构
//2.1 if语句
int main()
{
	int score = 0;
	cin >> score;
	if (score >= 80)
	{
		if (score > 90)
			cout << "A+" << endl;
		else
			cout << "A" << endl;
	}
	else if (score >= 60 && score < 80)
	{
		if (score > 70)
			cout << "B+" << endl;
		else
			cout << "B" << endl;
	}
	else
		cout << "NOOB" << endl;
		
	return 0;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	cin >> num1 >> num2 >> num3;
	if (num1 >= num2)
	{
		if (num1 >= num3)
			cout << "num1" << endl;
		else
			cout << "num3" << endl;
	}
	else if (num1 < num2)
	{
		if (num2 >= num3)
			cout << "num2" << endl;
		else if (num2 < num3)
		{
			cout << "num3" << endl;
		}
	}

	return 0;
}

//2.2 三目运算符
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = a > b ? a : b;
	cout << "c = " << c << endl;

	//C++中三目运算符返回的是变量，可以继续赋值
	(a > b ? a : b) = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	return 0;
}


//2.3 switch语句
int main()
{
	int score = 0;
	cout << "输入分数" << endl;
	cin >> score;
	switch (score)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		cout << "noob" << endl;
		break;
	case 6:
	case 7:
	case 8:
		cout << "normal" << endl;
		break;
	case 9:
	case 10:
		cout << "classic" << endl;
		break;
	default:
		cout << "please input again" << endl;
		break;
	}


	return 0;
}
//总结：
//1.switch语句中表达式类型只能是整型或者字符型
//2.case里如果没有break，那么程序会一直向下执行
//3.switch语句不能判断区间


//3.循环结构
//3.1 while语句
void menu()
{
	cout << "*****请输入(0/1)*****" << endl;
}
void game()
{
	int guess = 0;
	int rnd = rand() % 100 + 1;
	while (1)
	{

		cin >> guess;
		if (guess > rnd)
		{
			cout << "大" << endl;
		}
		else if (guess < rnd)
		{
			cout << "小" << endl;
		}
		else
		{
			cout << "perfect" << endl;
			break;
		}
	}

}
int main()
{
again:
	srand((unsigned int)time(NULL));
	int ipt = 0;
	menu();
	cin >> ipt;
	if (ipt == 1)
	{
		cout << "start" << endl;
		game();
	}
	else if (ipt == 0)
	{
		cout << "exit" << endl;
	}
	else
	{
		cout << "input again" << endl;
		goto again;
	}

	return 0;
}
//完全体请看c语言文件


//3.2 do-while语句
int main()
{
	int num = 0;
	do
	{
		cout << num << endl;
		num++;
	} while (num < 10);

	return 0;
}

//例题 水仙花数：一个三位数它的每个位上的数字的三次幂之和等于它本身
int judge(int x)
{
	int a = x % 10;
	int b = (x / 10) % 10;
	int c = x / 100;
	int sum = pow(a, 3) + pow(b, 3) + pow(c, 3);
	if (sum == x)
		return 1;
	else
		return 0;

}
int main()
{
	int i = 0;
	for (i = 100; i < 1000; i++)
	{
		if (judge(i))
		{
			cout << i << endl;
		}
	}

	return 0;
}


//3.3 for语句
int  main()
{
	int n = 0;
	for (n = 1; n <= 100; n++)
	{
		if (n % 7 == 0 || n % 10 == 7 || (n / 10) % 7 == 0)
			cout << n << endl;
	}

	return 0;
}


//4. 嵌套循环
int  main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "* ";
		}
		cout << '\n';//此处写  cout << endl;  亦可
	}

	return 0;
}

int main()
{
	int i = 0, j = 0;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %2d ", i, j, i * j);

		}
		printf("\n");
	}

	return 0;
}
int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "=" << j * i << " ";
		}
		cout << endl;
	}

	return 0;
}


//5.跳转语句
//5.1 break语句
//break使用时机:
//1.出现在switch条件语句中，作用是终止case并跳出switch    注意这里没有if语句
//2.出现在循环语句中，作用是跳出当前的循环语句
//3.出现在嵌套循环中，跳出最近的内层循环语句

//5.2 continue语句    应用于循环语句

//5.3 goto语句