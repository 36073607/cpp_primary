#define _CRT_SECURE_NO_WARNINGS
//C++ 中常见的几种输入字符串的方法如下：
//cin、cin.get()、cin.getline()、getline()、gets()、getchar()

//1. cin >>
//用法一：最常用、最基本的用法，输入一个数字：
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << a + b << endl;
}

//输入：2[回车]3[回车]
//输出：5
​
//用法二：接受一个字符串，遇“空格”、“Tab”、“回车”都结束
#include <iostream>
using namespace std;
int main()
{
	char a[20];
	cin >> a;
	cout << a << endl;
}
​
//输入：jkljkljkl
//输出：jkljkljkl
​
//输入：jkljkl jkljkl //遇空格结束，所以不能输入多个单词
//输出：jkljkl


//2. cin.get()
//用法一：cin.get(字符变量名)可以用来接收字符
#include <iostream>
using namespace std;
int main()
{
    char ch;
    ch = cin.get(); //或者cin.get(ch);只能获取一个字符
    cout << ch << endl;
}
​
//输入：jljkljkl
//输出：j

//用法二：cin.get(字符数组名，接收字符数)用来接收一行字符串，可以接收空格
#include <iostream>
using namespace std;
int main()
{
    char a[20];
    cin.get(a, 20); //有些类似getline。可以输入多个单词，中间空格隔开。
    cout << a << endl;
}
​
//输入：jkl jkl jkl
//输出：jkl jkl jkl
​
//输入：abcdeabcdeabcdeabcdeabcde （输入25个字符）
//输出：abcdeabcdeabcdeabcd （接收19个字符+1个'\0'）
​​
//用法三：cin.get(无参数)没有参数主要是用于舍弃输入流中的不需要的字符, 或者舍弃回车, 弥补cin.get(字符数组名, 接收字符数目)的不足.
#include <iostream>
using namespace std;
int main(void)
{

    char arr[10];
    cin.get(arr, 10);
    cin.get();//用于吃掉回车，相当于getchar();
    cout << arr << endl;
    cin.get(arr, 5);
    cout << arr << endl;
    system("pause");
    return 0;
}

//输入abcdefghi
//输出abcdefghi
//输入abcde
//输出abcd
//请按任意键继续

#include <iostream>
using namespace std;
int main(void)
{

    char arr[10];
    cin.get(arr, 10);
    //cin.get();//用于吃掉回车，相当于getchar(); 现在把这行注释掉试试看
    cout << arr << endl;
    cin.get(arr, 5);
    cout << arr << endl;
    system("pause");
    return 0;
}

//输入abcdefghi
//输出abcdefghi
//请按任意键继续


//3.cin.getline()
//cin.getline() : 接受一个字符串，可以接收空格并输出
#include <iostream>
using namespace std;
int main()
{
    char m[20];
    cin.getline(m, 5); //与上面基本相同。
    cout << m << endl;
}
​
//输入：jkljkljkl
//输出：jklj
//接受5个字符到m中，其中最后一个为'\0'，所以只看到4个字符输出；​
//如果把5改成20：
//输入：jkljkljkl
//输出：jkljkljkl
//​
//输入：jklf fjlsjf fjsdklf
//输出：jklf fjlsjf fjsdklf

//延伸：
//cin.getline()实际上有三个参数，cin.getline(接受字符串到m, 接受个数5, 结束字符)
//当第三个参数省略时，系统默认为'\0' 是‘ / n’吧。
//如果将例子中cin.getline()改为cin.getline(m, 5, 'a'); 当输入jlkjkljkl时输出jklj，输入jkaljkljkl时，输出jk
//当用在多维数组中的时候，也可以用cin.getline(m[i], 20)之类的用法：​
#include<iostream>
#include<string>
using namespace std;​
int main()
{
    char m[3][20];
    for (int i = 0; i < 3; i++)
    {
        cout << "\n请输入第" << i + 1 << "个字符串：" << endl;
        cin.getline(m[i], 20);
    }
    cout << endl;
    for (int j = 0; j < 3; j++)
        cout << "输出m[" << j << "]的值:" << m[j] << endl;
    ​
}​
//测试：
//
//请输入第1个字符串：
//kskr1
//​
//请输入第2个字符串：
//kskr2
//​
//请输入第3个字符串：
//kskr3
//​
//输出m[0]的值:kskr1
//输出m[1]的值 : kskr2
//输出m[2]的值 : kskr3


//4. getline()
//getline() ：接受一个字符串，可以接收空格并输出，需包含 #include<string>。
#include<iostream>
#include<string>
using namespace std;
    int main()
    {
        string str;
        getline(cin, str);
        cout << str << endl;
    }
    ​
//测试：

//输入：jkljkljkl //VC6中有个bug,需要输入两次回车。
//输出：jkljkljkl
//​
//输入：jkl jfksldfj jklsjfl
//输出：jkl jfksldfj jklsjfl


//5. gets()
//gets()： 接受一个字符串，可以接收空格并输出，需包含 #include<string>。
#include<iostream>
#include<string>
using namespace std;
int main()
{
    char m[20];
    gets(m); //不能写成m=gets();
    cout << m << endl;
}
//测试：
//
//输入：jkljkljkl
//输出：jkljkljkl
//
//输入：jkl jkl jkl
//输出：jkl jkl jkl
  ​
//类似cin.getline()里面的一个例子，gets()同样可以用在多维数组里面：​
#include<iostream>
#include<string>
using namespace std;
int main()
{
    char m[3][20];
    for (int i = 0; i < 3; i++)
    {
        cout << "\n请输入第" << i + 1 << "个字符串：" << endl;
        gets(m[i]);
    }
        ​
    cout << endl;
    for (int j = 0; j < 3; j++)
    cout << "输出m[" << j << "]的值:" << m[j] << endl;
}
//测试：
//
//请输入第1个字符串：
//kskr1
//        ​
//请输入第2个字符串：
//kskr2
//        ​
//请输入第3个字符串：
//kskr3
//        ​
//输出m[0]的值:kskr1
//输出m[1]的值 : kskr2
//输出m[2]的值 : kskr3
        ​
//自我感觉gets()和cin.getline()的用法很类似，只不过cin.getline()多一个参数罢了；​
//这里顺带说明一下，对于本文中的这个kskr1, kskr2, kskr3的例子，对于cin >> 也可以适用，原因是这里输入的没有空格，如果输入了空格，比如“ks kr jkl[回车]”那么cin就会已经接收到3个字符串，“ks, kr, jkl”；再如“kskr 1[回车]kskr 2[回车]”，那么则接收“kskr, 1, kskr”；这不是我们所要的结果！而cin.getline()和gets()因为可以接收空格，所以不会产生这个错误；


//6.getchar()
//getchar() ：接受一个字符，需包含 #include<string>。
#include<iostream>
using namespace std;
int main()
{
    char ch;
    ch = getchar(); //不能写成getchar(ch);
    cout << ch << endl;
}
        ​
//测试：
//输入：jkljkljkl
//输出：j
//            ​
//getchar()是C语言的函数，C++也可以兼容，但是尽量不用或少用；