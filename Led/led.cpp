/*
 * Led.cpp
 *
 *  Created on: 18 août 2021
 *      Author: Hellcat
 */

#ifndef SENSORS_H_
#include "../sensors.h"
#endif


Led::Led(string name, int pin) {
	_name = name;
	_pin = pin;
	_state = LED_OFF;
	_delay = 0;
	_blinking = false;
	pinMode(_pin, OUTPUT);

}

void Led::On() {
	_state = LED_ON;
	digitalWrite(_pin, HIGH);
}

void Led::Off() {
	_state = LED_OFF;
	digitalWrite(_pin, LOW);
}

bool Led::isOn() {
	return (_state==LED_ON) ? true : false;
}


void Led::Reset() {
	_state = LED_OFF;
	_blinking = false;
	_blink.~thread();
}

void Led::Blink(int duration) {
	_state = LED_BLINKING;
	_blinking = true;
	setDelay(duration);
  	_blink = std::thread(Led::toggle, this);
	_blink.detach();
}

bool Led::isBlinking() {
	return _blinking;
}

void Led::toggle(Led* led) {
	do {
//		cout << led->getName() << " BLINK !" << endl;
		led->On();
		delay(led->getDelay());
		led->Off();
		delay(led->getDelay());
	} while(led->isBlinking());
}


