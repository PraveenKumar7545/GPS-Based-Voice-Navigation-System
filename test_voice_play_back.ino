#include <Wire.h>
// setup u8g object

//
const int trigPin = 8;
const int echoPin = 7;
long duration, inches, cm, avgCm;
String longString = "";
int tapeLength = 0;
 
int voice1 = 2;
int voice2 = 3;
int voice3 = 4;
int voice4 = 5;
 
void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(voice1, OUTPUT);
  pinMode(voice2, OUTPUT);
  pinMode(voice3, OUTPUT);
  pinMode(voice4, OUTPUT);
}
 
void loop()
{
  avgCm = 0;
  for (int f = 0; f < 5; f++)
  { // average out 5 readings
    ultrasonic();
    avgCm = avgCm + cm;
  }
  cm = avgCm / 5;
  //draw loop

  do
  {
    draw();
  }


  
  if (cm <= 5)
  {
    digitalWrite(voice1, LOW);
  }
  else
  {
    digitalWrite(voice1, HIGH);
  }
 
  
 
  if ((cm > 5) && (cm <= 10))
  {
    digitalWrite(voice2, LOW);
  }
  else
  {
    digitalWrite(voice2, HIGH);
  }
 
  
 
  if ((cm > 10) && (cm <= 15))
  {
    digitalWrite(voice3, LOW);
  }
  else
  {
    digitalWrite(voice3, HIGH);
  }
 
  
 
  if ((cm > 15) && (cm <= 20))
  {
    digitalWrite(voice4, LOW);
  }
  else
  {
    digitalWrite(voice4, HIGH);
  }
  
}
 
void ultrasonic()
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}
long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
void draw(void) {


  if (cm > 110) {
    longString = "---";
    tapeLength = 0;
  }
  else {
    longString = String(cm) + "cm";
    tapeLength = cm;
  }
  const char* newData = (const char*) longString.c_str();


  for (int f = 10; f < 120; f = f + 10) {

  }
  for (int f = 2; f < tapeLength + 3; f++) {
  }
}
