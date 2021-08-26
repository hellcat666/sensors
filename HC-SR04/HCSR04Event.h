/*
 * HCSR04Event.h
 *
 *  Created on: 25 août 2021
 *      Author: Hell
 */

#ifndef HCSR04EVENT_H_
#define HCSR04EVENT_H_

#include <string>

using namespace std;

class HCSR04Event {
private:
    std::string _name;
    double _distance;

public:
    HCSR04Event(string name, double distance);
    ~HCSR04Event();
    inline void setName(string name) { _name = name; }
    inline string getName() { return _name; }
    inline void setDistance(double distance) { _distance = distance; }
    inline double getDistance() { return _distance; }
};

#endif /* HCSR04EVENT_H_ */
