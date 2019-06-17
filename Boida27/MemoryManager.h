#pragma once

#include "Manager.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <sstream>

using namespace System::Diagnostics;

class MemoryManager :
	public Manager
{
public:
	MemoryManager();
	~MemoryManager();
	vector<pair<string, string>> getMemoryPropeties();
};

