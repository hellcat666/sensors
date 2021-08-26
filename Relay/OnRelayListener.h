/*
 * OnRelayListener.h
 *
 *  Created on: 23 août 2021
 *      Author: Hell
 */

#ifndef ONRELAYLISTENER_H_
#define ONRELAYLISTENER_H_

#ifndef RELAYEVENT_H_
#include "relayEvent.h"
#endif

class OnRelayListener {
public:
    virtual ~OnRelayListener() { }
    virtual void onRelay(RelayEvent event) { }
};

#endif /* ONRELAYLISTENER_H_ */
