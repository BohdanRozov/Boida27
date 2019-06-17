#pragma once

#include "Manager.h"
#include <msclr/marshal.h>

using namespace System;
using namespace System::Configuration;

class SoftwareManager :
	public Manager
{
public:
	SoftwareManager();
	vector<pair<string, wstring>> getSoftwarePropeties();
};

