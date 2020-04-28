// This sketch uses Button presses to control a stepper motor.
//Combined projects from the SIK GUIDE and LEARN ARDUINO BASICS books


#include <Stepper.h> //including stepper motor library

//defining pins section

int stepIN1Pin = 8;         
int stepIN2Pin = 9;
int stepIN3Pin = 10;
int stepIN4Pin = 11;
int stepsPerRevolution = 2048; // amount of steps per revolution

const int button1Pin = 2;  // pushbutton 1 pin for clockwise rotation
const int button2Pin = 3;  // pushbutton 2 pin for counter clockwise rotation

Stepper myStepper(stepsPerRevolution, stepIN1Pin, stepIN3Pin, stepIN2Pin, stepIN4Pin);

void setup() {
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
myStepper.setSpeed(15);
}

void loop() {
  // A == B means "EQUIVALENT". This is true if both sides are the same.
  // A && B means "AND". This is true if both sides are true.
  // A || B means "OR". This is true if either side is true.
  // !A means "NOT". This makes anything after it the opposite (true or false).
  
  //This section layouts the button scheme one button is clockwise rotation, the other counter clockwise rotation  
int button1State, button2State;
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
 if (((button1State == LOW) && !(button2State == LOW)))  // if we're pushing button 1 OR button 2
  myStepper.step(stepsPerRevolution/8);
  if (((button2State == LOW) && !(button1State == LOW)))  // if we're pushing button 1 OR button 2
  myStepper.step(-stepsPerRevolution/8);
  }

