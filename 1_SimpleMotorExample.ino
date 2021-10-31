
//  Example code to move and stop the robot
//  By Ryan Hughes 2019

// ----------------------------------------------------------------------------------------------------------- //

//  This example covers:
//    > Definitions
//    > The Setup routine
//    > The Loop routine
//    > Pin modes
//    > The serial monitor
//    > Writing to pins
//    > Delays

// ----------------------------------------------------------------------------------------------------------- //

//  Creating definitions enables the code to be read
//  and written easily. This is achieved by reducing the
//  presence of numbers that may not have an obvious meaning.

#define motorRight 6                       //  For example, when "motorRight" is used in the code,
#define motorLeft  5                       //  the computer will see it as "10"

#define directionRightLow  7               //  This reduces confusion and increases efficiency.
#define directionRightHigh 8               //  In the code, these numbers are later related to pins on
#define directionLeftLow   9               //  the Arduino microcontroller.
#define directionLeftHigh  10              //  When the pin "directionRightLow" is LOW (0V) and pin "directionRightHigh" is
                                           //  HIGH (5V), the right motor will go forward, and vice versa.

//  Next is the "Setup Routine", this is only run once
//  when the system starts. It is used to begin any required
//  procedures and set inital parameters that often do not change. 

//---------------------------------------------------------------------------
// Function: setup
// ----------------------------
//   Sets up the serial monitor and pin modes for use later in the code
//
//   no parameters passed in
//
//   returns: none - function is void
//---------------------------------------------------------------------------

void setup() {  

    // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(motorRight, OUTPUT);              //  "pinMode" sets whether a pin on the Arduino will
  pinMode(motorLeft, OUTPUT);               //  look for an input, or produce an output.
                                            //  Here the pins are outputs, used to control the motors' speeds

  pinMode(directionRightHigh, OUTPUT);      //  The pins to control the motors' directions are also set 
  pinMode(directionRightLow, OUTPUT);       //  as outputs.
  pinMode(directionLeftHigh, OUTPUT);
  pinMode(directionLeftLow, OUTPUT);

  Serial.begin(9600);                       //  "Serial.begin" opens up a stream of data between the Arudino
                                            //  and the computer through the USB cable, providing an insight
                                            //  into what is happening within the code. This data can be seen
                                            //  in the serial monitor (Tools > Serial monitor).
                                            //  9600 is the Baud rate, the speed of communication.

}                                           //  The "}" shows the end of the setup routine.

//  Next is the "Loop Routine", this is run continuously.
//  Operations and decisions are normally in this section.

//---------------------------------------------------------------------------
// Function: loop
// ----------------------------
//   Makes the robot move forward for 1 second and then stop for 1 second
//
//   no parameters passed in
//
//   returns: none - function is void
//---------------------------------------------------------------------------

void loop() {

  digitalWrite(directionRightHigh, HIGH);   //  "digitalWrite" will set the selected output pin to 0V or 5V.
  digitalWrite(directionRightLow, LOW);     //  This code makes the right motor go forward.
  analogWrite(motorRight, 200);             //  "analogWrite" outputs a modulating signal that has an average voltage
                                            //  between 0V (0) and 5V (255). This is fed into the motor driver,
                                            //  controlling the speed of the motor.
                                            //  Here, the pin defined as "motorRight" is set to ouput an average of 3.9V ->
                                            //  [5V * (200/255)] = 3.9V, or 78% speed.

  digitalWrite(directionLeftHigh, HIGH);    //  Here the diection of the left motor is set to forward.
  digitalWrite(directionLeftLow, LOW);
  analogWrite(motorLeft, 200);              //  The pin defined as "motorLeft" set to 3.9V (78%)

  Serial.println("Forward");                //  This will print "Forward" to the serial monitor.

  delay(1000);                              //  The delay function specifies a time in milliseconds to pause for.

  analogWrite(motorRight, 0);               //  After a 1 second delay, the output is set to 0V -> [5V * (0/255)] = 0V,
  analogWrite(motorLeft, 0);                //  therefore the voltage to the motor from the motor driver is also 0v.
                                            //  The direction remains unchanged.

  Serial.println("Stopped");                //  This will print "Stopped" to the serial monitor.

  delay(1000);                              //  Pause for 1000ms


    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

}                                           //  The "}" shows the end of the loop routine, it then starts again.
