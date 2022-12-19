// 02.c button.hpp

#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <bcm2835.h>

class Button {
    public:
        Button(uint8_t nGPIO);
        ~Button();
        bool isOn(void);
     private:
	    uint8_t chosenGPIO;
};

#endif
