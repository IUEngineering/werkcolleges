#include <stdio.h>
#include "button.hpp"

int main(void){

	if (!bcm2835_init()) {
    	 printf("BCM init error!\n");
   	 return 1;
  	};

	Button button1(23);
	Button button2(24);
	Button button3(25);

	while(1){
		if(button1.isOn() == 0){
				printf("help\n");
			}
			else{
				printf("the button is on\n");
			};
	}

bcm2835_close();
return 0;
}

