#define _CRT_SECURE_NO_WARNINGS

#include "SingleOnceFlag_sptr.h"
#include <thread>
#include <mutex>

int main()
{
	std::mutex mtx;

	std::thread t1([&]() {
		SingleOnceFlag_sptr::GetInst();
		std::lock_guard<std::mutex> lock(mtx);//采用RAII思想加锁与解锁：在构造时加锁，离开{}时解锁
		std::cout << "s1 addr is " << SingleOnceFlag_sptr::GetInst() << std::endl;
		});

	std::thread t2([&]() {
		SingleOnceFlag_sptr::GetInst();
		mtx.lock();
		std::cout << "s2 addr is " << SingleOnceFlag_sptr::GetInst() << std::endl;
		mtx.unlock();
		});

	t1.join();
	t2.join();

	return 0;
}