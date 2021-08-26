/*
 * dht11.h
 *
 *  Created on: 16 août 2021
 *      Author: Hell
 */

#ifndef DHT11_H_
#define DHT11_H_

#include <wiringPi.h>

#ifndef ONDHT11LISTENER_H
#include "OnDHT11Listener.h"
#endif

#ifndef DHT11EVENT_H
#include "DHT11Event.h"
#endif


#include <atomic>
#include <iostream>
#include <thread>
#include <signal.h>
#include <list>

using namespace std;

#define MAXTIMINGS	85

enum DHT11_STATE { STOPPED, RUNNING };
enum TEMPERATURE_UNIT { CELSIUS, FARENHEIT, BOTH };

class DHT11 {
private:
	std::string _name;
    int _pin;
    TEMPERATURE_UNIT _units;
    int _tempCelsius;
	float _tempFarenheit;
    int _humidity;
    int _interval;
    thread _dht11;
    atomic<bool> _measuring;
    DHT11_STATE _state;
//    OnDHT11Listener* _listener;
    list<OnDHT11Listener *> _listeners;

public:
    DHT11(int pin);
    ~DHT11();

    inline void setPin(int pin) { _pin = pin; }
    inline int getPin() { return _pin; }
    inline void setUnits(TEMPERATURE_UNIT units) { _units = units; }
    inline TEMPERATURE_UNIT getUnits() { return _units; }
    inline void setInterval(int interval) { _interval = interval; }
    inline int getInterval() { return _interval; }
    inline void setTempCelsius(int tempCelsius) { _tempCelsius = tempCelsius; }
    inline int getTempCelsius() { return _tempCelsius; }
    inline void setTempFarenheit(float tempFarenheit){ _tempFarenheit = tempFarenheit; }
    inline float getTempFarenheit() {return _tempFarenheit; }
    inline void setHumidity(int humidity) { _humidity = humidity; }
    inline int getHumidity() { return _humidity; }

    void start();
    void stop();

    bool isRunning();

	static void read_dht11_data(DHT11* dht11);

    void setOnDHT11Listener(OnDHT11Listener* listener);
    void fireDHT11Event();

};




#endif /* DHT11_H_ */
