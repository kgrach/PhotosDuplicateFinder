#pragma once

#pragma once

#include <string>
#include <functional>
#include <memory>
#include <windows.h>

#include "ThreadPoolIo.h"

class FileTask {

	HANDLE hfile;
	std::shared_ptr<std::string> m_file;
	std::function<void(std::shared_ptr<std::string>&)> m_fNextConveyorStage;

	std::unique_ptr<ThreadPool::ThreadPoolIO<std::function<bool(void)>>>  m_read_io;

	OVERLAPPED m_ReadOv;
	DWORD m_ReadBuffSize;
	char m_ReadBuff[8096];


	bool Reading(void);
	void ReadComplete(PVOID Overlapped, ULONG IoResult, ULONG_PTR NumberOfBytesTransferred);

public:

	FileTask(std::shared_ptr<std::string>& file/*, std::function<void(std::shared_ptr<std::string>&)>& fNextConveyorStage*/) : m_file(file)/*, m_fNextConveyorStage(fNextConveyorStage)*/ {
	}

	bool PrepareDataTask();

	void operator ()(void);
};