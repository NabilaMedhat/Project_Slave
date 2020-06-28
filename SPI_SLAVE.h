/* 
 * File:   SPI_SLAVE.h
 * Author: Nabila
 *
 * Created on June 27, 2020, 3:29 AM
 */

#ifndef SPI_SLAVE_H
#define	SPI_SLAVE_H

#ifdef	__cplusplus
extern "C" {
#endif


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

    void SPI_Slave_init();
    char SPI_Receive();
    void SPI_Transmit(char data);
    void SPI_ReceiveString(char *str);
    void SPI_TransmitString(char *str);
    int checkData(char *buffer, char *cmpStr);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_SLAVE_H */

