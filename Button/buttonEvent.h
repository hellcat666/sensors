/*
 * ButtonEvent.h
 *
 *  Created on: 20 août 2021
 *      Author: Hellcat
 */

#ifndef BUTTONEVENT_H_
#define BUTTONEVENT_H_

#include <string>

using namespace std;

class ButtonEvent {
private:
    std::string _name;
    ushort _pin;

public:
    ButtonEvent(std::string name, ushort pin);
    ~ButtonEvent();
    inline void setName(string name) { _name = name; }
    inline string getName() { return _name; }
    inline void setPin(ushort pin) { _pin = pin; }
    inline ushort getPin() { return _pin; }
};



#endif /* BUTTONEVENT_H_ */
