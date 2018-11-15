#include <iostream>
#include <functional>
#include <memory>


#include "FileManager.h"

using namespace std;

FileManager::FileManager() {
	ThreadPool::GetMainThreadPool().StartingWork();


	f.open("D:\\Work\\PhotosDuplicateFinder\\res.log", fstream::out | fstream::trunc);
}

void FileManager::RegisterNewFile(std::shared_ptr<std::string>& pfileName) {
	
	//f << ::GetCurrentThreadId() << ":  " << pfileName->c_str() << endl;
	//cout << ::GetCurrentThreadId() << ":  " << pfileName->c_str() << endl;

	using namespace placeholders;

	//function<void(std::shared_ptr<std::string>&)> f = bind(&FileManager::RegisterNewFile, this, _1);
	auto pTask = make_shared<FileTask>(pfileName);

	m_ProsessFileTask.StartTask(pTask);
}

bool FileManager::AddDirectory(const char* dir) {
	using namespace placeholders;

	function<void(std::shared_ptr<std::string>&)> f = bind(&FileManager::RegisterNewFile, this, _1);
	auto pTask = make_shared<DirectoryTask>(dir, f);

	m_ProsessDirTask.StartTask(pTask);
	
	return true;
}