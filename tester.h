#ifndef TESTER_H
#define TESTER_H

#include <QtCore/QObject>
#include <gatocentralmanager.h>
#include <gatoperipheral.h>
#include <gatoservice.h>
#include <gatocharacteristic.h>
#include "uinput.h"

class Tester : public QObject
{
	Q_OBJECT

public:
	explicit Tester(QObject *parent = 0);
	~Tester();

public slots:
	void test();

private slots:
	void handleDiscoveredPeripheral(GatoPeripheral *peripheral, int rssi);
	void handleConnected();
	void handleDisconnected();
	void handleServices();
	void handleCharacteristics(const GatoService &service);
	void handleValueUpdated(const GatoCharacteristic &characteristic, const QByteArray &value);
	void handleReport(int p, int x, int y, int z);

private:
	GatoCentralManager *manager;
	GatoPeripheral *peripheral;
	GatoCharacteristic agg_char;
	struct uinput_info info;
	struct uinput_user_dev dev;

	int prev_btn_0;
	int prev_btn_1;
};

#endif // TESTER_H
