// LED
int LED1 = 6; // Pin for LED
int motionSensor = 3; // Pin for Motion Sensor
int LEDState = 0; // Set LED1 LOW

// Button 
int LED2 = 11; // Pin for LED
int button = 2; // Pin for Button
int LEDState2 = 0; // Set LED2 LOW

void setup()
{
  // Motion Sensor 
  pinMode(LED1, OUTPUT); // Set LED1 as an Output
  pinMode(motionSensor, INPUT); // Set Motion Sensors as Input
  
  //Button 
  pinMode(button, INPUT); // Set Button as an Input
  pinMode(LED2, OUTPUT);// Set LED2 as an Output
  Serial.begin(9600);// Initialize serial
  
  // Attach Interrupt to motionSensorTrigger Function
  attachInterrupt(digitalPinToInterrupt(motionSensor), motionSensorTrigger, CHANGE);
  
  // Attach Interrupt to buttonTrigger Function
  attachInterrupt(digitalPinToInterrupt(button), buttonTrigger, CHANGE);
  
}

void loop(){}
// Change State of LED when Motion changes  
void motionSensorTrigger()
{
	LEDState = !LEDState;
    digitalWrite(LED1,LEDState); 
  
    int motionSensorState = digitalRead(motionSensor);
    Serial.print("Motion: ");
    Serial.println(motionSensorState);
  
    Serial.print("LED: ");
    Serial.println(LEDState);
}

// Change State of LED when Button Press  
void buttonTrigger()
{
  LEDState2 = !LEDState2;
  digitalWrite(LED2,LEDState2); 
  
  int buttonState = digitalRead(button);
  Serial.print("Button State: ");
  Serial.println(buttonState);    
  
  Serial.print("LED2: ");   
  Serial.println(LEDState2);
}
