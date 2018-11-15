// PhotosDuplicateFinder.cpp : Defines the entry point for the console application.
//

#include "FileManager.h"

/*dirs.emplace_back("d:\\photos\\");
dirs.emplace_back("d:\\photos2\\");
dirs.emplace_back("d:\CanonPhotoLoad\\");

dirs.emplace_back("G:\\photos\\");
dirs.emplace_back("G:\\photos2\\");
dirs.emplace_back("G:\\fleshka2\\фото группы √номики\\");
dirs.emplace_back("G:\CanonPhotoLoad\\");*/

int main()
{
	
	//DuplicateFinder finder("D:\\Work\\PhotosDuplicateFinder\\del_duplicate.bat");
	FileManager mngr;

	//finder.AddDirectory("D:\\Work\\PhotosDuplicateFinder\\Case1");
	//finder.AddDirectory("D:\\Work\\PhotosDuplicateFinder\\Case2");
	//finder.AddDirectory("D:\\Work\\PhotosDuplicateFinder\\Case3");

	mngr.AddDirectory("G:\\CanonPhotoLoad");
	mngr.AddDirectory("G:\\fleshka");
	mngr.AddDirectory("G:\\photos");
	mngr.AddDirectory("G:\\photos2");

	//mngr.StartFind();
	//finder.Print();

	while (1) {
		Sleep(0);
	}

    return 0;
}

