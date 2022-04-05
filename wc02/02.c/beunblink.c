// Combile beunblink:
// gcc beunblink.c -o blink -lbcm2835

#include <bcm2835.h>
#include <stdio.h>  

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
// #define PIN_RED RPI_GPIO_P1_03
// #define PIN_GREEN RPI_GPIO_P1_05
// #define PIN_BLUE RPI_GPIO_P1_07
#define PIN_RED RPI_V2_GPIO_P1_11
#define PIN_GREEN RPI_V2_GPIO_P1_13
#define PIN_BLUE RPI_V2_GPIO_P1_15

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);

    if (!bcm2835_init())
      return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN_RED, BCM2835_GPIO_FSEL_OUTP);
     // Set the pin to be an output
    bcm2835_gpio_fsel(PIN_GREEN, BCM2835_GPIO_FSEL_OUTP);
     // Set the pin to be an output
    bcm2835_gpio_fsel(PIN_BLUE, BCM2835_GPIO_FSEL_OUTP);

    // Blink
    while (1)
    {
    //bcm2835_delay(200);
	// Turn it on
	bcm2835_gpio_write(PIN_BLUE, HIGH);
	// wait a bit
	bcm2835_delay(200);
	// turn it off
	bcm2835_gpio_write(PIN_BLUE, LOW);
	
    bcm2835_gpio_write(PIN_RED, HIGH);
	// wait a bit
	bcm2835_delay(200);
	// turn it off
	bcm2835_gpio_write(PIN_RED, LOW);
	
    bcm2835_gpio_write(PIN_GREEN, HIGH);
	// wait a bit
	bcm2835_delay(200);
	// turn it off
	bcm2835_gpio_write(PIN_GREEN, LOW);
	


	// wait a bit
	bcm2835_delay(200);
    }
    bcm2835_close();
    return 0;
}

