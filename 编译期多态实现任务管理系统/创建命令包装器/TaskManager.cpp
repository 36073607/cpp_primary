#include "TaskManager.h"
#include "Logger.h"
#include <iostream>

TaskManager::TaskManager() : nextId(1)
{
	loadTasks();//加载日志
}

void TaskManager::addTask(const std::string& des, int pri, const std::string& date)
{
	Task task;
	task.id = nextId++;
	task.description = des;
	task.priority = pri;
	task.dueDate = date;
	tasks.push_back(task);

	Logger::getInstance().log("Task added: " + task.toString());//添加一条日志
	saveTasks();//保存任务到文件
}

void TaskManager::removeTask(int id)
{
	auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
		return task.id == id;
		});

	if (it != tasks.end()) {
		tasks.erase(it);
		Logger::getInstance().log("Task deleted: " + it->toString());//打印日志,注意：it还在作用域内，可以使用toString()
		saveTasks();//保存任务到文件
	}
	else {
		Logger::getInstance().log("Task not found");
		std::cout << "Task not found" << std::endl;
	}
}

void TaskManager::updateTask(int id, const std::string& des, int pri, const std::string& date)
{
	auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
		return task.id == id;
		});

	if (it != tasks.end()) {
		it->description = des;
		it->priority = pri;
		it->dueDate = date;
		Logger::getInstance().log("Task updated: " + it->toString());
		saveTasks();
	}
	else {
		Logger::getInstance().log("Task not found");
		std::cout << "Task not found" << std::endl;
	}
}

void TaskManager::listTasks(int sortOpt)
{
	//防止影响源数据，此处创建一个副本
	std::vector<Task> cpy = tasks;
	switch (sortOpt) {
	case 1:
		sort(cpy.begin(), cpy.end(), compareByPriority);
		break;
	case 2:
		sort(cpy.begin(), cpy.end(), compareByDueDate);
		break;
	default:
		break;
	}

	for (const auto& task : cpy) {
		std::cout << task.toString() << std::endl;
	}
}

void TaskManager::loadTasks() {
	std::ifstream inFile("tasks.txt");
	if (!inFile.is_open()) {
		Logger::getInstance().log("Failed to open tasks.txt");
		return;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		//line中的数据格式为：id,描述,优先级,截止日期  现在注意移除这个','
		std::istringstream iss(line);
		Task task;

		//方法一：
		char delimiter;//分隔符
		iss >> task.id >> delimiter;

		//方法二：
		std::getline(iss, task.description, ',');
		
		//方法三：
		iss >> task.priority;
		iss.ignore(1);

		iss >> task.dueDate;

		tasks.push_back(task);
		if (task.id >= nextId) nextId = task.id + 1;
	}

	inFile.close();//关闭文件
	//打印一条日志
	Logger::getInstance().log("Tasks loaded successfully.");
}

void TaskManager::saveTasks() const
{
	std::ofstream outfile("tasks.txt");
	if (!outfile.is_open()) {
		Logger::getInstance().log("Failed to open tasks.txt");
		return;
	}

	for (const auto& task : tasks) {
		outfile << task.id << "," << task.description << "," << task.priority << "," << task.dueDate << std::endl;
	}

	outfile.close();
	Logger::getInstance().log("Tasks saved successfully.");
}

bool TaskManager::compareByPriority(const Task& a, const Task& b)
{
	return a.priority < b.priority;
}

bool TaskManager::compareByDueDate(const Task& a, const Task& b)
{
	return a.dueDate < b.dueDate;
}

