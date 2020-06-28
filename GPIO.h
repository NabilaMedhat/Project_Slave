/* 
 * File:   GPIO.h
 * Author: Nabila
 *
 * Created on June 28, 2020, 11:50 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <avr/io.h>

    enum PortD {
        Button0, Button1, Button2, Relay, Buzzer, LED0, LED1, LED2
    };

    enum portX {
        portA, portB, portC, portD
    };

    enum ddrX {
        ddrA, ddrB, ddrC, ddrD
    };

    enum pinX {
        pinA, pinB, pinC, pinD
    };

    enum Direction {
        input, output
    };
    
    
    void dirIO_DDRX(int pinNum, char port, int direction);
    void DDRXas(char ddrx, int direction);
    void setPORT(char port);
    void resetPORT(char port);
    int isPressed(int pinNum, char pin);
    void setPIN(int pinNum, char port);
    void resetPIN(int pinNum, char port);
    void togglePIN(int pinNum, char port);

#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

