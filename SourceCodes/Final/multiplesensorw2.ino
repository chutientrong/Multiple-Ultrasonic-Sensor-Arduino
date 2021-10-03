#include "Sensors.h"

Sensors _sensors;

void setup() {
  Serial.begin (9600);
  _sensors.Init();  
}


void loop()
{
  _sensors.Process();
}
