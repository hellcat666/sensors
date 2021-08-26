/*
 * DHT11Event.h
 *
 *  Created on: 16 août 2021
 *      Author: Hell
 */

#ifndef DHT11EVENT_H_
#define DHT11EVENT_H_

#ifndef DHT11DATA_H_
#include "DHT11Data.h"
#endif

#include <string>

using namespace std;


class DHT11Event {
private:
	DHT11Data* _dht11Data;
	string _units;

public:
	DHT11Event(string name, int celsius, float farenheit, int humidity, string units);
	~DHT11Event();
	inline void setDHT11Data(DHT11Data* dht11Data) { _dht11Data = dht11Data; }
	inline DHT11Data* getDHT11Data() { return _dht11Data; }
	inline void setUnits(string units) { _units = units; }
	inline string getUnits() { return _units; }
};



#endif /* DHT11EVENT_H_ */
