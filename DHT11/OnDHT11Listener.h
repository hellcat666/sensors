/*
 * OnDHT11Listener.h
 *
 *  Created on: 16 août 2021
 *      Author: Hellcat
 */

#ifndef ONDHT11LISTENER_H_
#define ONDHT11LISTENER_H_

#ifndef DHT11EVENT_H_
#include "DHT11Event.h"
#endif

class OnDHT11Listener {
public:
	virtual ~OnDHT11Listener() { }
	virtual void onDHT11(DHT11Event event) { }
};

#endif /* ONDHT11LISTENER_H_ */
