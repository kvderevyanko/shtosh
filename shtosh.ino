#include "input.h"
#include "output.h"



void setup() {
  startInput(); //Подключаем приёмник
  setupOut();

  Serial.begin(115200);

}


void loop() {
  readPins();

  ch1Speed = abs(ch1Speed);
  turnLeftServo(ch1Speed);


  /**
  Serial.print("ch1Speed: ");
  Serial.print(ch1Speed);
  Serial.print(" | ch2Turn: ");
  Serial.print(ch2Turn);
  Serial.print(" | ch3Lamp: ");
  Serial.print(ch3Lamp);
  Serial.println("");
**/
  //delay(5);
}
