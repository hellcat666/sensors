
/*
 * DHT11Sensor.cpp
 *
 *  Created on: 16 août 2021
 *      Author: Hellcat
 */
#ifndef DHT11SENSOR_H_
#include "DHT11Sensor.h"
#endif


#include <iostream>

DHT11Sensor::DHT11Sensor(string name, int pin) {
	setName(name);
	setPin(pin);
	_dht11 = new DHT11(getPin());
	_dht11->setInterval(5000);
	_dht11->setOnDHT11Listener(this);
	_dht11->start();
}

DHT11Sensor::~DHT11Sensor() {}

void DHT11Sensor::onDHT11(DHT11Event event) {
	setDHT11Data((DHT11Data *)event.getDHT11Data());
	char buf[256];
		sprintf(buf, "%s -  DHT11 Event received: Temperature %d °C (%.1f F) / Humidity %d%%", getDHT11Data()->getName().c_str(), getDHT11Data()->getCelsius(), getDHT11Data()->getFarenheit(), getDHT11Data()->getHumidity());
		cout << buf <<endl;

}

