#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//�����ص㣺1.����һ���������ڴ�ռ���   2.������ÿ��Ԫ�ض�����ͬ��������
//1. һά����
int main()
{
	int arr1[5];
	int arr2[5] = { 1,2,3,4,5 };
	int arr3[] = { 1,2,3 };

	cout << arr2[1] << endl;

	cout << "�����׵�ַΪ:" << arr1 << endl;//16����
	cout << "�����׵�ַΪ:" << (int)arr1 << endl;//10����
	cout << "�����е�һ��Ԫ�ص�ַΪ��" << (int)&arr1[0] << endl;

	//ע���������ǳ����������Խ��и�ֵ����

	//��C����ͬ��������ӡ������ÿһ��Ԫ�أ���Ҫ��ѭ�����ȥд������ֱ��д������

	return 0;
}
//��ϰ1���������������
int main()
{
	int arr[5] = { 0 };
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = arr[0];
	for (i = 1; i < 5; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("%d\n", max);

	return 0;
}
//��ϰ2: 
void swap(int* arr, int left, int right)
{
	int p = 0;
	while (left < right)
	{
		p = arr[left];
		arr[left] = arr[right];
		arr[right] = p;
		left++;
		right--;
	}
}
int main()
{
	int arr[5] = { 0 };
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int left = 0;
	swap(arr, left, right);

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
} 

void swap(int* arr, int left, int right)
{
	int p = 0;

	p = arr[left];
	arr[left] = arr[right];
	arr[right] = p;
	if (left < right)
		swap(arr, left + 1, right - 1);

}
int main()
{
	int arr[5] = { 0 };
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int left = 0;
	swap(arr, left, right);

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}


//2. ð������
int main()
{
	int arr[9] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}

		}

	}

	for (int x = 0; x < sz; x++)
	{
		printf("%d ", arr[x]);
	}

	return 0;
}


//3. ��ά����
//1.��ʼ��
int main()
{
	int arr[2][3];

	int arr1[2][3] = { {1,2,3},{4,5,6} };

	int arr2[2][3] = { 1,2,3,4,5,6 };

	int arr3[][3] = { 1,2,3,4,5,6 };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr2[i][j] << " ";
		}
	}


	return 0;
}
//2.������
int main()
{
	//1.�鿴ռ���ڴ�ռ��С
	int arr[2][3] = { {1,2,3},{2,3,4}};
	cout << "��ά����ռ���ڴ�ռ��СΪ��" << sizeof(arr) << endl;//24
	cout << "��ά�����һ��ռ���ڴ�Ϊ��" << sizeof(arr[0]) << endl;//12
	cout << "��ά�����һ��Ԫ��ռ���ڴ�Ϊ��" << sizeof(arr[0][0]) << endl;//4

	double arr1[2][3] = { {1,2,3},{2,3,4} };
	cout << "��ά����ռ���ڴ�ռ��СΪ��" << sizeof(arr) << endl;//48

	//2.�鿴��ά������׵�ַ
	cout << "��ά�����׵�ַΪ��" << (int)arr << endl;//������int��16����ת��Ϊ10����
	cout << "��ά�����һ���׵�ַΪ: " << (int)arr[0] << endl;
	cout << "��ά�����һ��Ԫ�ص�ַΪ��" << (int)&arr[0][0] << endl;//ע������ȡԪ�صĵ�ַʱ��Ҫ��ȡ��ַ��&����������Ľ���һ�����������������������һ��

	//�ܽ᣺��ά�����׵�ַΪ��һ��һά����ĵ�ַ

	return 0;
}


//4. ʾ�������Գɼ�ͳ��
int main()
{
	int i = 0, j = 0;
	int arr[3][3] = { 0 };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		int sum = 0;
		for (j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
			sum = arr[i][j] + sum;
		}
		cout << " " << sum << endl;//�ܷ�
	}


	return 0;
}


