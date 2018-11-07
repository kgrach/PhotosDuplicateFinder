// PhotosDuplicateFinder.cpp : Defines the entry point for the console application.
//

#include "DuplicateFinder.h"

/*dirs.emplace_back("d:\\photos\\");
dirs.emplace_back("d:\\photos2\\");
dirs.emplace_back("d:\CanonPhotoLoad\\");

dirs.emplace_back("G:\\photos\\");
dirs.emplace_back("G:\\photos2\\");
dirs.emplace_back("G:\\fleshka2\\фото группы √номики\\");
dirs.emplace_back("G:\CanonPhotoLoad\\");*/

int main()
{
	
	DuplicateFinder finder("D:\\Work\\PhotosDuplicateFinder\\del_duplicate.bat");


	//finder.AddDirectory("D:\\Work\\PhotosDuplicateFinder\\Case1");
	//finder.AddDirectory("D:\\Work\\PhotosDuplicateFinder\\Case2");
	//finder.AddDirectory("D:\\Work\\PhotosDuplicateFinder\\Case3");

	finder.AddDirectory("F:\\CanonPhotoLoad");
	finder.AddDirectory("F:\\fleshka");
	finder.AddDirectory("F:\\photos");
	finder.AddDirectory("F:\\photos2");

	finder.StartFind();

	finder.Print();

    return 0;
}

