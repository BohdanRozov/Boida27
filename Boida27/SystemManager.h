#pragma once

#include <Manager.h>

using namespace std;

class SystemManager : public Manager
{
public:
	SystemManager()
	{
	}

	~SystemManager()
	{
	}

	vector<pair<string, string>> getCpuPropeties();
	vector<pair<string, string>> getGpuPropeties();
	vector<pair<string, string>> getDisksPropeties();
};
