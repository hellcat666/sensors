/*
 * relay.h
 *
 *  Created on: 23 août 2021
 *      Author: Hellcat
 */

#ifndef RELAY_H_
#define RELAY_H_

#ifndef RELAYEVENT_H_
#include "RelayEvent.h"
#endif

#ifndef ONRELAYLISTENER_H_
#include "OnRelayListener.h"
#endif


#include <wiringPi.h>

#include <atomic>
#include <string>
#include <thread>
#include <list>

using namespace std;

enum RELAY_STATE { RELAY_OFF, RELAY_ON };

class Relay {
private:
	string _name;
	ushort _pin;
	RELAY_STATE _state;
	int _delay;
    std::thread _blink;
	std::atomic<bool> _blinking;
	OnRelayListener* _listener;
	list<OnRelayListener *> _listeners;

public:
	Relay(string name, ushort pin);
	~Relay();
	inline void setName(string name) { _name = name; }
	inline string getName() { return _name; }
	inline void setPin(ushort pin) { _pin = pin; }
	inline ushort getPin() { return _pin; }
	inline void setState(RELAY_STATE state) { _state = state; }
	inline RELAY_STATE getState() { return _state; }
	inline void setDelay(int delay) { _delay = delay; }
	inline int getDelay() { return _delay; }
	void On();
	void Off();
	bool isOn();
	void Blink(int duration);
	bool isBlinking();
	void Reset();
	static void toggle(Relay* relay);
	void setOnRelayListener(OnRelayListener* listener);
	void fireRelayEvent();
};

#endif /* RELAY_H_ */
