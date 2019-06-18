#include "SummaryManager.h"

SummaryManager::SummaryManager()
{
}

SummaryManager::~SummaryManager()
{
}

vector<pair<string, string>> SummaryManager::getSummaryPropeties() {
	vector<pair<string, string>> gpuProperites;

	for each (string str in printInfo("Win32_VideoController", "Name"))
	{
		gpuProperites.push_back(pair<string, string>("Name", str));
	}

	return gpuProperites;
}