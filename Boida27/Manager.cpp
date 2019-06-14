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
	catch (exception e) {
	}

	return toReturn;
}


