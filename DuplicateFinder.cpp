#include "DuplicateFinder.h"

#include <iterator>
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#include "Utils.h"

using namespace std;
namespace fs = std::experimental::filesystem;

uint32_t DuplicateFinder::CalcCRC32(std::string& file) {
	
	fstream f;

	f.open(file.c_str(), fstream::in | fstream::binary);

	if (!f.is_open()) {
		return 0;
	}

	uint32_t crc = 0;
	vector<unsigned char> buf(1 << 16);
	size_t len;

	do {
		f.read((char*)buf.data(), buf.size());
		len = f.gcount();
		crc = Utils::crc32c(crc, buf.data(), len);
	} while (len == buf.size());

	f.close();

	return crc;
}

DuplicateFinder::DuplicateFinder(const char* trans_bat) : m_trans_bat(trans_bat) {
	
}

void DuplicateFinder::AddDirectory(const char* dir) {
	m_dirs.emplace_back(dir);
}

bool DuplicateFinder::StartFind() {
	
	for (const auto& p : m_dirs) {

		time_t t = time(nullptr);
		cout << "Check entry dir : " << p.c_str() << ", started at " << std::asctime(std::localtime(&t)) << endl;

		for (const auto &entry : fs::recursive_directory_iterator(p.c_str())) {

			if (fs::is_regular_file(entry)) {

				const fs::path &m_file = entry;
				string s = m_file.extension().string();

				transform(s.begin(), s.end(), s.begin(), ::tolower);

				if (s == ".jpg" || s == ".cr2" || s == ".mp4") {
					FileKey key;
					key.m_filename = m_file.filename().string();
					key.m_crc = CalcCRC32(m_file.string());
					
					vector<string> &item = m_files[key];
					item.emplace_back(m_file.parent_path().string());
				}
			}
		}
	}

	return true;
}

void DuplicateFinder::Print() {

	fstream f;

	f.open(m_trans_bat.c_str(), fstream::out | fstream::trunc);

	if (!f.is_open()) {

		cout << "failed to open " << m_trans_bat << '\n';
		return;
	}

	for (auto it = m_files.begin(); it != m_files.end(); it++) {

		size_t num;

		system("cls");
		for (size_t i = 1; i <= it->second.size(); i++) {
			cout << i << ": " << it->second[i-1] << "\\" << it->first.m_filename << endl;
		}

		cout << "Choose original file ( push 1 .. "<< it->second.size() << ")" << endl;
		
		cin >> num;

		if (num >= 1 && num <= it->second.size()) {

			for (size_t i = 1; i <= it->second.size(); i++) {

				if(num != i)
					f << "del " << it->second[i-1] << "\\" << it->first.m_filename << endl;
			}

		}
	}

	f.close();
}

