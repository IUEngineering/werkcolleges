// Code om led's aan te sturen via een knop :)
//
// Compile commando: 
//

#include <bcm2835.h>
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include "button.hpp"
#include "led.hpp"

int main(){

    if (!bcm2835_init()) {
    	 printf("BCM init error!\n");
   	 return 1;
  	};

    Led ledred(4);
    Led ledgreen(17);
    Button redbutton(19);
    Button blackbutton(26);
    Led rgbred(2);
    Led rgbgreen(27);
    Led rgbblue(3);

    while(true){
        if(redbutton.isOn() == 0){
            ledred.on();
            rgbred.on();
            rgbblue.off();
        }
        else if(blackbutton.isOn() == 0){
            ledgreen.on();
            rgbgreen.on();
            rgbblue.off();
        }
        else{
            rgbgreen.off();
            rgbred.off();
            ledred.off();
            ledgreen.off();
            rgbblue.on();
        }
    }

bcm2835_close();
return 0;
}
