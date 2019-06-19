#include "SummaryManager.h"

SummaryManager::SummaryManager()
{
}

SummaryManager::~SummaryManager()
{
}

vector<pair<string, string>> SummaryManager::getSummaryPropeties() {
	vector<pair<string, string>> sumProperites;

	auto v1 = printInfo("Win32_OperatingSystem", "Caption");
	auto v2 = printInfo("Win32_OperatingSystem", "OSArchitecture");
	for (int i = 0; i < v1.size(); i++) {
		sumProperites.push_back(pair<string, string>("Name", v1[i]));
		sumProperites.push_back(pair<string, string>("Architecture", v2[i]));
	}

	return sumProperites;	
}