#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Boida27.h"
#include "SystemManager.h"
#include "SoftwareManager.h"
#include "DrivesManager.h"
#include "IOManager.h"
#include "MemoryManager.h"
#include "SummaryManager.h"

#include <msclr\marshal_cppstd.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace System;
using namespace System::Management;
using namespace std;

class Boida27 : public QMainWindow
{
	Q_OBJECT

public:
	Boida27(QWidget *parent = Q_NULLPTR);

private:
	Ui::Boida27Class ui;
	void printProperties(vector<pair<string, string>> properties);
	void printWProperties(vector<pair<string, wstring>> properties);
	SystemManager sysMan = SystemManager();
	SoftwareManager softMan = SoftwareManager();
	DrivesManager drivesMan = DrivesManager();
	IOManager ioMan = IOManager();
	MemoryManager memMan = MemoryManager();
	SummaryManager sumMan = SummaryManager();

private slots:
	void on_componentsTree_itemClicked(QTreeWidgetItem *item, int column);
};
