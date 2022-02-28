#include <SoftwareSerial.h>
#define Direction 4
#define Intensity_pin 9
#define Speed 5
#define Brake 6      
#define Status 12
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  
  pinMode(Status,OUTPUT);
  pinMode(Speed, OUTPUT);
  pinMode(Intensity_pin, OUTPUT);
  pinMode(Direction, OUTPUT);
  pinMode(Brake, OUTPUT);

  
  digitalWrite(Status,LOW);
  digitalWrite(Brake,HIGH);
  digitalWrite(Direction,HIGH);
  analogWrite(Intensity_pin,125);
  analogWrite(Speed,0);
  
      
}
void loop() 
{
  while (HC12.available())
  {
    digitalWrite(Status,HIGH);
    
    char pot = HC12.read();
    if (pot == 'a') 
    {
      int Intensity = HC12.parseInt();
      analogWrite(Intensity_pin,Intensity);
      //Serial.println(Intensity);
    }
    if (pot == 'b') 
    {
      int speed_val = HC12.parseInt();
      analogWrite(Speed, speed_val);
      //Serial.println(speed_val);
      
    } 
    if (pot == 'c') //Forward
    {
      digitalWrite(Direction,HIGH);
      Serial.println(1);
    } 
    if (pot == 'd') //Reverse
    {
     digitalWrite(Direction,LOW);
     //Serial.println("Reverse");
    } 
    if (pot == 'e') //Brake Hold
    {
     digitalWrite(Brake,HIGH);
    // Serial.println("Brake Hold");
    }
    if (pot == 'f') //Brake Leave
    {
     digitalWrite(Brake,LOW);
    // Serial.println("Brake Leave");
    } 
    if (pot == 'g') //Depth Set
    {
     // Serial.println("Reset");
    }
    if (pot == 'h') //Depth Reset
    {
     // Serial.println("Set");
    } 
       
  }
}
