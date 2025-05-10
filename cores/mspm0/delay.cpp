#include "Arduino.h"

extern "C" void delay(unsigned long ms) __attribute__((weak));
extern "C" void yield() __attribute__((weak));

// The code assumes that MCU is running at MCLK - 32MHz

extern "C"
{

    void delay(unsigned long ms) {
        if (!ms) {
            return;
        }

        delay_cycles(ms * 32000);
    }

    void delayMicroseconds(unsigned int usec) {
        if (!usec) {
            return;
        }
        delay_cycles(usec * 32);
    }

    void yield() {
       // Dummy
       delay_cycles(1);
    }


    unsigned long millis() {
       //TODO
      return 1;
    }

    unsigned long micros() {
      //TODO
        return 1;
    }

} // extern C
