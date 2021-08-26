
/*
 * dht11.cpp
 *
 *  Created on: 16 août 2021
 *      Author: Hellcat
 */
#ifndef DHT11_H_
#include "dht11.h"
#endif

using namespace std;

DHT11::DHT11(int pin) {
	_name = "DHT11";
    _pin = pin;
    _units = CELSIUS;
    _tempCelsius = 0;
	_tempFarenheit = 0.0f;
    _humidity = 0;
    _measuring = false;
    _interval = 2000;
    _state = STOPPED;
}

DHT11::~DHT11() {}

void DHT11::start() {
    _measuring = true;
    setInterval(2000);
    _dht11 = thread(DHT11::read_dht11_data, this);
    _dht11.detach();
}

void DHT11::stop() {
    _measuring = false;
}

bool DHT11::isRunning() {
    return _measuring;
}

void DHT11::read_dht11_data(DHT11* dht11)
{
    int DHTPIN = dht11->getPin();
    int dht11_data[5];
	uint8_t laststate;
	uint8_t counter;
	uint8_t j, i;
	float	f;

    do {
        laststate = HIGH;
        counter = 0;
        i = 0;
        j = 0;

        dht11_data[0] = dht11_data[1] = dht11_data[2] = dht11_data[3] = dht11_data[4] = 0;

        pinMode( DHTPIN, OUTPUT );
        digitalWrite( DHTPIN, LOW );
        delay( 20 );
        digitalWrite( DHTPIN, HIGH );
        delayMicroseconds( 40 );
        pinMode( DHTPIN, INPUT );

        for ( i = 0; i < MAXTIMINGS; i++ )
        {
            counter = 0;
            while ( digitalRead( DHTPIN ) == laststate )
            {
                counter++;
                delayMicroseconds( 1 );
                if ( counter == 255 )
                {
                    break;
                }
            }
            laststate = digitalRead( DHTPIN );

            if ( counter == 255 )
                break;

            if ( (i >= 4) && (i % 2 == 0) )
            {
                dht11_data[j / 8] <<= 1;
                if ( counter > 50 )
                    dht11_data[j / 8] |= 1;
                j++;
            }
        }

        if ( (j >= 40) &&
            (dht11_data[4] == ( (dht11_data[0] + dht11_data[1] + dht11_data[2] + dht11_data[3]) & 0xFF) ) )
        {
			dht11->setHumidity(dht11_data[0]);
            f = dht11_data[2] * 9. / 5. + 32;
			dht11->setTempCelsius(dht11_data[2]);
			dht11->setTempFarenheit(f);
			/* Used for Debugging
			printf("data[0]: %d\n\n",dht11_data[0]);
			printf("data[1]: %d\n\n",dht11_data[1]);
			printf("data[2]: %d\n\n",dht11_data[2]);
			printf("data[3]: %d\n\n",dht11_data[3]);
			printf("f: %.1f\n\n",f);
			*/
            printf( "Humidity = %d.%d %% Temperature = %d.%d C (%.1f F)\n",
                dht11_data[0], dht11_data[1], dht11_data[2], dht11_data[3], f );
        }else  {
            printf( "Data not good, skip\n" );
        }
//        raise(SIGUSR1);	NOT USED (Does'nt support parameters)
		dht11->fireDHT11Event();
        delay(dht11->getInterval());

    } while (dht11->isRunning());
}

void DHT11::setOnDHT11Listener(OnDHT11Listener* listener) {

    _listeners.push_front(listener);
}

void DHT11::fireDHT11Event() {
    DHT11Event event = DHT11Event(_name, getTempCelsius(), getTempFarenheit(), getHumidity(), "°C");
    for(OnDHT11Listener* listener : _listeners) {
	    listener->onDHT11(event);
    }
}




