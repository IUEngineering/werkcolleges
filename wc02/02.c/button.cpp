#include "button.hpp"

Button::Button(uint8_t nGPIO){
    chosenGPIO = nGPIO;
    bcm2835_gpio_fsel(chosenGPIO, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(chosenGPIO, BCM2835_GPIO_PUD_UP);
};

Button::~Button(){
    
};

bool Button::isOn(void){
    uint8_t value;
    value = bcm2835_gpio_lev(chosenGPIO);
    return value;
};
