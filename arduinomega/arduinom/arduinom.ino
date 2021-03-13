#include <Wire.h>
char buff[]="hello nodemcu";
char h[7];
const int sensor=A1; 
int tempc;   
float vout;

const int trigPin = 9;
const int echoPin = 10;
int sensorValue1;
long duration;
int distance, i;
 int metal;
void setup() {
  pinMode(sensor,INPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  
  pinMode(50, OUTPUT);
  
  pinMode(51, OUTPUT);

  pinMode(52, OUTPUT); 
 
 pinMode(53, OUTPUT); 
  
 Wire.begin(8);               
 Wire.onReceive(receiveEvent); 
 Wire.onRequest(requestEvent); 
 Serial.begin(9600); 

 delay(5000);

 digitalWrite(50, HIGH);
 digitalWrite(51, LOW);
 digitalWrite(52, HIGH);
 digitalWrite(53, LOW);
}

void loop() {
  
  //temp sensor
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; 
h[0]=tempc;

 delay(100);

// gas sensor
sensorValue1 = analogRead(A0);
h[1]=sensorValue1/10;

  // ultra sonic sensor

  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
 h[2]=distance;
// Prints the distance on the Serial Monitor

if(distance<5)
{
  delay(50);
digitalWrite(50, LOW);
 digitalWrite(51, LOW);
 digitalWrite(52, LOW);
 digitalWrite(53, LOW);  
}
else
{
   delay(50);
 digitalWrite(50, HIGH);
 digitalWrite(51, LOW);
 digitalWrite(52, HIGH);
 digitalWrite(53, LOW); 
}
  
  // metal detector:
  metal = analogRead(A2);
  h[3]=metal/10;
  h[4]='\0';
  Serial.println(h);
  
 delay(100);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    Serial.print(c);           /* print the character */
  }
 Serial.println();             /* to newline */
}

// function that executes whenever data is requested from master
void requestEvent() {
 Wire.write(h);  /*send string on request */
 
}
