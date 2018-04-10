#include "Moves.h"
#include "Outputs.h"

Moves::Moves()
{
	pinMode(PIN_MOTOR_LEFT_1, OUTPUT);
	pinMode(PIN_MOTOR_LEFT_2, OUTPUT);
	pinMode(PIN_MOTOR_RIGHT_1, OUTPUT);
	pinMode(PIN_MOTOR_RIGHT_2, OUTPUT);
}

void Moves::rotateRight(int n)
{
	analogWrite(PIN_MOTOR_RIGHT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_4 / n));
	digitalWrite(PIN_MOTOR_RIGHT_2, LOW);
	analogWrite(PIN_MOTOR_LEFT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_5 / n));
	digitalWrite(PIN_MOTOR_LEFT_2, LOW);
	analogWrite(PIN_G_LED_RGB, 255);
	analogWrite(PIN_R_LED_RGB, 255);
	analogWrite(PIN_B_LED_RGB, 255);
}
	
void Moves::turnRight(int n)
{
	digitalWrite(PIN_MOTOR_RIGHT_1, LOW);
	//analogWrite(PIN_MOTOR_RIGHT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_3 / n));
	//analogWrite(PIN_MOTOR_LEFT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_4 / n));
  analogWrite(PIN_MOTOR_RIGHT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_1 / n));
  analogWrite(PIN_MOTOR_LEFT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_7 / n));
	digitalWrite(PIN_MOTOR_LEFT_2, LOW);
	delay(10);/*
	digitalWrite(PIN_MOTOR_RIGHT_1, LOW);
	digitalWrite(PIN_MOTOR_RIGHT_2, LOW);
	analogWrite(PIN_MOTOR_LEFT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_4 / n));
	digitalWrite(PIN_MOTOR_LEFT_2, LOW);*/
	delay(40);
	analogWrite(PIN_G_LED_RGB, 255);
	analogWrite(PIN_R_LED_RGB, 255);
	analogWrite(PIN_B_LED_RGB, LOW);
}
	
void Moves::rotateLeft(int n)
{
	analogWrite(PIN_MOTOR_RIGHT_1, LOW);
	digitalWrite(PIN_MOTOR_RIGHT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_4 / n));
	analogWrite(PIN_MOTOR_LEFT_1, LOW);
	digitalWrite(PIN_MOTOR_LEFT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_5 / n));
	analogWrite(PIN_G_LED_RGB, 255);
	analogWrite(PIN_R_LED_RGB, 255);
	analogWrite(PIN_B_LED_RGB, 255);
}
	
void Moves::turnLeft(int n)
{
	digitalWrite(PIN_MOTOR_RIGHT_1, LOW);
	//analogWrite(PIN_MOTOR_RIGHT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_3 / n));
	//analogWrite(PIN_MOTOR_LEFT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_4 / n));
  analogWrite(PIN_MOTOR_RIGHT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_1 / n));
  analogWrite(PIN_MOTOR_LEFT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_7 / n));
	digitalWrite(PIN_MOTOR_LEFT_2, LOW);
	delay(10);/*
	digitalWrite(PIN_MOTOR_RIGHT_1, LOW);
	analogWrite(PIN_MOTOR_RIGHT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_3 / n));
	digitalWrite(PIN_MOTOR_LEFT_1, LOW);
	digitalWrite(PIN_MOTOR_LEFT_2, LOW);*/
	delay(40);
	analogWrite(PIN_G_LED_RGB, LOW);
	analogWrite(PIN_R_LED_RGB, LOW);
	analogWrite(PIN_B_LED_RGB, 255);
}

void Moves::front(int n)
{
	digitalWrite(PIN_MOTOR_RIGHT_1, LOW);
	analogWrite(PIN_MOTOR_RIGHT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_2 / n));
	analogWrite(PIN_MOTOR_LEFT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_3 / n));
	digitalWrite(PIN_MOTOR_LEFT_2, LOW);
	analogWrite(PIN_G_LED_RGB, 255);
	analogWrite(PIN_R_LED_RGB, LOW);
	analogWrite(PIN_B_LED_RGB, LOW);
}

void Moves::back(int n)
{
	digitalWrite(PIN_MOTOR_RIGHT_2, LOW);
	digitalWrite(PIN_MOTOR_LEFT_1, LOW);
	analogWrite(PIN_MOTOR_RIGHT_1, (int)(PULSE_MOTOR_SPEED_LEVEL_1 / n));
	analogWrite(PIN_MOTOR_LEFT_2, (int)(PULSE_MOTOR_SPEED_LEVEL_2 / n));
	analogWrite(PIN_G_LED_RGB, LOW);
	analogWrite(PIN_R_LED_RGB, 255);
	analogWrite(PIN_B_LED_RGB, LOW);
}

void Moves::stop()
{
	digitalWrite(PIN_MOTOR_RIGHT_1, LOW);
	digitalWrite(PIN_MOTOR_RIGHT_2, LOW);
	digitalWrite(PIN_MOTOR_LEFT_1, LOW);
	digitalWrite(PIN_MOTOR_LEFT_2, LOW);
	analogWrite(PIN_G_LED_RGB, 0);
	analogWrite(PIN_R_LED_RGB, 255);
	analogWrite(PIN_B_LED_RGB, 0);
}
