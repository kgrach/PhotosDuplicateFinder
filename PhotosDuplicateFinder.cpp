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

	mngr.AddDirectory("F:\\CanonPhotoLoad");
	mngr.AddDirectory("F:\\fleshka");
	mngr.AddDirectory("F:\\photos");
	mngr.AddDirectory("F:\\photos2");

	//mngr.StartFind();
	//finder.Print();

    return 0;
}

