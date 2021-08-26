/*
 * DHT11Data.cpp
 *
 *  Created on: 18 août 2021
 *      Author: Hellcat
 */

#include "DHT11Data.h"

DHT11Data::DHT11Data() {
	setName("");
	setCelsius(0);
	setFarenheit(0.0);
	setHumidity(0);
}

DHT11Data::DHT11Data(DHT11Data* dht11Data) {
	setName(dht11Data->getName());
	setCelsius(dht11Data->getCelsius());
	setFarenheit(dht11Data->getFarenheit());
	setHumidity(dht11Data->getHumidity());
}

DHT11Data::DHT11Data(string name, int celsius, float farenheit, int humidity) {
	setName(name);
	setCelsius(celsius);
	setFarenheit(farenheit);
	setHumidity(humidity);
}

DHT11Data::~DHT11Data() {
	// TODO Auto-generated destructor stub
}

