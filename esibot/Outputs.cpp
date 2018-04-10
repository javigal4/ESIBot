#include "Outputs.h"

Outputs::Outputs()
{
	pinMode(PIN_R_LED_RGB, OUTPUT);
	pinMode(PIN_G_LED_RGB, OUTPUT);
	pinMode(PIN_B_LED_RGB, OUTPUT);
	pinMode(PIN_ZUMBADOR, OUTPUT);
}

void Outputs::colorLed(int r, int g, int b)
{
	analogWrite(PIN_G_LED_RGB, r);
	analogWrite(PIN_R_LED_RGB, g);
	analogWrite(PIN_B_LED_RGB, b);
}

void Outputs::buzzer(int time)
{
	digitalWrite(PIN_ZUMBADOR, HIGH);
	delay(time);
	digitalWrite(PIN_ZUMBADOR, LOW);
}