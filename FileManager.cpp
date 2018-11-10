#include "FileManager.h"

FileManager::FileManager() {
	ThreadPool::GetMainThreadPool().StartingWork();
}

bool FileManager::AddDirectory(const char* dir) {

	auto task_prt = std::make_shared<DirectoryTask>(dir);
	m_ProsessDirTask.StartTask(task_prt);
	
	return true;
}

bool FileManager::Start() {
	return false;
}

bool FileManager::Stop() {
	return false;
}