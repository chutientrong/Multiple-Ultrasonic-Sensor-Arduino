#include "OneSensor.h"

Sensor::Sensor(uint8_t index, uint8_t trigPin, uint8_t echoPin)
:
  _index(index),
  _trigPin(trigPin),
  _echoPin(echoPin),
  _state(OK),
  _distance(0)
{
}


void Sensor::Init()
{
  pinMode(TrigPin()  , OUTPUT);
  pinMode(EchoPin()  , INPUT);
}


void Sensor::Process()
{
  Measure();
  UpdateState();
//  ProcessState();
  PrintDistance();
  delay(100);
}


void Sensor::Measure()
{
  digitalWrite(TrigPin(), HIGH);
  delayMicroseconds (10);
  digitalWrite(TrigPin(), LOW);
  uint16_t duration = pulseIn (EchoPin(), HIGH);
  _distance = (duration / 2) / 29.1;
}


void Sensor::UpdateState()
{
  if (_distance < 0)
  {
    _state = LOW_OUT_OF_RANGE;
  }
  else if (_distance <= 50)
  {
    _state = WAY_TOO_CLOSE;
  }
  else if (_distance <= 100)
  {
    _state = TOO_CLOSE;
  }
  else if (_distance <= 200)
  {
    _state = OK;
  }
  else 
  {
    _state = HIGH_OUT_OF_RANGE;
  }
}


void Sensor::ProcessState()
{

  switch (_state)
  {
  case LOW_OUT_OF_RANGE:
    Serial.println("LOW_OUT_OF_RANGE");
    break;
    
  case WAY_TOO_CLOSE:
    Serial.println("WAY_TOO_CLOSE");
    break;
    
  case TOO_CLOSE:
    Serial.println("TOO_CLOSE");
    break;
    
  case OK:
    Serial.println("OK");
    break;
  
  case HIGH_OUT_OF_RANGE:
    Serial.println("HIGH_OUT_OF_RANGE");    break;
    break;
  
  default:
    // Error
    break;
  }
}

void Sensor::PrintDistance()
{
  Serial.print("Sensor ");
  Serial.print(Index());
  Serial.print(": ");
  Serial.print(_distance); 
  Serial.print("cm    ");

  ProcessState();
//  if ((_state == LOW_OUT_OF_RANGE) || (_state == HIGH_OUT_OF_RANGE))
//  {
//    Serial.print(" (Out of range)");
//  }
  
  Serial.println("");
}
