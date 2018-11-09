#include <filesystem>
#include <iostream>
#include <time.h>

#include "DirectoryTask.h"


using namespace std;
namespace fs = std::experimental::filesystem;

void DirectoryTask::Process(void) {

	time_t t = time(nullptr);
	cout << "Check entry dir : " << m_dir.c_str() << ", started at " << std::asctime(std::localtime(&t)) << endl;

	for (const auto &entry : fs::recursive_directory_iterator(m_dir.c_str())) {

		if (fs::is_regular_file(entry)) {

			const fs::path &m_file = entry;
			string s = m_file.extension().string();

			transform(s.begin(), s.end(), s.begin(), ::tolower);

			if (s == ".jpg" || s == ".cr2" || s == ".mp4") {
				
				string m_filename = m_file.filename().string();

			}
		}
	}

}