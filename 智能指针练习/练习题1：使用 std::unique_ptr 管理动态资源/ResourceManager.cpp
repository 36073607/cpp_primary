#define _CRT_SECURE_NO_WARNINGS
#include "ResourceManager.h"

ResourceManager::ResourceManager(): ptr(nullptr) {}

ResourceManager::ResourceManager(int val) : ptr(std::make_unique<int>(val)) {}

ResourceManager::ResourceManager(ResourceManager&& other) noexcept : ptr(std::move(other.ptr)) 
{
	other.ptr = nullptr;
}

ResourceManager& ResourceManager::operator=(ResourceManager&& other) noexcept
{
	if (this != &other)
	{
		ptr = std::move(other.ptr);
		other.ptr = nullptr;
	}
	return *this;
}

int ResourceManager::getValue() const
{
	return *ptr;
}

void ResourceManager::setValue(int newValue)
{
	*ptr = newValue;
}

