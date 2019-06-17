#include "DrivesManager.h"

DrivesManager::DrivesManager()
{
}

DrivesManager::~DrivesManager()
{
}

vector<pair<string, string>> DrivesManager::getDrivesPropeties() {
	vector<pair<string, string>> drivesProperites;

	for each (string str in printInfo("Win32_DiskDrive", "Model"))
	{
		drivesProperites.push_back(pair<string, string>("Name", str));
	}

	return drivesProperites;
}