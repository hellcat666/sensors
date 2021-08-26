/*
 * button.cpp
 *
 *  Created on: 19 août 2021
 *      Author: Hellcat
 */
#ifndef BUTTON_H_
#include "button.h"
#endif

#include <list>
#include <vector>

using namespace std;

// Button Interrupt Management Stuff
static vector<Button*> buttons;		// List of created Button Objects
static vector<uint> pins;			// List of GPIO Pins assigned
									// to the previously created Button Objects
static uint currentPin;				// Pin number of the currently activated Button

static Button* search(ushort pin);	// Returns Button Object according to the given Pin number
static void intFunc();				// Interrupt HAndler function

/**********************************************************************************
 * static void intFunc(void)
 **********************************************************************************
 * This is the Interrupt handler function.
 * It is called each time an Interrupt occurs
 * It scans the GPIO Ports according to the list of Pins
 * currently assigned to the Buttons.
 * Once detected, it retrieves the Object and calls the appropriate method.
 * (For test, it just calls the sayHello() function)
 *
 **********************************************************************************/
static void intFunc() {
Button* b = nullptr;
uint pin = 0;
	for (uint i=0; i<pins.size(); i++) {
		pin = pins[i];
		if(digitalRead(pin)!=0) {
			b = search(pin);
			if(b!=nullptr) {
				currentPin = pin;
				/*
				char buf[50];
				sprintf(buf, "Pin #%d Active", pin);
				std::cout << buf << std::endl;
				*/
				b->fireButtonEvent();
			}
		}
	}
	delay(500);
}

/**********************************************************************************
 * static Button* search(ushort pin)
 **********************************************************************************
 *
 **********************************************************************************/
static Button* search(ushort pin) {
	for(Button* b : buttons)
		if(b->getPin()==pin)
			return b;
	return  nullptr;
}


/**********************************************************************************
 * Button class Implementation
 **********************************************************************************/
Button::Button(string name, int pin) {
	setName(name);
	setPin(pin);
	setState(RELEASED);
	setInterrupt();
	buttons.push_back(this);
	pins.push_back(getPin());
}

Button::~Button() { }

void Button::setInterrupt() {
	if(wiringPiISR(getPin(), INT_EDGE_RISING, intFunc)<0) {
		cout << "Failed to initialize GPIO Interrupt Service..." << endl;
		setState(ERROR);
	}
	else {
		setState(RELEASED);
	}
}

/*
void Button::setMonitoring() {
	_running = true;
	_monitor = thread(Button::check, this);
}

void Button::check(Button* button) {
	do {
		Button* b = search(currentPin);
		if(b!=nullptr) b->sayHello();
		currentPin = 0;
		delay(500);
	}while(button->isRunning());
}
*/

void Button::sayHello() {
	char buf[50];
	sprintf(buf, "%s has been PRESSED", getName().c_str());
	cout << buf << endl;
	currentPin = 0;
}

void Button::setOnButtonListener(OnButtonListener* listener) {
    _listeners.push_front(listener);
}

void Button::fireButtonEvent() {
    ButtonEvent event = ButtonEvent(_name, _pin);
    for(OnButtonListener* listener : _listeners) {
	    listener->onButton(event);
    }
}
