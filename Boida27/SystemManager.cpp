#include "SystemManager.h"

vector<pair<string, string>> SystemManager::getCpuPropeties() {
	vector<pair<string, string>> cpuProperites;

	cpuProperites.push_back(pair<string, string>("Name", printInfo("Win32_Processor", "Name")[0]));

	return cpuProperites;
}

vector<pair<string, string>> SystemManager::getGpuPropeties() {
	vector<pair<string, string>> gpuProperites;

	for each (string str in printInfo("Win32_VideoController", "Name"))
	{
		gpuProperites.push_back(pair<string, string>("Name", str));
	}

	return gpuProperites;
}

vector<pair<string, string>> SystemManager::getDisksPropeties() {
	vector<pair<string, string>> gpuProperites;

	for each (string str in printInfo("Win32_DiskDrive", "Name"))
	{
		gpuProperites.push_back(pair<string, string>("Name", str));
	}

	return gpuProperites;
}