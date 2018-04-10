#include "Functions.h"

//Pin medidor de batería.
#define PIN_BATTERY_METER A6

int contBatteryStatus;
int sumBatteryStatus;
boolean batteryStatus = true; //'true' Estado de la batería OK, 'false' batería agotada

//variable de la interrupcion
volatile boolean noAbatido = true;

Functions *functions;

void setup() {
  Serial1.begin(9600);
  pinMode(PIN_BATTERY_METER, INPUT);
  sumBatteryStatus = 0;
  contBatteryStatus = 0;
  // se introduce la interrupcion
  attachInterrupt(digitalPinToInterrupt(1), muerto, RISING);
}

void loop() {
  functions->followLine();
}



void muerto()
{
  noAbatido = false;
  detachInterrupt(digitalPinToInterrupt(1));
}
