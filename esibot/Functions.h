#ifndef FUNCTIONS
#define FUNCTIONS

#include <Arduino.h>
#include "Moves.h"
#include "Sensors.h"
#include "Outputs.h"

class Functions
{
public:
  void choose();
	void sumo();
	void remoteControl();
	void followLine();
  void moveUS();
  void moveIR();
  boolean checkBatteryStatus();
private:
  Moves *_moves;
  Sensors *_sensors;
  Outputs *_outputs;
  bool conf;
};

#endif
