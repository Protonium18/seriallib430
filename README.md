# seriallib430
A C++ object-oriented SPI bitbanging library designed for the MSP430. This library is intended to be extensible and simple to comprehend, while maintaining a high degree of performance and control. It is capable of operating in both 3-wire and 4-wire modes. 

Documentation:

  Macros:
   - LSB_FIRST = 0 - Used to specify the direction of data transfer. With LSB_FIRST, data will be interpreted/shifted out from the least significant bit.
   - MSB_FIRST = 1 - Used to specify the direction of data transfer. With MSB_FIRST, data will be interpreted/shifted out from the most significant bit.
   - NULL_PIN = 99 - Used to specify a pin that is not in use. The pin will not be initialized or set.
    

serialobj(uint8_t PORT, uint8_t SERIAL_OUT, uint8_t SERIAL_IN, uint8_t CLOCK, uint8_t CHIP_SELECT)
  - serialobj can only be initialized with a single port at this time. The PORT argument dictates which port this is.
  - SERIAL_OUT is the pin on which data is shifted out.  
  - SERIAL_IN is the pin on which data is shifted in.
  - CLOCK is the pin used to synchronize data transfer with a given peripheral.
  - CHIP_SELECT is the pin used to set peripherals to an active state. This pin is not set or cleared by default.
  - Upon construction, SERIAL_OUT, CLOCK, and CHIP_SELECT bits in PxDIR register are set to 1, setting them to output.
  - All pins are not set in PxOUT, and their peripheral status is not set nor checked. These values are intended to be set by the developer for a given         peripheral.
  - The constructor does not check if the values input are valid. If an erroneous value is input, the object will still be constructed and most likely not     work correctly. 
  - If intended to be used in 3-wire mode, set CHIP_SELECT to NULL_PIN.
  - If the clock polarity of a peripheral is expected to be high, setCLK(1) should be called in order to set the clock pin to high.

void serialobj::byteOut(uint8_t data, uint8_t direction)
  - The data parameter is the data to be shifted out.
  - The direction parameter dictates whether the data is shifted out by most significant bit first or least significant first. Without an argument, it will     default to LSB_FIRST.
  - This function will return a value of 0.
