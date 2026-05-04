#pragma once

#include "Task.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>


class TaskManager
{
public:
	TaskManager();
	void addTask(const std::string& des, int pri, const std::string& date);
	void removeTask(int id);
	void updateTask(int id, const std::string& des, int pri, const std::string& date);
	void listTasks(int sortOpt);//1-按优先级升序 2-按日期升序
	void loadTasks();
	void saveTasks() const;

private:
	std::vector<Task> tasks;
	int nextId;
	static bool compareByPriority(const Task& a, const Task& b);
	static bool compareByDueDate(const Task& a, const Task& b);
};

