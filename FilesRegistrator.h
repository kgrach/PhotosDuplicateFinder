#pragma once
#include <string>
#include <vector>
#include <map>
#include <stdint.h>

class FilesRegistrator {
	
	struct FileKey {
		std::string m_filename;
		uint32_t	m_crc;

		bool operator<(const FileKey& rhs) const {
			if (m_crc < rhs.m_crc || (m_crc == rhs.m_crc && m_filename < rhs.m_filename))
				return true;
			return false;
		}
	};

	std::map<FileKey, std::vector<std::string>>		m_files;
	std::vector<std::string>						m_dirs;
	std::string										m_trans_bat;

	uint32_t CalcCRC32(std::string& file);

public:

	FilesRegistrator(const char*);

	void AddDirectory(const char*);
	bool StartFind();
	void Print();
};