#pragma once

#ifndef _ResourceManager_
#define _ResourceManager_

#include <iostream>
#include <memory>

class ResourceManager
{
private:
	std::unique_ptr<int> ptr;

public:
	ResourceManager();
	explicit ResourceManager(int val);
	~ResourceManager() = default;
	ResourceManager(const ResourceManager& other) = delete;
	ResourceManager& operator=(const ResourceManager& other) = delete;
	ResourceManager(ResourceManager&& other) noexcept;
	ResourceManager& operator=(ResourceManager&& other) noexcept;
	int getValue() const;
	void setValue(int newValue);
};

#endif // !_ResourceManager_
