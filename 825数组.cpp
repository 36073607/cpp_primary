#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//数组特点：1.放在一块连续的内存空间中   2.数组中每个元素都是相同数据类型
//1. 一维数组
int main()
{
	int arr1[5];
	int arr2[5] = { 1,2,3,4,5 };
	int arr3[] = { 1,2,3 };

	cout << arr2[1] << endl;

	cout << "数组首地址为:" << arr1 << endl;//16进制
	cout << "数组首地址为:" << (int)arr1 << endl;//10进制
	cout << "数组中第一个元素地址为：" << (int)&arr1[0] << endl;

	//注：数组名是常量，不可以进行赋值操作

	//与C语言同理，如果想打印数组中每一个元素，需要用循环语句去写，不能直接写数组名

	return 0;
}
//练习1：五个将军称体重
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
//练习2: 
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


//2. 冒泡排序
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


//3. 二维数组
//1.初始化
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
//2.数组名
int main()
{
	//1.查看占用内存空间大小
	int arr[2][3] = { {1,2,3},{2,3,4}};
	cout << "二维数组占用内存空间大小为：" << sizeof(arr) << endl;//24
	cout << "二维数组第一行占用内存为：" << sizeof(arr[0]) << endl;//12
	cout << "二维数组第一个元素占用内存为：" << sizeof(arr[0][0]) << endl;//4

	double arr1[2][3] = { {1,2,3},{2,3,4} };
	cout << "二维数组占用内存空间大小为：" << sizeof(arr) << endl;//48

	//2.查看二维数组的首地址
	cout << "二维数组首地址为：" << (int)arr << endl;//这里用int将16进制转化为10进制
	cout << "二维数组第一行首地址为: " << (int)arr[0] << endl;
	cout << "二维数组第一个元素地址为：" << (int)&arr[0][0] << endl;//注意这里取元素的地址时需要加取地址符&，否则输出的将是一个数；这里的输出结果与上面一致

	//总结：二维数组首地址为第一个一维数组的地址

	return 0;
}


//4. 示例：考试成绩统计
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
		cout << " " << sum << endl;//总分
	}


	return 0;
}


