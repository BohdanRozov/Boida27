#pragma once

#include "Manager.h"

class DrivesManager :
	public Manager
{
public:
	DrivesManager();
	~DrivesManager();
	vector<pair<string, string>> getDrivesPropeties();
};

