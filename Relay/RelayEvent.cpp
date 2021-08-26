/*
 * RelayEvent.cpp
 *
 *  Created on: 23 août 2021
 *      Author: Hellcat
 */
#ifndef RELAYEVENT_H_
#include "RelayEvent.h"
#endif


RelayEvent::RelayEvent(string name, ushort pin, bool state) {
	_name = name;
	_pin = pin;
	_state = state;
}

RelayEvent::~RelayEvent() {

}


