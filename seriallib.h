#pragma once
#ifndef SERIALLIB_H_
#define SERIALLIB_H_
#include <stdint.h>
#include <msp430.h>

#define MSB_FIRST 1
#define LSB_FIRST 0

class serialobj{
    public:
        serialobj(uint8_t PORT, uint8_t SERIAL_OUT, uint8_t SERIAL_IN, uint8_t CLOCK, uint8_t CHIP_SELECT);
        uint8_t byteOut(uint8_t data, uint8_t direction);
        uint8_t byteIn(uint8_t direction);
        void chipSelect(uint8_t out);
        void setSDA(uint8_t out);
        uint8_t readSDA();
        void setCLK(uint8_t out);

    private:
        unsigned char SDA_IN;
        unsigned char SDA_OUT;
        unsigned char CLK;
        unsigned char SELECT;

        volatile unsigned char* PORT_OUT;
        volatile unsigned char* PORT_IN;
        volatile unsigned char* PORT_DIR;
};



#endif /* SERIALLIB_H_ */
