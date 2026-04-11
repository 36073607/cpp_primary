#include <iostream>

#include "ResourceManager.h"

int main() {
    std::cout << "Calling a parameterized constructor =======================================" << std::endl;

    const auto resourceManager = std::make_unique<ResourceManager>(10);
    std::cout << "Initial Value : " << resourceManager->getValue() << std::endl;
    resourceManager->setValue(20);
    std::cout << "Updated Value : " << resourceManager->getValue() << std::endl;

    std::cout << "Calling a parameterized constructor =======================================" << std::endl;

    const auto resourceManager2(std::make_unique<ResourceManager>(40));
    std::cout << "Initial Value : " << resourceManager2->getValue() << std::endl;

    std::cout << "Calling a parameterized constructor =======================================" << std::endl;

    ResourceManager resourceManager3(50);
    std::cout << "Updated Value : " << resourceManager3.getValue() << std::endl;

    std::cout << "Calling the move constructor=======================================" << std::endl;

    auto resourceManager4(std::move(resourceManager3));
    std::cout << "Initial Value : " << resourceManager4.getValue() << std::endl;

    std::cout <<
        "First call the no-argument constructor, then call the overloaded move assignment operator "
        "======================================="
        << std::endl;

    ResourceManager resourceManager5;
    resourceManager5 = std::move(resourceManager4);
    std::cout << "Initial Value : " << resourceManager5.getValue() << std::endl;

    std::cout << "=======================================" << std::endl;

    return 0;
}
