#pragma once

#include "IWork.h"

#include <string>


class DirectoryTask : public IWork {

	std::string m_dir;
	
public:

	DirectoryTask(const std::string& dir) : m_dir(dir) {

	}

	virtual void Process(void) override final;
};