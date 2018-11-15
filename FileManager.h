#pragma once

#include <string>
#include <fstream>

#include "ThreadPoolWork.h"
#include "DirectoryTask.h"
#include "FileTask.h"

class FileManager {


	std::fstream f;
	ThreadPool::SequentialTasksEx<DirectoryTask>	m_ProsessDirTask;
	ThreadPool::ParallelTasksEx<FileTask>			m_ProsessFileTask;

	void RegisterNewFile(std::shared_ptr<std::string>& fileName);

public:

	FileManager();

	bool AddDirectory(const char*);
};
