#pragma once
#include "IRegistrator.h"

namespace RegisterTask {

class RegistratorTask : public IRegistrator {

	AddNewFile f_AddNewFile;

public:

	void RegisterCallBack(AddNewFile f) {
		f_AddNewFile = f;
	}

	bool Work
};
}