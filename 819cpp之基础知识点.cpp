#include <iostream>
using namespace std;
//一 梦开始的地方
int main()
{
	cout << "hello world" << endl;
	system("pause");//经本人验证，这句话可有可无

	return 0;
}


//二 注释


//三 变量
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	cout << "a=" << a << endl;

	system("pause");
	return 0;
}


//四 常量
//1.#define 宏常量: #define 常量名 常量值
// 通常在文件上方定义，表示一个常量
//2.const修饰的变量: const 数据类型 常量名 = 常量值
// 通常在变量定义1前加关键字const，修饰该变量为常量，不可修改
//其一
#include <iostream>
using namespace std;
#define Trial 7
int main()
{
	cout << "一周总共有：" << Trial << "天" << endl;

	system("pause");
	return 0;
}
//其二
#include <iostream>
using namespace std;
int main()
{
	const int week = 7;
	cout << "共" << week << "天" << endl;

	system("pause");
	return 0;
}



//五 关键字


//六 标识符命名规则
//1.标识符不能是关键字
//2.标识符只能由字母、数字、下划线组成
//3.第一个字符必须为字母或下划线
//4.标识符中字母区分大小写
//建议：给变量起名的时候，最好能够做到见名知意