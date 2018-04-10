#ifndef MOVES
#define MOVES

#include <Arduino.h>

// Pin 1 LEFT MOTOR
#define PIN_MOTOR_LEFT_1 6
// Pin 2 LEFT MOTOR
#define PIN_MOTOR_LEFT_2 5
// Pin 1 RIGHT MOTOR
#define PIN_MOTOR_RIGHT_1 9
// Pin 2 RIGHT MOTOR
#define PIN_MOTOR_RIGHT_2 10

/*MACROS PULSE CONFIGURATION*/
//PWM pulse for level 1/7 motor speed
#define PULSE_MOTOR_SPEED_LEVEL_1 100
//PWM pulse for level 2/7 motor speed
#define PULSE_MOTOR_SPEED_LEVEL_2 160
//PWM pulse for level 3/7 motor speed
#define PULSE_MOTOR_SPEED_LEVEL_3 180
//PWM pulse for level 4/7 motor speed
#define PULSE_MOTOR_SPEED_LEVEL_4 210
//PWM pulse for level 5/7 motor speed
#define PULSE_MOTOR_SPEED_LEVEL_5 230
//PWM pulse for level 6/7 motor speed
#define PULSE_MOTOR_SPEED_LEVEL_6 240
//PWM pulse for level 7/7 motor speed
#define PULSE_MOTOR_SPEED_LEVEL_7 255
/*END MACROS PULSE CONFIGURATION*/


class Moves
{
public:
	Moves();

	void rotateRight(int speed);
	void turnRight(int speed);
	
	void rotateLeft(int speed);
	void turnLeft(int speed);

	void front(int speed);
	void back(int speed);


	void stop();
};

#endif
