#define _CRT_SECURE_NO_WARNINGS
//数据类型
//1.整型 整数类型的数据
//short（短整型） 占用2字节
//int（整型） 占用4字节
//long（长整型） windows为4字节，linux为4字节（32位），8字节（64位）
//long long（长长整型） 8字节
//注：占用空间大小不同，导致 存储的整型数据取值的范围 不同
//例如int 取值范围 （-2^31 -- 2^31-1）



//2. sizeof关键字
//作用 统计数据类型所占内存大小
#include <iostream>
using namespace std;
int main()
{
	cout << "short所占内存：" << sizeof(short) << endl;
	cout << "int所占内存：" << sizeof(int) << endl;
	cout << "long所占内存：" << sizeof(long) << endl;
	cout << "long long所占内存：" << sizeof(long long) << endl;

	int num = 10;
	cout << sizeof(num) << endl;

	return 0;
}



//3. 实型（浮点型）
//单精度float 占用4字节   有效数字范围：7位有效数字
//双精度double 占用8字节  有效数字范围：15-16位有效数字
//默认情况下 输出一个小数，会显示6位有效数字
#include <iostream>
using namespace std;
int main()
{
	float num1 = 0.0f;//默认浮点数为双精度，加f使其为单精度
	double num2 = 0.0;

	//科学计数法
	float f1 = 3e2;//3*10^2     300
	float f2 = 3e-2;//3*10^-2   0.03

	return 0;
}


//4. 字符型
//作用 字符型变量用于显示单个字符
//语法 char ch = 'a';

//注意1:在显示字符型变量时，用单引号将字符括起来，不要用双引号
//注意2:单引号内只能有一个字符，不可以是字符串！！！（c语言中亦适用）

//c和cpp中字符型变量只占用1个字节
//字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元

#include <iostream>
using namespace std;
int main()
{
	char ch = 'a';
	//查看字符型变量对应的ASCII码
	cout << (int)ch << endl;

	//a-97  A-65     相差32

	return 0;
}


//5. 转移字符
#include <iostream>
using namespace std;
int main()
{
	//换行符 \n

	cout << "hello" << endl;
	cout << "hello\n";

	//反斜杠 \\

	cout << "\\" << endl;  //打印结果为 \

	//水平制表符:最大作用是输出时格式整齐
	cout << "aaa\thello" << endl;// \t及之前的字符共占8个位置 aaa五个空格hello
	cout << "aaaa\thello" << endl;// aaaa四个空格hello

	return 0;
}



//6. 字符串型
//C风格字符串：char ch[] = "abcde";
//C++风格：string ch = "abcde";
#include <iostream>
#include <string>//C++风格写法要注意引用头文件
using namespace std;
int main()
{
	char arr[] = "abcde";
	cout << arr << endl;

	string arr1 = "abcdef";
	cout << arr1 << endl;//C++风格写法要注意引用头文件


	return 0;
}


//7. 布尔类型   占用1个字节
//true(本质是1)   false(本质是0)
#include <iostream>
using namespace std;
int main()
{
	bool flag = true;
	cout << flag << endl;

	flag = false;
	cout << flag << endl;


	return 0;
}


//8. 数据的输入(scanf)
//作用 用于从键盘获取数据
//关键字 cin :   cin >> 变量;
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a = 0;
	cout << "请对a赋值" << endl;
	cin >> a;
	cout << "a=" << a << endl;

	string ch = "0";
	cin >> ch;
	cout << ch << endl;

	bool flag = false;
	cin >> flag;
	cout << flag << endl;//bool类型只要是非零的值都代表真，输入英文时输出0

	return 0;
}
//总结：cin --> c in
//      cout --> c out
