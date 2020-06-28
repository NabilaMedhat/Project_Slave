/*
 * File:   main.c
 * Author: Nabila
 *
 * Created on June 23, 2020, 10:43 PM
 */

#include "SPI_SLAVE.h"
#include "GPIO.h"

char Buffer[20];
char O1[] = "O1";
char C1[] = "C1";
char O2[] = "O2";
char C2[] = "C2";

int main(void) {
    SPI_Slave_init();
    dirIO_DDRX(PC2, ddrC, output);
    dirIO_DDRX(PD3, ddrD, output);
    while (1) {
        SPI_ReceiveString(Buffer);
        if (checkData(Buffer, O1)) {
            setPIN(PC2, portC);
        } else if (checkData(Buffer, C1)) {
            resetPIN(PC2, portC);
        } else if (checkData(Buffer, O2)) {
            setPIN(PD3, portD);
        } else if (checkData(Buffer, C2)) {
            resetPIN(PD3, portD);
        }
    }
}

