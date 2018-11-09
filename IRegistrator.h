#pragma once

#include <string>
#include <functional>


namespace RegisterTask {

using AddNewFile = std::function<void(std::string&)>;

class IRegistrator {
public:
	virtual void RegisterCallBack(AddNewFile) = 0;
};

}