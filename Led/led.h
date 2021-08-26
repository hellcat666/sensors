/*
 * Led.h
 *
 *  Created on: 18 août 2021
 *      Author: Hell
 */

#ifndef LED_H_
#define LED_H_

#include <wiringPi.h>

#include <atomic>
#include <string>
#include <thread>

using namespace std;

enum LED_STATE { LED_OFF, LED_ON, LED_BLINKING };

class Led {
private:
	string _name;
	int _pin;
	LED_STATE _state;
	int _delay;
    std::thread _blink;
	std::atomic<bool> _blinking;
public:
	Led(string name, int pin);
	~Led();
	inline void setName(string name) { _name = name; }
	inline string getName() { return _name; }
	inline void setState(LED_STATE state) { _state = state; }
	inline LED_STATE getState() { return _state; }
	inline void setDelay(int delay) { _delay = delay; }
	inline int getDelay() { return _delay; }
	void On();
	void Off();
	bool isOn();
	void Blink(int duration);
	bool isBlinking();
	void Reset();
	static void toggle(Led* led);
};

#endif /* LED_H_ */
