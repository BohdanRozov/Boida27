#include "Boida27.h"

Boida27::Boida27(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Boida27::printProperties(vector<pair<string, string>> properties) {
	int i = 0;
	for each (pair<string, string> p in properties)
	{
		ui.propertiesTable->insertRow(i);
		ui.propertiesTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(p.first)));
		ui.propertiesTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.second)));
		i++;
	}
}

void Boida27::printWProperties(vector<pair<string, wstring>> properties) {
	int i = 0;
	for each (pair<string, wstring> p in properties)
	{
		ui.propertiesTable->insertRow(i);
		ui.propertiesTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(p.first)));
		ui.propertiesTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdWString(p.second)));
		i++;
	}
}


void Boida27::on_componentsTree_itemClicked(QTreeWidgetItem *item,
	int column) {

	for (int i = ui.propertiesTable->rowCount() - 1; i >= 0; i--) {
		ui.propertiesTable->removeRow(i);
	}

	if (QString::compare(item->text(0), "CPU") == 0) {
		printProperties(sysMan.getCpuPropeties());
	}
	else if (QString::compare(item->text(0), "GPU") == 0) {
		printProperties(sysMan.getGpuPropeties());
	}
	else if (QString::compare(item->text(0), "PCI") == 0) {
		printProperties(sysMan.getPCIPropeties());
	}
	else if (QString::compare(item->text(0), "Disks") == 0) {
		printProperties(sysMan.getDisksPropeties());
	}
	else if (QString::compare(item->text(0), "PnP Devices") == 0) {
		printProperties(sysMan.getPnPPropeties());
	}
	else if (QString::compare(item->text(0), "BIOS & CMOS") == 0) {
		printProperties(sysMan.getBCPropeties());
	}
	else if (QString::compare(item->text(0), "Software") == 0) {
		printWProperties(softMan.getSoftwarePropeties());
	}
	else if (QString::compare(item->text(0), "Drives") == 0) {
		printProperties(drivesMan.getDrivesPropeties());
	}
	else if (QString::compare(item->text(0), "I/O Devices") == 0) {
		printProperties(ioMan.getIOPropeties());
	}
	
}