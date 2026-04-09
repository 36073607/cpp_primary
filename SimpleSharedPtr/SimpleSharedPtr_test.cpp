#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "SimpleSharedPtr.h"

// 测试类
class Test
{
public:
    Test(int val) : value(val)
    {
        std::cout << "Test Constructor: " << value << std::endl;
    }
    ~Test() 
    {
        std::cout << "Test Destructor: " << value << std::endl;
    }
    void show() const 
    {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value;
};

int main()
{

{
    std::cout << "Creating default constructed shared_ptr..." << std::endl;
    SimpleSharedPtr<Test> ptr1; // 默认构造
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;

    std::cout << "\nCreating shared_ptr with resource..." << std::endl;
    SimpleSharedPtr<Test> ptr2(new Test(100)); // 非默认构造
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    ptr2->show();

    std::cout << "\nCopying ptr2 to ptr3..." << std::endl;
    SimpleSharedPtr<Test> ptr3 = ptr2; // 拷贝构造
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;
    ptr3->show();

    std::cout << "\nAssigning ptr3 to ptr1..." << std::endl;
    ptr1 = ptr3; // 拷贝赋值
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;

    std::cout << "\nResetting ptr2..." << std::endl;
    ptr2.reset(new Test(200)); // 重新指向新的对象
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    ptr2->show();
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;

    std::cout << "\nExiting scope..." << std::endl;
} // ptr2, ptr1, ptr3 离开作用域

    std::cout << "End of main." << std::endl;
    return 0;
}