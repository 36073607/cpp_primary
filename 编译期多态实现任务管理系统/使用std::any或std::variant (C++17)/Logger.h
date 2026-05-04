#pragma once

#include <string>
#include <mutex>
#include <fstream>

class Logger
{
public:
	//获取单例
	static Logger& getInstance();
	//记录日志
	void log(const std::string& msg);
	~Logger();

private:
	Logger();
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
	std::ofstream logFile;
	std::mutex mtx;
};

