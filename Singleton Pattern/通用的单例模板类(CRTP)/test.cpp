#define _CRT_SECURE_NO_WARNINGS

#include "Singleton.h"
#include <thread>
#include <mutex>

int main()
{
	std::mutex mtx;

	std::thread t1([&]() {
		SingleNet::GetInst();
		std::lock_guard<std::mutex> lock(mtx);//采用RAII思想加锁与解锁：在构造时加锁，离开{}时解锁
		std::cout << "s1 addr is " << SingleNet::GetInst() << std::endl;
		});

	std::thread t2([&]() {
		SingleNet::GetInst();
		mtx.lock();
		std::cout << "s2 addr is " << SingleNet::GetInst() << std::endl;
		mtx.unlock();
		});

	t1.join();
	t2.join();

	return 0;
}