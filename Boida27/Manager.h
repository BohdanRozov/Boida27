#pragma once


#include <vector>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Management;
using namespace std;

class Manager
{
public:
	 vector<string> printInfo(String^ hardwareClass, String^ propertyName);
};