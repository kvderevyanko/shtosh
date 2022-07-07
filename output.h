 #include <ESP32Servo.h>

#define LS 15 //левый сервомотор
#define RS 2 //правый сервомотор

#define RS_DEFAULT 0 //правый сервомотор по умолчанию
#define LS_DEFAULT 0 //левый сервомотор по умолчанию

#define STEP 8 //Количество шагов для сервомотора



int leftServoVal; //Значение правого сервомотора
int rightServoVal; //Значение левого сервомотора

Servo leftServo; 
Servo rightServo; 




void setupOut() {

  leftServoVal = LS_DEFAULT;
  rightServoVal = RS_DEFAULT;
  
  leftServo.attach(LS); 
  leftServo.write(leftServoVal); 

  rightServo.attach(RS); 
  rightServo.write(rightServoVal); 
}

//Поворот левого сервомотора
void turnLeftServo(int pos){

  if(leftServoVal + STEP > pos && leftServoVal - STEP < pos) {
    leftServoVal = pos; 
  }
  else if(pos > leftServoVal) {
    leftServoVal = leftServoVal + STEP;  
  }  else if (pos < leftServoVal) {
    leftServoVal = leftServoVal - STEP;  
  }
  leftServo.write(leftServoVal); 
}



//Поворот правого сервомотора
void turnRightServo(int pos){
  if(pos > rightServoVal) {
    rightServoVal = rightServoVal + STEP;  
  } else if (pos < rightServoVal) {
    rightServoVal = rightServoVal - STEP;
  }
  
  rightServo.write(rightServoVal); 
}
