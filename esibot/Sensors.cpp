#include "Sensors.h"

Sensors::Sensors()
{
	pinMode(PIN_SENSOR_FRONTAL_LEFT_CNY, INPUT);
	pinMode(PIN_SENSOR_FRONTAL_CENTER_LEFT_CNY, INPUT);
	pinMode(PIN_SENSOR_FRONTAL_CENTER_RIGHT_CNY, INPUT);
	pinMode(PIN_SENSOR_FRONTAL_RIGHT_CNY, INPUT);
}

long Sensors::GetUltraSoundValue(int port)
{
	long distancia;
	//Ex: port = 2;
	long longTime;
	pinMode(port, OUTPUT);
	digitalWrite(port, LOW);
	delayMicroseconds(2);
	digitalWrite(port, HIGH);
	delayMicroseconds(5);
	digitalWrite(port, LOW);
	pinMode(port, INPUT);
	longTime = pulseIn(port, HIGH);

	distancia = TimeMsToDistanceCm(longTime);
	return distancia;
}

long Sensors::TimeMsToDistanceCm(long ms)
{
	return ms / 29 / 2;
}

bool Sensors::isBlack(int port)
{
	int value = analogRead(port);
	if (value < CNY_VALUE_UMBRAL_BLACK) //El suelo no es de color negro, movimientos con paredes y ultrasonidos
		return false;
	return true;
}

bool Sensors::obstacleOpposite()
{
	if (GetUltraSoundValue(PIN_SENSOR_FRONTAL_ULTRASOUND) < DIST_COLISION)
		return true;
	
	return false;
}
