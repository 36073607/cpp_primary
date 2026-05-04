#pragma once

#include <string>
#include <sstream>
#include <iomanip>

class Task {
public:
	int id;
	std::string description;
	int priority;
	std::string dueDate;//截止日期

	std::string toString() const {
		std::ostringstream oss;
		oss << "ID: " << id << ", 描述: " << description << ", 优先级: " << priority << ", 截止日期: " << dueDate;
		return oss.str();
	}
};