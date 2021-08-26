
/*
 * hcsr04.cpp
 *
 *  Created on: 25 août 2021
 *      Author: Hellcat
 */
#ifndef HCSR04_H_
#include "hcsr04.h"
#endif

	HCSR04::HCSR04(string name, ushort triggerPin, ushort echoPin) {
		_name = name;
		_triggerPin = triggerPin;
		_echoPin = echoPin;
		initialize();
	}
	HCSR04::~HCSR04() {
		if(isRunning()) {  stop(); }
	}
	void HCSR04::start(int delay) {
		_delay = delay;
		_running = true;
		_loop = thread(compute, this);
	}
	void HCSR04::stop() {
		_running = false;
	}

	void HCSR04::compute(HCSR04* hcsr04) {
		do {
			hcsr04->trigger();
			hcsr04->waitForEcho();
			hcsr04->computeDistance();
			hcsr04->fireHCSR04Event();
			delay(hcsr04->getDelay());
		}while((hcsr04->isRunning()));
	}

	void HCSR04::initialize() {
		pinMode(_triggerPin, OUTPUT);
		digitalWrite(_triggerPin, LOW);
		pinMode(_echoPin, INPUT);
		sleep(2);
	}

	void HCSR04::trigger() {
		digitalWrite(_triggerPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(_triggerPin, LOW);
	}

	void HCSR04::waitForEcho() {
	struct timespec gettime_now;
		while(digitalRead(_echoPin)!=HIGH){
			clock_gettime(CLOCK_REALTIME, &gettime_now);
			_pulseStart = (double)gettime_now.tv_nsec;
		}
		while(digitalRead(_echoPin)!=LOW){
			clock_gettime(CLOCK_REALTIME, &gettime_now);
			_pulseEnd = (double)gettime_now.tv_nsec;
		}
	}

	void HCSR04::computeDistance() {
		_pulseDuration = (_pulseEnd - _pulseStart);
		_distance = (_pulseDuration / NANOSEC) * 17150;

	}


	void HCSR04::setOnHCSR04Listener(OnHCSR04Listener* listener) {
	    _listeners.push_front(listener);
	}

	void HCSR04::fireHCSR04Event() {
		HCSR04Event event = HCSR04Event(_name, _distance);
	    for(OnHCSR04Listener* listener : _listeners) {
		    listener->onHCSR04(event);
	    }
	}



