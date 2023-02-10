#pragma once

#ifndef LC640A_H_
#define LC640A_H_

#include "seriallib.h"

#define EEPROM_CMD_READ 0x03
#define EEPROM_CMD_WRITE 0x02
#define EEPROM_CMD_WRITE_ENABLE 0x06
#define EEPROM_CMD_WRITE_RESET 0x04
#define EEPROM_CMD_READ_STATREG 0x05
#define EEPROM_CMD_WRITE_STATREG 0x01

#define EEPROM_WRITE_ENABLE 0x01
#define EEPROM_WRITE_REST 0x00

class _25LC640A : public serialobj{
    public:
        _25LC640A(uint8_t PORT, uint8_t SERIAL_OUT, uint8_t SERIAL_IN, uint8_t CLOCK, uint8_t CHIP_SELECT);
        uint8_t eepromRead(uint16_t address);
        uint8_t eepromReadBytes(uint16_t address, uint8_t* data_array, uint16_t len);
        void eepromWrite(uint16_t address, uint8_t data);
        void eepromWriteBytes(uint16_t address, uint8_t* data_array, uint16_t len);
        void eepromWriteLatch(uint8_t state);
        uint8_t eepromReadStatusReg();
        void eepromWriteStatusReg(uint8_t data);


    private:
};



#endif
