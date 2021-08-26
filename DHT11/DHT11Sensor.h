/*
 * DHT11Sensor.h
 *
 *  Created on: 16 août 2021
 *      Author: Hellcat
 */

#ifndef DHT11SENSOR_H_
#define DHT11SENSOR_H_

#ifndef DHT11_H_
#include "dht11.h"
#endif

#ifndef DHT11EVENT_H_
#include "DHT11Event.h"
#endif

#ifndef ONDHT11LISTENER_H_
#include "OnDHT11Listener.h"
#endif

#include <iostream>
#include <string>

using namespace std;

class DHT11Sensor : OnDHT11Listener {
private:
	string _name;
	int _pin;
	DHT11* _dht11;
	DHT11Data* _dht11Data;

public:
	DHT11Sensor(string name, int pin);
	~DHT11Sensor();
	inline void setDHT11Data(DHT11Data* dht11Data) { _dht11Data = new DHT11Data(dht11Data); }
	inline DHT11Data* getDHT11Data() { return _dht11Data; }

	void onDHT11(DHT11Event event);

public:
	inline void setName(string name) { _name = name; }
	inline string getName() { return _name; }
	inline void setPin(int pin) { _pin = pin; }
	inline int getPin() { return _pin; }

};

#endif /* DHT11SENSOR_H_ */
