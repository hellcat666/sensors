/*
 * OnButtonListener.h
 *
 *  Created on: 20 août 2021
 *      Author: Hell
 */

#ifndef ONBUTTONLISTENER_H_
#define ONBUTTONLISTENER_H_

#ifndef BUTTONEVENT_H
#include "ButtonEvent.h"
#endif

class OnButtonListener {
public:
    virtual ~OnButtonListener() { }
    virtual void onButton(ButtonEvent event) { }
};

#endif /* ONBUTTONLISTENER_H_ */
