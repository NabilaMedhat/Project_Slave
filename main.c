/*
 * File:   main.c
 * Author: Nabila
 *
 * Created on June 23, 2020, 10:43 PM
 */

#include "SPI_SLAVE.h"

char Buffer[20];
char O1[] = "O1";
char C1[] = "C1";
char O2[] = "O2";
char C2[] = "C2";

int main(void) {
    SPI_Slave_init();
    DDRC = 0xFF;
    DDRA = 0xFF;
    DDRD = 0xFF;
    /* Replace with your application code */
    while (1) {
        /* data = SPI_Receive();
         if (data == 'O') {
             PORTC = 0xFF;
         } else if (data == 'C') {
             PORTC = 0x00;
         } else {
             PORTC = 0x08;
         }*/
        
        SPI_ReceiveString(Buffer);
        if (checkData(Buffer, O1)) {
            PORTC = 0xFF;
        } else if (checkData(Buffer, C1)) {
            PORTC = 0x00;
        } else if (checkData(Buffer, O2)) {
            PORTD = 0xFF;
        } else if (checkData(Buffer, C2)) {
            PORTD = 0x00;
        }
    }
}

