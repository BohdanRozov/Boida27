#pragma once


#include <vector>
#include <msclr\marshal_cppstd.h>
#include <qdebug.h>
#include <iostream>
#include <sstream>

using namespace System;
using namespace System::Management;
using namespace std;

class Manager
{
public:
	static vector<string> printInfo(String^ hardwareClass, String^ propertyName);
	static vector<string> printInfoSize(String^ hardwareClass, String^ propertyName);
	static vector<string> printInfoCondition(String^ hardwareClass, String^ propertyName, String^ condition, String^ conditionResult);
	static vector<string> getCorrect_UINT64T_Strs(vector<string> strs);
};