#include "Manager.h"

vector<string> Manager::printInfo(String^ hardwareClass, String^ propertyName) {
	vector<string> toReturn;
	try {
		ManagementObjectSearcher^ searcher = gcnew ManagementObjectSearcher("root\\CIMV2", "SELECT * FROM " + hardwareClass);
		ManagementObjectCollection^ collection = searcher->Get();

		for each (ManagementObject^ object in collection)
		{
			if (object != nullptr && object[propertyName] != nullptr) {
				string propStr = "";
				auto prop = object[propertyName]->ToString();
				if (prop != nullptr) {
					propStr = msclr::interop::marshal_as<string>(prop);
				}
				toReturn.push_back(propStr);
			}
		}
	}
	catch (...) {
	}

	return toReturn;
}

vector<string> Manager::printInfoSize(String^ hardwareClass, String^ propertyName) {
	vector<string> toReturn;
	try {
		ManagementObjectSearcher^ searcher = gcnew ManagementObjectSearcher("root\\CIMV2", "SELECT * FROM " + hardwareClass);
		ManagementObjectCollection^ collection = searcher->Get();

		for each (ManagementObject^ object in collection)
		{
			if (object != nullptr && object[propertyName] != nullptr) {
				string propStr = "";
				auto prop = object[propertyName]->ToString();
				if (prop != nullptr) {
					propStr = msclr::interop::marshal_as<string>(prop);
				}
				toReturn.push_back(propStr);
			}
		}
	}
	catch (...) {
	}

	return getCorrect_UINT64T_Strs(toReturn);
}

vector<string> Manager::getCorrect_UINT64T_Strs(vector<string> strs) {
	int i = 1;
	vector<string> toReturn = vector<string>();
	for (string &str : strs) // access by reference to avoid copying
	{
		stringstream ss;
		uint64_t value;
		istringstream iss(str);
		iss >> value;
		ss << ceilf((value / 1024.0 / 1024 / 1024) * 10) / 10 << " GB";
		toReturn.push_back(ss.str());
	}
	return toReturn;
}

vector<string> Manager::printInfoCondition(String^ hardwareClass, String^ propertyName, String^ condition, String^ conditionResult) {
	vector<string> toReturn;
	try {
		ManagementObjectSearcher^ searcher = gcnew ManagementObjectSearcher("root\\CIMV2", "SELECT * FROM " + hardwareClass);
		ManagementObjectCollection^ collection = searcher->Get();

		for each (ManagementObject^ object in collection)
		{
			if (object != nullptr && object[propertyName] != nullptr && object[condition] != nullptr) {
				string propStr = "";
				auto prop = object[propertyName]->ToString();
				if (prop != nullptr) {
					propStr = msclr::interop::marshal_as<string>(prop);
				}
				std::cout << msclr::interop::marshal_as<string>(object[condition]->ToString()) << endl;
				if (object[condition]->ToString()->CompareTo(conditionResult) == 0) {
					toReturn.push_back(propStr);
				}
			}
		}
	}
	catch (...) {
	}

	return toReturn;
}