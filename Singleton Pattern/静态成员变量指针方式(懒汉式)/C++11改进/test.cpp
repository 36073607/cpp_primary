#define _CRT_SECURE_NO_WARNINGS

#include "SingleOnceFlag.h"
#include <thread>
#include <mutex>

int main()
{
	auto inst = SingleOnceFlag::GetInst();

	std::mutex mtx;

	std::thread t1([&]() {
		SingleOnceFlag::GetInst();
		std::lock_guard<std::mutex> lock(mtx);//采用RAII思想加锁与解锁：在构造时加锁，离开{}时解锁
		std::cout << "s1 addr is " << SingleOnceFlag::GetInst() << std::endl;
		});

	std::thread t2([&]() {
		SingleOnceFlag::GetInst();
		mtx.lock();
		std::cout << "s2 addr is " << SingleOnceFlag::GetInst() << std::endl;
		mtx.unlock();
		});

	t1.join();
	t2.join();

	return 0;
}