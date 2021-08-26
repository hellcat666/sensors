
/*
 * DHT11Event.cpp
 *
 *  Created on: 16 août 2021
 *      Author: Hellcat
 */
#ifndef DHT11EVENT_H_
#include "DHT11Event.h"
#endif

using namespace std;

DHT11Event::DHT11Event(string name, int celsius, float farenheit, int humidity, string units) {
	_dht11Data = new DHT11Data(name, celsius, farenheit, humidity);
	setUnits(units);
}

DHT11Event::~DHT11Event() { }




