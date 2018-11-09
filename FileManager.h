#pragma once

#include <concurrent_queue.h>
#include <string>
#include <vector>

#include "ThreadPoolWork.h"

class FileManager {


	concurrency::concurrent_queue<std::string>	m_files;

	ThreadPool::SequentialTasks<ProcessDirTask> m_ProsessDirTask;

public:

	void AddFile(std::string&);

	bool AddDirectory(const char*);
	bool Start()
	bool Stop();
};