#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"
#include <iostream>
#include <chrono>
#include <ctime>

Logger& Logger::getInstance()
{
	static Logger logger;
	return logger;
}

Logger::Logger()
{
	logFile.open("log.txt", std::ios::app);
	if (!logFile.is_open()) {
		throw std::runtime_error("Failed to open log file");
	}
}

void Logger::log(const std::string& msg)
{
	std::lock_guard<std::mutex> lock(mtx);
	if (logFile.is_open()) {
		auto now = std::chrono::system_clock::now();
		auto now_time = std::chrono::system_clock::to_time_t(now);
		logFile << std::ctime(&now_time) << ": " << msg << std::endl;
	}
}

Logger::~Logger()
{
	if (logFile.is_open()) {
		logFile.close();
	}
}
