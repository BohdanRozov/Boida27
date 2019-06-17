#include "IOManager.h"

IOManager::IOManager()
{
}


IOManager::~IOManager()
{
}

vector<pair<string, string>> IOManager::getIOPropeties() {
	vector<pair<string, string>> ioProperites;

	for each (string str in printInfo("Win32_PortConnector", "Name"))
	{
		ioProperites.push_back(pair<string, string>("Name", str));
	}

	return ioProperites;
}