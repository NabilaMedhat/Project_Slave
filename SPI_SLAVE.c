/*
 * File:   SPI_SLAVE.c
 * Author: Nabila
 *
 * Created on June 27, 2020, 3:28 AM
 */


#include "SPI_SLAVE.h"

void SPI_Slave_init() {
    DDRB |= (1 << MISO);
    SPCR |= (1 << SPE) | (1 << SPR1) | (1 << SPR0); // | (1 << SPIE);
}

char SPI_Receive() /* SPI Receive data function */ {
    while (!(SPSR & (1 << SPIF))); /* Wait till reception complete */
    return (SPDR); /* Return received data */
}

void SPI_Transmit(char data) /* SPI write data function */ {
    char flush_buffer;
    SPDR = data; /* Write data to SPI data register */
    while (!(SPSR & (1 << SPIF))); /* Wait till transmission complete */
    flush_buffer = SPDR; /* Flush received data */
    /* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and then accessing SPDR hence flush buffer used here to access SPDR after SPSR read */
}

void SPI_ReceiveString(char *str) {
    unsigned int i = 0;
    str[i] = SPI_Receive();
    while (str[i] != ' ') {
        i++;
        str[i] = SPI_Receive();
    }
    str[i] = '\0';
}

void SPI_TransmitString(char *str) {
    while (*str) {
        SPI_Transmit(*str);
        str++;
    }
}

int checkData(char *buffer, char *cmpStr) {
    int flag = strcmp(buffer, cmpStr);
    return flag == 0 ? 1 : 0;
}