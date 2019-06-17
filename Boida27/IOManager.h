#pragma once

#include "Manager.h"

class IOManager :
	public Manager
{
public:
	IOManager();
	~IOManager();
	vector<pair<string, string>> getIOPropeties();
};

