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

vector<pair<string, string>> SystemManager::getPCIPropeties() {
	vector<pair<string, string>> pciProperites;

	ManagementObjectSearcher^ searcher = gcnew ManagementObjectSearcher("root\\CIMV2", "SELECT * FROM " + "Win32_PnPEntity");
	ManagementObjectCollection^ collection = searcher->Get();

	for each (ManagementObject^ object in collection)
	{
		if (object != nullptr && object["Name"] != nullptr &&  object["DeviceID"] != nullptr) {
			string propStr = "";
			string idStr = "";
			auto prop = object["Name"]->ToString();
			if (prop != nullptr) {
				propStr = msclr::interop::marshal_as<string>(prop);
			}
			auto id = object["DeviceID"]->ToString();
			if (id->Contains("PCI")) {
				pciProperites.push_back(pair<string, string>("Name", propStr));
			}
		}
	}

	return pciProperites;
}

vector<pair<string, string>> SystemManager::getPnPPropeties() {
	vector<pair<string, string>> pnpProperites;

	ManagementObjectSearcher^ searcher = gcnew ManagementObjectSearcher("root\\CIMV2", "SELECT * FROM " + "Win32_PnPEntity");
	ManagementObjectCollection^ collection = searcher->Get();

	for each (ManagementObject^ object in collection)
	{
		if (object != nullptr && object["Name"] != nullptr &&  object["DeviceID"] != nullptr) {
			string propStr = "";
			string idStr = "";
			auto prop = object["Name"]->ToString();
			if (prop != nullptr) {
				propStr = msclr::interop::marshal_as<string>(prop);
			}
			auto id = object["DeviceID"]->ToString();
			if (!id->Contains("PCI")) {
				pnpProperites.push_back(pair<string, string>("Name", propStr));
			}
		}
	}

	return pnpProperites;
}

vector<pair<string, string>> SystemManager::getBCPropeties() {

	vector<pair<string, string>> bcProperites;
	auto v1 = printInfo("Win32_BIOS", "Name");
	auto v2 = printInfo("Win32_BIOS", "Version");
	for (int i = 0; i < v1.size(); i++) {
		bcProperites.push_back(pair<string, string>("Name", v1[i]));
		bcProperites.push_back(pair<string, string>("Version", v2[i]));
	}

	for each (string str in printInfo("Win32_Battery", "Name"))
	{
		bcProperites.push_back(pair<string, string>("Name", str));
	}

	return bcProperites;
}