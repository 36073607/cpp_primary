#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1. ˳��ṹ������˳��ִ�У���������ת
//2. ѡ��ṹ
//2.1 if���
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

//2.2 ��Ŀ�����
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = a > b ? a : b;
	cout << "c = " << c << endl;

	//C++����Ŀ��������ص��Ǳ��������Լ�����ֵ
	(a > b ? a : b) = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	return 0;
}


//2.3 switch���
int main()
{
	int score = 0;
	cout << "�������" << endl;
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
//�ܽ᣺
//1.switch����б��ʽ����ֻ�������ͻ����ַ���
//2.case�����û��break����ô�����һֱ����ִ��
//3.switch��䲻���ж�����


//3.ѭ���ṹ
//3.1 while���
void menu()
{
	cout << "*****������(0/1)*****" << endl;
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
			cout << "��" << endl;
		}
		else if (guess < rnd)
		{
			cout << "С" << endl;
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
//��ȫ���뿴c�����ļ�


//3.2 do-while���
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

//���� ˮ�ɻ�����һ����λ������ÿ��λ�ϵ����ֵ�������֮�͵���������
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


//3.3 for���
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


//4. Ƕ��ѭ��
int  main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "* ";
		}
		cout << '\n';//�˴�д  cout << endl;  ���
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


//5.��ת���
//5.1 break���
//breakʹ��ʱ��:
//1.������switch��������У���������ֹcase������switch    ע������û��if���
//2.������ѭ������У�������������ǰ��ѭ�����
//3.������Ƕ��ѭ���У�����������ڲ�ѭ�����

//5.2 continue���    Ӧ����ѭ�����

//5.3 goto���