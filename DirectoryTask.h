#pragma once

#include <string>
#include <functional>

class DirectoryTask  {

	std::string m_dir;
	std::function<void(std::shared_ptr<std::string>&)> m_fNextConveyorStage;

public:

	DirectoryTask(const std::string& dir, std::function<void(std::shared_ptr<std::string>&)>& fNextConveyorStage) : m_dir(dir), m_fNextConveyorStage(fNextConveyorStage){
	}

	void operator ()(void);
};