/*
 * RelayEvent.h
 *
 *  Created on: 23 août 2021
 *      Author: Hell
 */

#ifndef RELAYEVENT_H_
#define RELAYEVENT_H_

#include <string>

using namespace std;

class RelayEvent {
private:
	string _name;
	ushort _pin;
	bool _state;

public:
	RelayEvent(string name, ushort pin, bool state);
	~RelayEvent();
    inline void setName(string name) { _name = name; }
    inline string getName() { return _name; }
    inline void setPin(ushort pin) { _pin = pin; }
    inline ushort getPin() { return _pin; }
    inline void setState(bool state) { _state = state; }
    inline bool getState() { return _state; }
};




#endif /* RELAYEVENT_H_ */
