#include <NewPing.h>

// trigger and echo pins for each sensor
//#define trigPin1 30
//#define echoPin1 31
//#define trigPin2 32
//#define echoPin2 33
//#define trigPin3 34
//#define echoPin3 35

#define MAX_DISTANCE 500 // maximum distance for sensors
#define NUM_SONAR 15 // number of sonar sensors

NewPing sonar[NUM_SONAR] = { // array of sonar sensor objects
  NewPing(30, 31, MAX_DISTANCE),
  NewPing(32, 33, MAX_DISTANCE),
  NewPing(34, 35, MAX_DISTANCE),
  NewPing(36, 37, MAX_DISTANCE),
  NewPing(38, 39, MAX_DISTANCE),
  NewPing(40, 41, MAX_DISTANCE),
  NewPing(3, 2, MAX_DISTANCE),
  NewPing(5, 4, MAX_DISTANCE),
  NewPing(7, 6, MAX_DISTANCE),
  NewPing(9, 8, MAX_DISTANCE),
  NewPing(11, 10, MAX_DISTANCE),
  NewPing(22, 23, MAX_DISTANCE),
  NewPing(24, 25, MAX_DISTANCE),
  NewPing(26, 27, MAX_DISTANCE),
  NewPing(28, 29, MAX_DISTANCE),
};

int distance[NUM_SONAR]; // array stores distances for each
                         // sensor in cm

void setup() {
  Serial.begin(9600);
}

void loop() {
//  delay(100);
  updateSonar(); // update the distance array
  // print all distances
  printSS();
  Serial.println("------------- ");

}

// takes a new reading from each sensor and updates the
// distance array
void updateSonar() {
  for (int i = 0; i < NUM_SONAR; i++) {
    distance[i] = sonar[i].ping_cm(); // update distance
    // sonar sensors return 0 if no obstacle is detected
    // change distance to max value if no obstacle is detected
    if (distance[i] == 0)
      distance[i] = MAX_DISTANCE;
  }
}
void printSS() {                                                         // Sensor ping cycle complete, do something with the results.
  // The following code would be replaced with your code that does something with the ping results.
  for (uint8_t i = 0; i < NUM_SONAR; i++) {
    if(distance[i]>MAX_DISTANCE){
      Serial.print("Out of range!!!");
    }else{
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(" = ");
    Serial.print(distance[i]);
    Serial.print(" cm ");
    Serial.println();
    }
  }
//  Serial.println();
  delay(50);
} 
