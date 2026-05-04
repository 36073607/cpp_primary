#include "Logger.h"
#include "TaskManager.h"
#include "Command.h"
#include <unordered_map>
#include <functional>

int main() {
    TaskManager taskmanager;
    
    //法一：虚基类
    /*std::unordered_map<std::string, std::unique_ptr<CommandBase>> commands;
    commands["add"] = std::make_unique<AddCommand>(taskmanager);
    commands["remove"] = std::make_unique<RemoveCommand>(taskmanager);
    commands["list"] = std::make_unique<ListCommand>(taskmanager);
    commands["update"] = std::make_unique<UpdateCommand>(taskmanager);*/

    //法二；类型擦除
    std::unordered_map<std::string, std::function<void(const std::string&)>> commands;
    //伪闭包
    auto add_command = std::make_shared<AddCommand>(taskmanager);
    auto remove_command = std::make_shared<RemoveCommand>(taskmanager);
    auto list_command = std::make_shared<ListCommand>(taskmanager);
    auto update_command = std::make_shared<UpdateCommand>(taskmanager);

    commands["add"] = [add_command](const std::string& args) {add_command->execute(args); };
    commands["remove"] = [remove_command](const std::string& args) {remove_command->execute(args); };
    commands["list"] = [list_command](const std::string& args) {list_command->execute(args); };
    commands["update"] = [update_command](const std::string& args) {update_command->execute(args); };

    std::cout << "欢迎使用任务管理系统!" << std::endl;
    std::cout << "可用命令：add, remove, list, update, exit" << std::endl;
    std::string ipt;
    while (1) {
        std::cout << "\n> ";
        std::getline(std::cin, ipt);
        if (ipt.empty()) continue;

        //分隔命令
        size_t spacePos = ipt.find(" ");
        std::string cmd = ipt.substr(0, spacePos);
        std::string args;
        if (spacePos != std::string::npos) {
            args = ipt.substr(spacePos + 1);
        }

        if (cmd == "exit") {
            std::cout << "退出程序" << std::endl;
            break;
        }

        auto it = commands.find(cmd);
        if (it != commands.end()) {
            it->second(args);
        }
        else {
            std::cout << "未知命令: " << cmd << std::endl;
        }
    }

    return 0;
}

