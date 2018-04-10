#include "Functions.h"

void Functions::choose()
{
	String s = Serial1.readString();
	if (s == "choose")
	  conf = true;
	else if (s == "back")  
	  conf = false;

  if (conf)
  {
    switch (s[0])
    {
      case 1: sumo(); break;
      case 2:
        followLine(); break;
      case 3:
        remoteControl();
        Serial1.println(2);
        break;
    }
  }
}

void Functions::sumo()
{
	while (!_sensors->obstacleOpposite())
		_moves->rotateRight(2);
   
	_moves->front(2);
	
	if (_sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_LEFT_CNY))
	{
		_moves->back(2);
		delay(500);
		_moves->rotateRight(2);
		delay(1000);
	}
}

void Functions::remoteControl()
{
	int val;
  int vel = 2;
	int bytes = Serial1.available();

	if (bytes > 0)
	{
		val = Serial1.read();
		Serial.println(val);
	}
	 
	switch (val)
	{
		case 10: _moves->front(vel); break;
		case 11: _moves->back(vel); break;
		case 12: _moves->turnRight(vel); break;
		case 13: _moves->turnLeft(vel); break;
		case 14: _moves->rotateRight(vel); break;
		case 15: _moves->rotateLeft(vel); break;
    case 16: 
      switch (vel)
      {
        case 1: vel = 4;
        case 2: vel--;
        case 3: vel--;
        case 4: vel--;
      } break;
		default:
		  _moves->stop();
		  conf = false;
		  break;
	}
}

void Functions::followLine()
{
	int vel = 2;
	//CNYs in the middle detect black
	if (_sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_LEFT_CNY) && _sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_RIGHT_CNY))
	{
		if (!_sensors->isBlack(PIN_SENSOR_FRONTAL_LEFT_CNY) && !_sensors->isBlack(PIN_SENSOR_FRONTAL_RIGHT_CNY) && 
		    !_sensors->isBlack(PIN_SENSOR_BACK_LEFT_CNY) && !_sensors->isBlack(PIN_SENSOR_BACK_RIGHT_CNY))
			_moves->front(vel);
	}
	else if (_sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_LEFT_CNY) && !_sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_RIGHT_CNY))
	{
		while (!_sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_RIGHT_CNY))
			_moves->rotateLeft(vel);
		_moves->turnLeft(vel);
		delay(20);
		_moves->front(vel);
	}
	else if (_sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_RIGHT_CNY) && !_sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_LEFT_CNY))
	{
		while (!_sensors->isBlack(PIN_SENSOR_FRONTAL_CENTER_LEFT_CNY))
			_moves->rotateRight(vel);
		_moves->turnRight(vel);
		delay(20);
		_moves->front(vel);
	}
	else
	{
		if (_sensors->isBlack(PIN_SENSOR_BACK_RIGHT_CNY))
		{
			_moves->turnLeft(vel);
			delay(40);
		}
		else if (_sensors->isBlack(PIN_SENSOR_BACK_LEFT_CNY))
		{
			_moves->turnRight(vel);
			delay(40);
		}
	}
}

boolean Functions::checkBatteryStatus()
{
//  float battery_med;//variable para calcular la media de varias lecturas
//  int battery=analogRead(PIN_BATTERY_METER); //Lee batería
//
//  contBatteryStatus++;
//  sumBatteryStatus+=battery;
//
////   if(contBatteryStatus == 15){
////      int battery_med = sumBatteryStatus/15;
////      Serial.println(battery);
////      Serial.println(battery_med);
////      Serial.println(contBatteryStatus);
////      Serial.println("*******");
////      if(battery_med < 720){ //Si es menor del mínimo (720 ~ 7 V):
////
////          analogWrite(PIN_G_LED_RGB, 255);
////          analogWrite(PIN_R_LED_RGB, 0);
////          analogWrite(PIN_B_LED_RGB, 0);
////          //tone(PIN_ZUMBADOR, 1500, 500);
////          delay(500);
////          analogWrite(PIN_G_LED_RGB, 0);
////          analogWrite(PIN_R_LED_RGB, 255);
////          analogWrite(PIN_B_LED_RGB, 0);
////          //tone(PIN_ZUMBADOR, 2000, 500);
////                delay(500);
////          analogWrite(PIN_G_LED_RGB, 0);
////          analogWrite(PIN_R_LED_RGB, 0);
////          analogWrite(PIN_B_LED_RGB, 255);
////          //tone(PIN_ZUMBADOR, 2500, 500);
////                delay(500);
////          analogWrite(PIN_G_LED_RGB, 0);
////          analogWrite(PIN_R_LED_RGB, 0);
////          analogWrite(PIN_B_LED_RGB, 0);
////            //    noTone(PIN_ZUMBADOR);
////                delay(500);
////          contBatteryStatus = 0;
////          sumBatteryStatus=0;
////          return false;
////
////        }
////      else if(battery_med >= 720){//Si el nivel de batería es bueno:
////
////          if(battery_med < 760){//(720 ~ 7V < nivel de batería < 760 ~ 7.4V)
////            //Cerca de agotarse la batería.
////            //Emite 3 pitidos
////
////            for(int i=0;i<3;i++){
////        tone(PIN_ZUMBADOR, 3000, 200);
////        noTone(PIN_ZUMBADOR);
////              delay(200);
////              }
////      }
////      contBatteryStatus = 0;
////        sumBatteryStatus=0;
////          analogWrite(PIN_G_LED_RGB, 0);
////          analogWrite(PIN_R_LED_RGB, 0);
////          analogWrite(PIN_B_LED_RGB, 0);
////        return true;
////    }
////    }
}
