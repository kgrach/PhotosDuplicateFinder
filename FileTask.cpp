#include "FileTask.h"

using namespace ThreadPool;

bool FileTask::PrepareDataTask() {
	
	hfile = CreateFile(m_file->c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING | FILE_FLAG_OVERLAPPED, NULL);

	if (hfile == INVALID_HANDLE_VALUE)
		return false;

	m_read_io.reset(new ThreadPoolIO<std::function<bool(void)>>(reinterpret_cast<HANDLE>(hfile),
		std::bind(&FileTask::Reading, this),
		std::bind(&FileTask::ReadComplete, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));

	m_read_io->IoPending();

	return true;
}

bool FileTask::Reading(void) {
	memset(&m_ReadOv, 0, sizeof(m_ReadOv));

	int res = ::ReadFile(hfile, &m_ReadBuff, sizeof(m_ReadBuff), &m_ReadBuffSize, &m_ReadOv);
	return true;
}

void FileTask::ReadComplete(PVOID Overlapped, ULONG IoResult, ULONG_PTR NumberOfBytesTransferred) {
	m_read_io->IoPending();
}

void FileTask::operator ()(void) {

}
