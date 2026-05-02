#pragma once

#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <fstream>
#include <atomic>
#include <sstream>
#include <vector>
#include <stdexcept>


//辅助函数，将单个参数转化为字符串
template<typename T>
std::string to_string_helper(T&& arg) {
	std::ostringstream oss;
	oss << std::forward<T>(arg);
	return oss.str();
}


class LogQueue {
public:
	void push(const std::string& msg) {
		std::lock_guard<std::mutex> lock(_mtx);
		_queue.push(msg);
		_cond_var.notify_one();//唤醒一个正在 pop 中等待的消费者线程
	}

	bool pop(std::string& msg) {
		std::unique_lock<std::mutex> lock(_mtx);
		_cond_var.wait(lock, [this]() {
			return !_queue.empty() || _is_shutdown;
			});
		//消费逻辑
		// 被唤醒后，先别急着走，看看情况
		if (_is_shutdown && _queue.empty()) return false;
		// 如果队列里还有货，不管是不是要关闭，先把剩下的干完！
		msg = _queue.front();
		_queue.pop();
		return true;
	}

	void shutdown() {
		std::lock_guard<std::mutex> lock(_mtx);
		_is_shutdown = true;
		_cond_var.notify_all();
	}

private:
	std::queue<std::string> _queue;// 底层队列，非线程安全
	std::mutex _mtx; // 互斥锁，保护 queue_ 和 is_shutdown_
	std::condition_variable _cond_var;// 条件变量，用于线程间的等待/唤醒机制
	bool _is_shutdown = false;// 关闭标志，用于优雅退出
};


enum class LogLevel {
	INFO, DEBUG, WARN, ERROR
};

class Logger {
public:
	Logger(const std::string& filename) : log_file_(filename, std::ios::out | std::ios::app), exit_flag_(false) {
		if (!log_file_.is_open()) {
			throw std::runtime_error("打开文件失败");
		}

		worker_thread_ = std::thread([this]() {
			std::string msg;
			while (log_queue_.pop(msg)) {
				log_file_ << msg << std::endl;
			}
		});
	}

	//析构的公式写法
	~Logger() {
		exit_flag_ = false;
		log_queue_.shutdown();
		if (worker_thread_.joinable()) {
			worker_thread_.join();
		}

		if (log_file_.is_open()) {
			log_file_.close();
		}
	}

	template<typename... Args>
	void log(LogLevel level, const std::string& format, Args&&... args) {
		std::string level_str;
		switch (level) {
		case LogLevel::DEBUG :
			level_str = "[DEBUG] ";
			break;

		case LogLevel::INFO :
			level_str = "[INFO] ";
			break;

		case LogLevel::WARN :
			level_str = "[WARN] ";
			break;

		case LogLevel::ERROR :
			level_str = "[ERROR] ";
			break;
		}

		log_queue_.push(level_str + formatMessage(format, std::forward<Args>(args)...));//参数包展开，而不是折叠表达式
	}

private:
	template<typename... Args>
	std::string formatMessage(const std::string& format, Args&&... args) {
		std::vector<std::string> arg_strings = { to_string_helper(std::forward<Args>(args))... };//参数包展开，而不是折叠表达式
		std::ostringstream oss;
		size_t pos = 0;
		size_t placeholder = 0;
		size_t arg_idx = 0;

		while (pos < format.size() && arg_idx < arg_strings.size()) {
			placeholder = format.find("{}", pos);
			if (placeholder != std::string::npos)
			{
				oss << format.substr(pos, placeholder - pos);
				oss << arg_strings[arg_idx++];
				pos = placeholder + 2;
			}
			else 
				break;
		}

		oss << format.substr(pos);

		while (arg_idx < arg_strings.size())
			oss << arg_strings[arg_idx++];

		return oss.str();
	}


	LogQueue log_queue_;
	std::thread worker_thread_;
	std::ofstream log_file_;
	std::atomic<bool> exit_flag_;
};