#ifndef OUTPUTS
#define OUTPUTS

#include <Arduino.h>

//Pin BUZZER
#define PIN_ZUMBADOR 3

//Pin B RGB LED
#define PIN_B_LED_RGB 11
//Pin R RGB LED
#define PIN_R_LED_RGB 12
//Pin G RGB LED
#define PIN_G_LED_RGB 13

class Outputs
{
public:
	Outputs();
	void colorLed(int r, int g, int b);
	void buzzer(int time);
};

#endif
