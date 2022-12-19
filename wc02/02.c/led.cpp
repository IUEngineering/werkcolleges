// led.cpp
#include "led.hpp"

// Led constructor, nGPIO is the gpio pin of the LED.
Led::Led(uint8_t nGPIO){
    chosenGPIO = nGPIO;
};

// Led destructor.
Led::~Led(){

};

// Set nGPIO pin HIGH (turn chosen the LED on).
void Led::on(void){
    bcm2835_gpio_set(chosenGPIO);
};

// Set nGPIO pin LOW (turn the chosen LED off).
void Led::off(void){
    bcm2835_gpio_clr(chosenGPIO);
};

// Set nGPIO to the opposite value. 
void Led::switchStatus(){
    switch(bcm2835_gpio_lev(chosenGPIO)){
        case 0:
            bcm2835_gpio_set(chosenGPIO);
            break;
        case 1:
            bcm2835_gpio_clr(chosenGPIO);
            break;
    };
};