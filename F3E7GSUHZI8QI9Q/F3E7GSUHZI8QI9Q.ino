// autonomous car
// Created by Jesper Birk - 2014

int motorPin1 =  8;    // motor wire connected to digital pin 5
int motorPin2 =  9;    // motor wire connected to digital pin 6
int motorPin3 =  10;    // steering motor wire connected to digital pin 7
int motorPin4 =  11;    // steering motor wire connected to digital pin 8

int steeringMotorSpeed = 150;  // Set default power to send to steering motor


int avoidDistance = 80cm;
int endAvoidDistance = 100;

int goToReverseDistance = 55;
int reverseTime = 2000;

 int fullTrottleMinDistance = 250;


int fullTrottleSpeed = 220;
int cruiseSpeed = 160;
int avoidSpeed = 120;
int reverseSpeed = 130;

int sensorDelay = 100;  //  

long randNumber;
int avoidDirection = 1;
int avoidCirclesBeforeDirectionChange = 10;
int countDown = 1;
int distanceCountDown = 1;

#include "Ultrasonic.h"
Ultrasonic ultrasonic(12,13);

int distance = (ultrasonic.Ranging(CM));

// The setup() method runs once, when the sketch starts

void setup()   {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  randomSeed(analogRead(0));
  
  // initialize the digital pins as an output:
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT);  
  pinMode(motorPin3, OUTPUT); 
  pinMode(motorPin4, OUTPUT);  
}

////////////   LOOP    ////////////

void loop()                     
{
   // Serial.println("start loop  ");
    
   // Serial.println(ultrasonic.Ranging(CM));

//choseMode();



distance = (ultrasonic.Ranging(CM));

////////////   REVERSE MODE    ////////////
  if(distance <= goToReverseDistance){
    avoidDirection = avoidDirection * -1;
    
//   while(distance < avoidDistance) {
    // Serial.println("start reverse  ");
      if(avoidDirection == 1){                      // turn one way
        analogWrite(motorPin3, steeringMotorSpeed);
        digitalWrite(motorPin4, LOW);  
      } else {                                      // ... or the other way
        analogWrite(motorPin4, steeringMotorSpeed); 
        digitalWrite(motorPin3, LOW); 
      }
    analogWrite(motorPin2, reverseSpeed);            //rotates motor - backwards
    digitalWrite(motorPin1, LOW); 
    delay(reverseTime);                              // for time set in reverseTime
 //   delay(sensorDelay);
    distance = (ultrasonic.Ranging(CM));
 //   }

 
    digitalWrite(motorPin2, LOW);                    // stop motors
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    
 
    avoidDirection = avoidDirection * -1;             // switch steering direction
                               
    distance = (ultrasonic.Ranging(CM));
  }
////////////////////////////////////////////////

////////////   AVOID MODE    ////////////

        distance = (ultrasonic.Ranging(CM));
        
  if(distance < avoidDistance){
  // Serial.println("start avoid  ");

    distance = (ultrasonic.Ranging(CM));
    countDown = avoidCirclesBeforeDirectionChange;
    distanceCountDown = distance;
    
  while(distance <= endAvoidDistance && distance > goToReverseDistance){
        if(avoidDirection == 1){
            analogWrite(motorPin3, steeringMotorSpeed); // turn one way
            digitalWrite(motorPin4, LOW);
        } else {
            analogWrite(motorPin4, steeringMotorSpeed); // or turn the other way
            digitalWrite(motorPin3, LOW);
        }
        
        analogWrite(motorPin1, avoidSpeed); //rotates motor
        digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW    
        delay(sensorDelay);
        distance = (ultrasonic.Ranging(CM));
          if(distance < distanceCountDown) { countDown--; }           // if obstacle is getting closer - count down to changing direction
          if(countDown < 1) {
              avoidDirection = avoidDirection * -1;   // switch steering direction
              countDown = avoidCirclesBeforeDirectionChange;
              distanceCountDown = distance;  
          }
    // Serial.println(distance);  
    // Serial.println(avoidDirection);  
    }   // end while (avoid) 
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
////////////////////////////////

////////////   CRUISE MODE    ////////////
        distance = (ultrasonic.Ranging(CM));
        
    while(distance > avoidDistance  && distance < fullTrottleMinDistance){
        analogWrite(motorPin1, cruiseSpeed); //rotates motor 
        digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW    
        delay(sensorDelay);   
        distance = (ultrasonic.Ranging(CM));
    // Serial.println("cruise");
    // Serial.println(distance);  
    }   // end while
    
    
////////////   FULL SPEED MODE    ////////////
        distance = (ultrasonic.Ranging(CM));
        
    while(distance > fullTrottleMinDistance){
        analogWrite(motorPin1, fullTrottleSpeed); //rotates motor 
        digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW    
        delay(sensorDelay);   
        distance = (ultrasonic.Ranging(CM));
              // Serial.println("FULL");
              // Serial.println(distance);  
    }   // end while

      // Serial.println("REstart loop  ");
    
   // Serial.println(distance);
  

}



