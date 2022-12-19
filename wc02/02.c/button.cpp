#include "button.hpp"

Button::Button(uint8_t nGPIO){
    chosenGPIO = nGPIO;
};

Button::~Button(){

};

bool Button::isOn(void){
    uint8_t value;
    value = bcm2835_gpio_lev(chosenGPIO);
    return value;
};
