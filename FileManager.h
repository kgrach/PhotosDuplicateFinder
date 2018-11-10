#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ThreadPoolWork.h"
#include "DirectoryTask.h"

class FileManager {

	ThreadPool::SequentialTasksEx<DirectoryTask> m_ProsessDirTask;

public:

	FileManager();

	//void AddFile(std::string&);

	bool AddDirectory(const char*);
	bool Start();
	bool Stop();
};