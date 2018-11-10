#pragma once

#include <string>


class DirectoryTask {

	std::string m_dir;
	
public:

	DirectoryTask(const std::string& dir) : m_dir(dir) {

	}

	void operator ()(void);
};