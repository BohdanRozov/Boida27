#include "MemoryManager.h"



MemoryManager::MemoryManager()
{
}


MemoryManager::~MemoryManager()
{
}


void PrintProcessNameAndID(vector<pair<string, string>> *v, DWORD processID)
{
	try {
		TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

		// Get a handle to the process.

		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
			PROCESS_VM_READ,
			FALSE, processID);

		// Get the process name.

		if (NULL != hProcess)
		{
			HMODULE hMod;
			DWORD cbNeeded;

			if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
				&cbNeeded))
			{
				GetModuleBaseName(hProcess, hMod, szProcessName,
					sizeof(szProcessName) / sizeof(TCHAR));
			}
		}


		// Release the handle to the process.

		Process^ toMonitor = Process::GetProcessById(processID);
		long memoryUsed = toMonitor->WorkingSet64;

		std::wstring wStr = szProcessName;
		string str = std::string(wStr.begin(), wStr.end());
		if (str.compare("<unknown>") != 0) {
			v->push_back(pair<string, string>(str, to_string(memoryUsed / 1000000) + " MB"));
		}

		CloseHandle(hProcess);
	}
	catch (...) {
		cout << "Error" << endl;
		return;
	}
}

vector<pair<string, string>> MemoryManager::getMemoryPropeties() {
	vector<pair<string, string>> memoryProperites;

	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		return memoryProperites;
	}

	// Calculate how many process identifiers were returned.

	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the name and process identifier for each process.

	for (i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			PrintProcessNameAndID(&memoryProperites, aProcesses[i]);
		}
	}

	std::sort(memoryProperites.begin(), memoryProperites.end(), [](auto &left, auto &right) {
		return stoi(left.second) > stoi(right.second);
	});

	return memoryProperites;
}