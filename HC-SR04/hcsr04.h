/*
 * hcsr04.h
 *
 *  Created on: 25 août 2021
 *      Author: Hellcat
 */

#ifndef HCSR04_H_
#define HCSR04_H_


#ifndef HCSR04EVENT_H_
#include "HCSR04Event.h"
#endif

#ifndef ONHCSR04LISTENER_H_
#include "OnHCSR04Listener.h"
#endif

#include <wiringPi.h>

#include <iostream>
#include <unistd.h>
#include <math.h>
#include <string>
#include <thread>
#include <atomic>
#include <list>


using namespace std;

#define NANOSEC 1000000000

class HCSR04 {
private:
	string _name;
	ushort _triggerPin;
	ushort _echoPin;
	double _pulseStart;
	double _pulseEnd;
	double _pulseDuration;
	double _distance;
	struct timespec _timeNow;
	int _delay;
    thread _loop;
	atomic<bool> _running;
	OnHCSR04Listener* _listener;
	list<OnHCSR04Listener *> _listeners;

public:
	HCSR04(string name, ushort triggerPin, ushort echoPin);
	virtual ~HCSR04();
	inline void setName(string name) { _name = name; }
	inline string getName() { return _name; }
	inline void setTriggerPin(ushort triggerPin) { _triggerPin = triggerPin; }
	inline ushort getTriggerPin() { return _triggerPin; }
	inline void setEchoPin(ushort echoPin) { _echoPin = echoPin; }
	inline ushort getEchoPin() { return _echoPin; }
	inline void setDelay(int delay) { _delay = delay; }
	inline int getDelay() { return _delay; }
	inline bool isRunning() { return _running; }
	void start(int delay);
	void stop();
	static void compute(HCSR04* hcsr04);

	void setOnHCSR04Listener(OnHCSR04Listener* listener);
	void fireHCSR04Event();

private:
	void initialize();
	void trigger();
	void waitForEcho();
	void computeDistance();

};




#endif /* HCSR04_H_ */
