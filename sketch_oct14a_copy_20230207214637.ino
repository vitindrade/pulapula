#include "Ultrasonic.h"

#define pin_rele1 10
#define pin_rele2 11

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic(8, 7);
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(pin_rele1, OUTPUT);
  pinMode(pin_rele2, OUTPUT);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(250);

  if (distance <= 356){
    digitalWrite(pin_rele1, HIGH);
    Serial.println("Caixa de SOM_1");
    digitalWrite(pin_rele2, HIGH);
    Serial.println("Caixa de SOM_2");
    delay(500);
  } else{
    digitalWrite(pin_rele1, LOW);
    digitalWrite(pin_rele2, LOW);
  }
}