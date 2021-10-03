#ifndef SENSORS_H
#define SENSORS_H

#include "Arduino.h"
#include "OneSensor.h"

class Sensors
{
  public:
    Sensors();

    void Init();
    void Process();

  private:
    static const int NR_OF_SENSORS = 15;

    Sensor _sensors[NR_OF_SENSORS];
};

#endif // SENSORS_H
