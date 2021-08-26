/*
 * OnHCSR04Listener.h
 *
 *  Created on: 25 août 2021
 *      Author: Hell
 */

#ifndef ONHCSR04LISTENER_H_
#define ONHCSR04LISTENER_H_

#ifndef HCSR04EVENT_H
#include "HCSR04Event.h"
#endif

class OnHCSR04Listener {
public:
    virtual ~OnHCSR04Listener() { }
    virtual void onHCSR04(HCSR04Event event) { }
};

#endif /* ONHCSR04LISTENER_H_ */
