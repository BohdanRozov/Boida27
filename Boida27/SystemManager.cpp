#include "SystemManager.h"

static auto cpuPreload = pair<string, string>("Name", Manager::printInfo("Win32_Processor", "Name")[0]);

vector<pair<string, string>> SystemManager::getCpuPropeties() {
	vector<pair<string, string>> cpuProperites;
	cpuProperites.push_back(cpuPreload);
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
	vector<pair<string, string>> disksProperites;
	auto v1 = printInfo("Win32_LogicalDisk", "Name");
	auto v2 = printInfoSize("Win32_LogicalDisk", "Size");
	for (int i = 0; i < v1.size(); i++) {
		disksProperites.push_back(pair<string, string>("Name", v1[i]));
		disksProperites.push_back(pair<string, string>("Size", v2[i])); 
	}

	return disksProperites;
}

vector<pair<string, string>> SystemManager::getPnPPropeties() {
	vector<pair<string, string>> pnpProperites;

	for each (string str in printInfo("Win32_PnPEntity", "Name"))
	{
		pnpProperites.push_back(pair<string, string>("Name", str));
	}

	return pnpProperites;
}