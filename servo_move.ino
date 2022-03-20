#include<Wire.h>
#include<Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define ServoMin 150
#define ServoMax 510

int flag = 0;

void servowrite(int servonum, int angle){
  int tick = map(angle,0,180,ServoMin,ServoMax);
  pwm.setPWM(servonum,0,tick);
}

void zeroset(){
  for (int i=0;i<6;i++){
    servowrite(2*i,90);

    delay(100);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  delay(100);
  
  zeroset();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i=0; i<4; i++){
   servowrite(0,90-15*i);
   delay(100);
   if(i<3){
    servowrite(10,90-10*i);
    delay(100); 
   }
  }
  if (flag=0){
    for (int i=0; i<4; i++){
      servowrite(4,90+5*i);
      servowrite(2,90+5*i);
      servowrite(6,90+5*i);
      servowrite(8,90+5*i);
      delay(100);
    }
  }

  else{
    for (int i=0; i<7; i++){
      servowrite(4,75+5*i);
      servowrite(2,75+5*i);
      servowrite(6,75+5*i);
      servowrite(8,75+5*i);
      delay(100);
    } 
  }
  for (int i=0; i<4; i++){
     servowrite(0,45+15*i);
     delay(100);
     if(i<3){
      servowrite(10,70+10*i);
      delay(100);
     }
  }
  for (int i=0; i<4; i++){
    servowrite(10,90+15*i);
     delay(100);
     if(i<3){
      servowrite(0,90+10*i);
      delay(100);
     }
  }
  for (int i=0; i<7; i++){
      servowrite(4,105-5*i);
      servowrite(2,105-5*i);
      servowrite(6,105-5*i);
      servowrite(8,105-5*i);
      delay(100);
    }
  for (int i=0; i<4; i++){
    servowrite(10,135-15*i);
     delay(100);
     if(i<3){
      servowrite(0,110-10*i);
      delay(100);
     }
  }
  flag++;
}
