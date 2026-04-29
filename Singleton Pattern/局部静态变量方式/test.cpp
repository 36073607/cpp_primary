#define _CRT_SECURE_NO_WARNINGS

#include "Singleton1.h"
#include <thread>
#include <mutex>

int main()
{
	//std::cout << "s1 addr is " << &Single::GetInst() << std::endl;
	//std::cout << "s2 addr is " << &Single::GetInst() << std::endl;

	std::mutex mtx;

	std::thread t1([&]() {
		Single::GetInst();
		std::lock_guard<std::mutex> lock(mtx);//采用RAII思想加锁与解锁：在构造时加锁，离开{}时解锁
		std::cout << "s1 addr is " << &Single::GetInst() << std::endl;
		});

	std::thread t2([&]() {
		Single::GetInst();
		mtx.lock();
		std::cout << "s2 addr is " << &Single::GetInst() << std::endl;
		mtx.unlock();
		});

	t1.join();
	t2.join();

	return 0;
}