/*
 * DHT11Data.h
 *
 *  Created on: 18 août 2021
 *      Author: Hellcat
 */

#ifndef DHT11DATA_H_
#define DHT11DATA_H_

#include <iostream>

using namespace std;

class DHT11Data {
public:
	DHT11Data();
	DHT11Data(DHT11Data* dht11Data);
	DHT11Data(string name, int celsius, float farenheit, int humidity);
	virtual ~DHT11Data();
	inline void setName(string name) { _name = name; }
	inline string getName() { return _name; }
	inline void setCelsius(int celsius) { _celsius = celsius; }
	inline int getCelsius() { return _celsius; }
	inline void setFarenheit(float farenheit) { _farenheit = farenheit; }
	inline float getFarenheit() { return _farenheit; }
	inline void setHumidity(int humidity) { _humidity = humidity; }
	inline int getHumidity() { return _humidity; }

private:
	string _name;
	int _celsius;
	float _farenheit;
	int _humidity;
};

#endif /* DHT11DATA_H_ */
