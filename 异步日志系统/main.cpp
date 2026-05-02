#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Logger.h"

int main() {
    try {
        Logger logger("log.txt");

        logger.log(LogLevel::INFO, "Starting application.");

        int user_id = 42;
        std::string action = "login";
        double duration = 3.5;
        std::string world = "World";

        logger.log(LogLevel::INFO, "User {} performed {} in {} seconds.", user_id, action, duration);
        logger.log(LogLevel::WARN, "Hello {}", world);
        logger.log(LogLevel::ERROR, "This is a message without placeholders.");
        logger.log(LogLevel::DEBUG, "Multiple placeholders: {}, {}, {}.", 1, 2, 3);

        // 模拟一些延迟以确保后台线程处理完日志
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    catch (const std::exception& ex) {
        std::cerr << "日志系统初始化失败: " << ex.what() << std::endl;
    }

    return 0;
}