#include "Sensors.h"

Sensors::Sensors()
:
  //              index trigPin echoPin )
  _sensors( { Sensor(1 ,  30   ,  31   ),
              Sensor(2 ,  32   ,  33   ),
              Sensor(3 ,  34   ,  35  ),
              Sensor(4 ,  36   ,  37   ),
              Sensor(5 ,  38   ,  39   ),
              Sensor(6 ,  40   ,  41  ),
              Sensor(7 ,  3   ,  2   ),
              Sensor(8 ,  5   ,  4   ),
              Sensor(9 ,  7   ,  6  ),
              Sensor(10 ,  9   ,  8   ),
              Sensor(11 ,  11   ,  10   ),
              Sensor(12 ,  22   ,  23  ),
              Sensor(13 ,  24   ,  25   ),
              Sensor(14 ,  26   ,  27   ),
              Sensor(15 ,  28   ,  29  ),
              })

{
}

void Sensors::Init()
{
  for (uint8_t index = 0; index < NR_OF_SENSORS; index++)
  {
    _sensors[index].Init();
  }
}


void Sensors::Process()
{
  for (uint8_t index = 0; index < NR_OF_SENSORS; index++)
  {
    _sensors[index].Process();
  }
}
