/*
 * relay.cpp
 *
 *  Created on: 23 août 2021
 *      Author: Hellcat
 */
#ifndef RELAY_H_
#include "relay.h"
#endif


#include <list>
#include <vector>


Relay::Relay(string name, ushort pin) {
	_name = name;
	_pin = pin;
	_state = RELAY_OFF;
	_delay = 0;
	_blinking = false;
	pinMode(_pin, OUTPUT);
}

void Relay::On() {
	_state = RELAY_ON;
	digitalWrite(_pin, HIGH);
	fireRelayEvent();
}

void Relay::Off() {
	_state = RELAY_OFF;
	digitalWrite(_pin, LOW);
	fireRelayEvent();
}

bool Relay::isOn() {
	return (_state==RELAY_ON) ? true : false;
}


void Relay::Reset() {
	_state = RELAY_OFF;
	_blinking = false;
	_blink.~thread();
}

void Relay::Blink(int duration) {
	_blinking = true;
	if(duration<1000)
		setDelay(1000);
	else
		setDelay(duration);
  	_blink = std::thread(Relay::toggle, this);
	_blink.detach();
}

bool Relay::isBlinking() {
	return _blinking;
}

void Relay::toggle(Relay* relay) {
	do {
		relay->On();
		delay(relay->getDelay());
		relay->Off();
		delay(relay->getDelay());
	} while(relay->isBlinking());
}

void Relay::setOnRelayListener(OnRelayListener* listener) {
    _listeners.push_front(listener);
}

void Relay::fireRelayEvent() {
    RelayEvent event = RelayEvent(_name, _pin, (_state==RELAY_ON) ? true : false);
    for(OnRelayListener* listener : _listeners) {
	    listener->onRelay(event);
    }
}

