/*
 * button.h
 *
 *  Created on: 19 août 2021
 *      Author: Hellcat
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#ifndef BUTTONEVENT_H_
#include "ButtonEvent.h"
#endif

#ifndef ONBUTTONLISTENER_H_
#include "OnButtonListener.h"
#endif

#include <wiringPi.h>

#include <iostream>
#include <string>
#include <thread>
#include <atomic>
#include <list>


using namespace std;

/**********************************************************************************
 * Button class Declaration
 **********************************************************************************/

enum BUTTON_STATE { PUSHED, RELEASED, ERROR };

class Button {
private:
	string _name;
	ushort _pin;
	ushort _activePin;
	BUTTON_STATE _state;
	OnButtonListener* _listener;
	list<OnButtonListener *> _listeners;


public:
	Button(string name, int pin);
	virtual ~Button();
	inline void setName(string name) { _name = name; }
	inline string getName() { return _name; }
	inline void setPin(ushort pin) { _pin  = pin; }
	inline ushort getPin() { return _pin; }
	inline void setState(BUTTON_STATE state) { _state = state; }
	inline BUTTON_STATE getState() { return _state; }
	void setInterrupt();
	void sayHello();

	void setOnButtonListener(OnButtonListener* listener);
	void fireButtonEvent();
};

#endif /* BUTTON_H_ */
