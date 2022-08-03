// C++ code
//

int LED1 = 10; // Pin for LED
int motionSensor = 2; // Pin for Motion Sensor
int LEDState = 0; // State of LED (HIGH / LOW)

void setup()
{
  pinMode(LED1, OUTPUT); // Set LED as an Output
  pinMode(motionSensor, INPUT); // Set Motion Sensors as Input
  Serial.begin(9600);// Initialize serial
  attachInterrupt(digitalPinToInterrupt(motionSensor), motionSensorTrigger, CHANGE);
}

void loop(){}
// Change State of LED when Motion changes  
void motionSensorTrigger()
{
	LEDState = !LEDState;
    digitalWrite(LED1,LEDState); 
    int motionSensorState = digitalRead(motionSensor); // State of Motion Sensor (HIGH / LOW)
    Serial.print("Motion: ");
    Serial.println(motionSensorState);
    Serial.print("LED: ");
    Serial.println(LEDState);
}

  
