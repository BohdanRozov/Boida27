#pragma once
#include "Manager.h"
class SummaryManager :
	public Manager
{
public:
	SummaryManager();
	~SummaryManager();
	vector<pair<string, string>> getSummaryPropeties();
};

