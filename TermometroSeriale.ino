#include <RCSwitch.h> 

RCSwitch mySwitch = RCSwitch();
 
 const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
 
 int sensorValue = 0;        // value read from the pot
float outputValue = 0;        // value output to the PWM (analog out)
int quantum = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  mySwitch.enableTransmit(10);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  sensorValue = analogRead(analogInPin);
  //Serial.println(sensorValue);
  //outputValue=(((sensorValue/1024)*5000)/10)-273.15;  
  outputValue=(((sensorValue-15)*0.005)/0.01)-273;
  mySwitch.send(sensorValue, 24);
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(60000);
  
  Serial.println(outputValue);
}
