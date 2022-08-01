
int LED1 = 10; // Pin for LED
int motionSensor = 8; // Pin for Motion Sensor
void setup()
{
  pinMode(LED1, OUTPUT); // Set LED as an Output
  pinMode(motionSensor, INPUT); // Set Motion Sensors as Input
  Serial.begin(9600);// Initialize serial
}

void loop()
{
  // Read the State of the Motion Sensor 
  int currentState = digitalRead(motionSensor); 
  // If Motion is Detected Turn On LED and Print their States
  if(currentState == HIGH) { 
  	digitalWrite(LED1, HIGH); 
    Serial.println("Motion: Detected");
    Serial.println("LED: On");
  }
  // If No Motion is Detected Turn On LED and Print their States
  else {
  	digitalWrite(LED1, LOW);
    Serial.println("Motion: Not Detected");
    Serial.println("LED: Off");
  }
  delay(1000); // Wait for 1 second

}
