#include "Manager.h"

vector<string> Manager::printInfo(String^ hardwareClass, String^ propertyName) {
	ManagementObjectSearcher^ searcher = gcnew ManagementObjectSearcher("root\\CIMV2", "SELECT * FROM " + hardwareClass);
	ManagementObjectCollection^ collection = searcher->Get();

	vector<string> toReturn;
	for each (ManagementObject^ object in collection)
	{
		Console::WriteLine(object[propertyName]->ToString());
		string stdStr = msclr::interop::marshal_as<string>(object[propertyName]->ToString());
		toReturn.push_back(stdStr);
	}
	return toReturn;
}


