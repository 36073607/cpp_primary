#pragma once

#include <iostream>
#include <string>
#include <memory>

class CommandBase {
public:
	virtual void execute(std::string& args) = 0;
};

template <typename Derived>
class Command : public CommandBase {
public:
	void execute(std::string& args) {
		(static_cast<Derived*>(this))->executeImpl(args);
	}
};

#include "TaskManager.h"
#include "Logger.h"
class AddCommand : public Command<AddCommand> {
public:
	AddCommand(TaskManager& manager) : taskManager(manager) {}

	//用户传来一条指令： 描述,优先级,日期
	void executeImpl(const std::string& args) {
		//解析指令
		size_t pos1 = args.find(',');
		size_t pos2 = args.find(',', pos1 + 1);
		if (pos1 == std::string::npos || pos2 == std::string::npos) {
			Logger::getInstance().log("参数格式错误");
			return;
		}

		std::string des = args.substr(0, pos1);
		int pri = std::stoi(args.substr(pos1 + 1, pos2 - pos1 - 1));
		std::string date = args.substr(pos2 + 1);

		taskManager.addTask(des, pri, date);
		std::cout << "任务添加成功" << std::endl;
	}

private:
	TaskManager& taskManager;
};


class RemoveCommand : public Command<RemoveCommand> {
public:
	RemoveCommand(TaskManager& manager) : taskManager(manager) {}

	void executeImpl(const std::string& args) {
		try {
			size_t pos;
			int id = std::stoi(args, &pos);
			if (pos != args.size()) {
				Logger::getInstance().log("参数格式错误");
				return;
			}
			taskManager.removeTask(id);
			std::cout << "任务删除成功" << std::endl;
		}
		catch (const std::invalid_argument& e) {
			Logger::getInstance().log("参数格式错误");
			return;
		}
		catch (const std::out_of_range& e) {
			Logger::getInstance().log("超出范围");
			return;
		}
	}

private:
	TaskManager& taskManager;
};


class ListCommand : public Command<ListCommand> {
public:
	ListCommand(TaskManager& manager) :taskManager(manager) {}

	void executeImpl(const std::string& args) {
		try {
			size_t pos;
			int sortopt = 0;
			sortopt = std::stoi(args, &pos);
			if (pos != args.size()) {
				Logger::getInstance().log("参数格式错误");
				return;
			}
			taskManager.listTasks(sortopt);
			std::cout << "任务排序成功" << std::endl;
		}
		catch (const std::invalid_argument& e) {
			Logger::getInstance().log("参数格式错误");
			return;
		}
		catch (const std::out_of_range& e) {
			Logger::getInstance().log("超出范围");
			return;
		}
	}

private:
	TaskManager taskManager;
};


class UpdateCommand : public Command<UpdateCommand> {
public:
	UpdateCommand(TaskManager& manager) : taskManager(manager) {}

	void executeImpl(const std::string& args) {
		try {
			size_t pos1 = args.find(',', 0);
			size_t pos2 = args.find(',', pos1 + 1);
			size_t pos3 = args.find(',', pos2 + 1);

			if (pos1 == std::string::npos || pos2 == std::string::npos || pos3 == std::string::npos) {
				Logger::getInstance().log("参数格式错误");
				return;
			}

			int id = std::stoi(args.substr(0, pos1));
			std::string des = args.substr(pos1 + 1, pos2 - pos1 - 1);
			int pri = std::stoi(args.substr(pos2 + 1, pos3 - pos2 - 1));
			std::string date = args.substr(pos3 + 1);
			taskManager.updateTask(id, des, pri, date);
			std::cout << "任务更新成功" << std::endl;
		}
		catch (const std::invalid_argument& e) {
			Logger::getInstance().log("参数格式错误");
			return;
		}
		catch (const std::out_of_range& e) {
			Logger::getInstance().log("超出范围");
			return;
		}
	}

private:
	TaskManager taskManager;
};

