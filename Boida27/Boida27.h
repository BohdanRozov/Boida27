#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Boida27.h"
#include "SystemManager.h"

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
	void getCorrect_UINT64T_Strs(vector<string> strs);

private slots:
	void on_componentsTree_itemClicked(QTreeWidgetItem *item, int column);
};
