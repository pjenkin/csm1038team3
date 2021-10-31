
//  Example code to control the robot with functions
//  By Ryan Hughes 2019

// ----------------------------------------------------------------------------------------------------------- //

//  This example covers:
//    > Writing functions
//    > Calling functions

// ----------------------------------------------------------------------------------------------------------- //

//Define I/O pins (input/output)
#define motorRight 6                         //  As with the previous example, definitions are set to clear up 
#define motorLeft 5                         //  the main body of the code.

#define directionRightLow   7
#define directionRightHigh  8
#define directionLeftLow    9
#define directionLeftHigh   10

//---------------------------------------------------------------------------
// Function: setup
// ----------------------------
//   Allocates pin modes and begins serial communications
//
//   no parameters passed in
//
//   returns: none
//---------------------------------------------------------------------------

void setup() {                               // The setup routine beigns (running only once).

  pinMode(motorRight, OUTPUT);
  pinMode(motorLeft, OUTPUT);                // The previously defined pins are then set to OUTPUTs to control the speed.
  pinMode(directionRightHigh, OUTPUT);
  pinMode(directionRightLow, OUTPUT);
  pinMode(directionLeftHigh, OUTPUT);
  pinMode(directionLeftLow, OUTPUT);         // And to control the direction.

  Serial.begin(9600);                        // The Serial communication line is initiated to help check for issues or "debug"


}                                            // End of the setup routine.


//---------------------------------------------------------------------------
// Function: loop
// ----------------------------
//   Moves the robot forwards, then left and then right, with 1 second intervals
//
//   no parameters passed in
//
//   returns: none
//---------------------------------------------------------------------------
void loop() {                                // The loop routine beigns (running over and over, continuously).

  moveForward();                             // Here, we are calling the "moveForward function". This tells the Arduino to
                                             // run a set of code that is written below. 
                                             
  delay(1000);                               // "delay" is another example of a function, however this is included
                                             // in the Arduino system, so it knows what to do already.
                                             
  moveLeft();                                // The brackets in "moveLeft()" are empty because the function does not require
                                             // any inputs, whereas "delay(1000)" needs to know the length of the delay
  delay(1000);
  moveRight();                               // This will run the "moveRight" function, shown below.
  delay(1000);

}                                            // End of the loop routine.


//---------------------------------------------------------------------------
// Function: moveForward
// ----------------------------
//   Moves the robot forward
//
//   no parameters passed in
//
//   returns: none
//---------------------------------------------------------------------------
void moveForward(){                          // This is the start of the "moveForward" function.
                                             // This function is a "void" as it does not return a value to the loop routine.

  Serial.println("Forward");                 // This will tell you that the "moveForward" funtion is being called
                                             // in the serial monitor (Tools > Serial monitor).

  digitalWrite(directionRightHigh, HIGH);    
  digitalWrite(directionRightLow, LOW);      // This tells the motors to go forward.
  analogWrite(motorRight, 200);              // This sets the speed.

  digitalWrite(directionLeftHigh, HIGH);
  digitalWrite(directionLeftLow, LOW);
  analogWrite(motorLeft, 200);               // (Q1) Roughly what voltage will this line output, and to what pin number?
  
}


//---------------------------------------------------------------------------
// Function: moveLeft
// ----------------------------
//   Moves the robot to bear left
//
//   no parameters passed in
//
//   returns: none
//---------------------------------------------------------------------------
void moveLeft(){

  Serial.println("Left");                    // This will tell you that the "moveLeft" funtion is being called.

  digitalWrite(directionRightHigh, HIGH);    // (Q2) What voltage is outputted to both the directionRightHigh and 
  digitalWrite(directionRightLow, LOW);      //      directionRightLow pins? What number are these pins?
  analogWrite(motorRight, 200);

  digitalWrite(directionLeftHigh, HIGH);     // Sets the left motor direction.
  digitalWrite(directionLeftLow, LOW);
  analogWrite(motorLeft, 100);                // Sets the left motor speed.
  
}


//---------------------------------------------------------------------------
// Function: moveRight
// ----------------------------
//   Makes the robot bear right
//
//   no parameters passed in
//
//   returns: none
//---------------------------------------------------------------------------
void moveRight(){

  Serial.println("Right");                   // Prints "Right" to the serial monitor

  digitalWrite(directionRightHigh, HIGH);
  digitalWrite(directionRightLow, LOW);      // (Q3) How would you reverse the motors directions?
  analogWrite(motorRight, 100);               // Sets right motor speed.

  digitalWrite(directionLeftHigh, HIGH);
  digitalWrite(directionLeftLow, LOW);       // Sets left motor direction.
  analogWrite(motorLeft, 200);               // Sets left motor speed.
  
}

// CHALLENGE: Create your own functions to move the robot in different ways, e.g. Stop, backwards or rotate.
//            When ending a line of code, remember to use a ";".

// ANSWERS: 
//  Q1 -> 5v * (100/255) = 1.96V, outputted to pin number 10
//  Q2 -> HIGH = 5V, LOW = 0V, directionRightHigh = pin 5, directionRightLow = pin 4
//  Q3 -> Make directionRightHigh = 0V (LOW) and directionRightLow = 5V (HIGH)
