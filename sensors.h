/*
 * foo.h
 *
 *  Created on: 17 août 2021
 *      Author: Hellcat
 */

#ifndef SENSORS_H_
#define SENSORS_H_

#ifndef BUTTON_H_
#include "Button/button.h"
#endif

#ifndef DHT11SENSOR_H_
#include "DHT11/DHT11Sensor.h"
#endif

#ifndef LED_H_
#include "Led/led.h"
#endif

#ifndef RELAY_H_
#include "Relay/relay.h"
#endif


#ifndef HCSR04_H_
#include "HC-SR04/hcsr04.h"
#endif

extern void foo(void);

#endif /* SENSORS_H_ */
