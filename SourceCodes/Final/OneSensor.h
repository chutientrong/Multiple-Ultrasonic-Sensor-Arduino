#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

class Sensor
{
  public:
    enum EState 
    {
      LOW_OUT_OF_RANGE, 
      WAY_TOO_CLOSE,
      TOO_CLOSE, 
      OK, 
      HIGH_OUT_OF_RANGE
    };
    
    Sensor(uint8_t index, uint8_t trigPin, uint8_t echoPin);

    uint8_t Index    (void) { return _index;     };
    uint8_t TrigPin  (void) { return _trigPin;   };
    uint8_t EchoPin  (void) { return _echoPin;   };
     
    void Init();
    void Process();

  private:
    uint8_t _index;
    uint8_t _trigPin;
    uint8_t _echoPin;
    EState _state;
    uint8_t _distance;
    
    void Measure();
    void UpdateState();
    void ProcessState();
    void PrintDistance(void);
};

#endif // SENSOR_H
