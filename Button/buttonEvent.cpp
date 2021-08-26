
/*
 * ButtonEvent.cpp
 *
 *  Created on: 20 août 2021
 *      Author: Hellcat
 */
#ifndef BUTTONEVENT_H_
#include "buttonEvent.h"
#endif

ButtonEvent::ButtonEvent(string name, ushort pin) {
    _name = name;
    _pin = pin;
}

ButtonEvent::~ButtonEvent() {
}



