#define _CRT_SECURE_NO_WARNINGS

#include "Singleton_hungry.h"
#include <thread>
#include <mutex>

int main()
{
	auto inst = Single_hungry::GetInst();

	std::mutex mtx;

	std::thread t1([&]() {
		Single_hungry::GetInst();
		std::lock_guard<std::mutex> lock(mtx);//采用RAII思想加锁与解锁：在构造时加锁，离开{}时解锁
		std::cout << "s1 addr is " << Single_hungry::GetInst() << std::endl;
		});

	std::thread t2([&]() {
		Single_hungry::GetInst();
		mtx.lock();
		std::cout << "s2 addr is " << Single_hungry::GetInst() << std::endl;
		mtx.unlock();
		});

	t1.join();
	t2.join();

	return 0;
}