#include "25lc640a.h"

_25LC640A::_25LC640A(uint8_t PORT, uint8_t SERIAL_OUT, uint8_t SERIAL_IN, uint8_t CLOCK, uint8_t CHIP_SELECT)
: serialobj(PORT, SERIAL_OUT, SERIAL_IN, CLOCK, CHIP_SELECT){

    this->chipSelect(1);
}

uint8_t _25LC640A::eepromRead(uint16_t address){

    uint8_t data = 0;

    this->chipSelect(0);

    this->byteOut((EEPROM_CMD_READ), MSB_FIRST);
    this->byteOut((address & 0xFF00), MSB_FIRST);
    this->byteOut((address & 0x00FF), MSB_FIRST);
    data = byteIn(MSB_FIRST);

    this->chipSelect(1);

    return data;
}

uint8_t _25LC640A::eepromReadBytes(uint16_t address, uint8_t* data_array, uint16_t len){

    this->chipSelect(0);
    this->byteOut(EEPROM_CMD_READ, MSB_FIRST);
    this->byteOut((address & 0xFF00), MSB_FIRST);
    this->byteOut((address & 0x00FF), MSB_FIRST);

    this->bytesIn(data_array, len, MSB_FIRST);

    this->chipSelect(1);

    return 0;

}

void _25LC640A::eepromWriteLatch(uint8_t state){
    this->chipSelect(0);

    if(state == 0){
        this->byteOut(EEPROM_CMD_WRITE_RESET, MSB_FIRST);
    }
    else{
       this->byteOut(EEPROM_CMD_WRITE_ENABLE, MSB_FIRST);
    }

    this->chipSelect(1);
}

void _25LC640A::eepromWrite(uint16_t address, uint8_t data){

    this->eepromWriteLatch(EEPROM_WRITE_ENABLE);

    this->chipSelect(0);
    this->byteOut(EEPROM_CMD_WRITE, MSB_FIRST);

    this->byteOut((address & 0xFF00), MSB_FIRST);
    this->byteOut((address & 0x00FF), MSB_FIRST);

    this->byteOut(data, MSB_FIRST);

    this->chipSelect(1);
}

void _25LC640A::eepromWriteBytes(uint16_t address, uint8_t* data_array, uint16_t len){

    this->eepromWriteLatch(EEPROM_WRITE_ENABLE);

    this->chipSelect(0);
    this->byteOut(EEPROM_CMD_WRITE, MSB_FIRST);

    this->byteOut((address & 0xFF00), MSB_FIRST);
    this->byteOut((address & 0x00FF), MSB_FIRST);

    this->bytesOut(data_array, len, MSB_FIRST);

    this->chipSelect(1);
}

uint8_t _25LC640A::eepromReadStatusReg(){

    uint8_t data = 0;

    this->chipSelect(0);
    this->byteOut(EEPROM_CMD_READ_STATREG, MSB_FIRST);
    data = this->byteIn(MSB_FIRST);
    this->chipSelect(1);

    return data;

}

void _25LC640A::eepromWriteStatusReg(uint8_t data){

    this->chipSelect(0);
    this->byteOut(EEPROM_CMD_WRITE_STATREG, MSB_FIRST);
    this->byteOut(data, MSB_FIRST);
    this->chipSelect(1);

}


