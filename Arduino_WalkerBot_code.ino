//Theo Jansen Mecha Walker BrainCode
//Author: Farhan Nur Shabab
//Date started: March 7th 2014

//--------------------------------------------------------------


// Define pin inputs and outputs

// Kill switch
int powerPin = A0;

//Microphone
int microPhon = A2;
int soundlb = 948;
int soundub = 954;
int soundTolerance = 6;

//LED
int LEDpin = 13;

// Motor logic pins for Left Motor
int motorlogicPinL1 = 3; //connect to L293 pin 1A 
int motorlogicPinL2 = 5; //connect to L293 pin 2A 

// Motor logic pins for Right Motor
int motorlogicPinR4 = 6; // 4A
int motorlogicPinR3 = 9; // 3A

// Motor Speed Variable
// Forward: Lf > 0, Lb = 0
//          Rf = 0, Rb > 0
volatile int LforwardVel = 255; // Move forward when started
volatile int LbackwardVel = 0;

volatile int RforwardVel = 0; // Move forward when started
volatile int RbackwardVel = 255;

// Sensor Pins
int IRsensor = 2;

// Sensor Pin Outputs

void setup() { 
  
 // Power
 pinMode (powerPin, INPUT);
 
 //LED
 pinMode(LEDpin, OUTPUT);
 
 // IR Sensors
 pinMode (IRsensor, INPUT); //Ahead sensor output
 
 // Set pins as input or output 
 pinMode(motorlogicPinL1, OUTPUT); 
 pinMode(motorlogicPinL2, OUTPUT); 
 
 pinMode(motorlogicPinR4, OUTPUT); 
 pinMode(motorlogicPinR3, OUTPUT);
 
 // attachInterrupts, used for obstacle avoidance
 attachInterrupt(0,read_AheadSensor,CHANGE); //Front Sensor, Pin 2
 
//Use serial monitor for debugging in IDE; this code is optional
 Serial.begin (9600);
 
} 
 
 
void loop() { 
 
 //----------------------Monitor Sensor Function-------------------------
 
 Serial.print ("IRSensor: ");
 int AheadSense = digitalRead(IRsensor);
 Serial.println (AheadSense); //print the sensor output
 delay (250); //wait half a second
 
 Serial.print ("Sound: ");
 Serial.println (digitalRead(microPhon)); //print the sensor output
 delay (250); //wait half a second
 
 
 //----------------------------------------------------------------------
 
 int powerVal = analogRead(powerPin);
 
 //if power is switch is turned on
 if (powerVal >= 1010)
 {
 
 // Walk straight

 // Control speed of L motor with analogWrite 
 analogWrite(motorlogicPinL1, LforwardVel); 
 analogWrite(motorlogicPinL2, LbackwardVel); 
 
 // Control speed of R motor with analogWrite 
 analogWrite(motorlogicPinR3, RforwardVel); 
 analogWrite(motorlogicPinR4, RbackwardVel); 
 
 
 Serial.print ("Microphone: ");
 int sound = analogRead(microPhon);
 Serial.println (sound); //print the sensor output
 delay (250); //wait half a second
 
 // IR sensor detects no obstacle
 if (digitalRead(IRsensor)==1)
 {
 

 // if sound received by microphone is within a set threshold
 if ((analogRead(microPhon)<= soundlb-soundTolerance) ||(analogRead(microPhon)>= soundub+soundTolerance))

 // execute a preset list of movements
 { 
   digitalWrite(LEDpin, HIGH);
   
   analogWrite(motorlogicPinL1, 0); 
   analogWrite(motorlogicPinL2, 200); 
  
   analogWrite(motorlogicPinR3, 200); 
   analogWrite(motorlogicPinR4, 0); 
   
   delay(2000);
   
   analogWrite(motorlogicPinL1, 0); 
   analogWrite(motorlogicPinL2, 255); 
  
   analogWrite(motorlogicPinR3, 0); 
   analogWrite(motorlogicPinR4, 255); 
   
   delay(2000);
   
   analogWrite(motorlogicPinL1, 255); 
   analogWrite(motorlogicPinL2, 0); 
  
   analogWrite(motorlogicPinR3, 255); 
   analogWrite(motorlogicPinR4, 0); 
   
   delay(2000);
   
 }
   
 } 
 
 if (powerVal < 1010)
 {
   // Control speed of L motor with analogWrite 
 analogWrite(motorlogicPinL1, 0); 
 analogWrite(motorlogicPinL2, 0); 
 
 // Control speed of R motor with analogWrite 
 analogWrite(motorlogicPinR3, 0); 
 analogWrite(motorlogicPinR4, 0); 
   
 }
}
}


void read_AheadSensor()
{
  if (digitalRead(IRsensor)==0) {
    
    if (analogRead(powerPin) >= 1010) {
      
      while (digitalRead(IRsensor)==0)
      {
        // Turn right
        // Motor Speed Variable
        // Forward: Lf > 0, Lb = 0
        //          Rf = 0, Rb > 0
        analogWrite(motorlogicPinL1, LforwardVel); 
        analogWrite(motorlogicPinL2, LbackwardVel); 
        analogWrite(motorlogicPinR3, 255); 
        analogWrite(motorlogicPinR4, 0); 
      }
    }
  }
}
