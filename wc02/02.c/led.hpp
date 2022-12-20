// led.hpp

#ifndef _LED_HPP_
#define _LED_HPP_

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <bcm2835.h>

class Led {
    public:
        Led(uint8_t nGPIO);
        ~Led();
        void on(void);
        void off(void);
        void switchStatus();
        void teston(void);
        void testoff(void);
     private:
        uint8_t chosenGPIO;
};

#endif