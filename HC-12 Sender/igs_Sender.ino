#include <SoftwareSerial.h>
bool Forward;
bool Reverse;
bool Brake_Hold;
bool Brake_Release;
bool Depth_Set;
bool Depth_Reset;
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  HC12.begin(9600);
}
void loop()
{
  int Intensity = analogRead(A0);
  int Speed = analogRead(A1);
  Intensity = map(Intensity, 0, 1024, 0, 255);
  Speed = map(Speed, 0, 1024, 0, 255);
  HC12.print("a");
  HC12.print(Intensity);
  Serial.println(Intensity);
  delay(10);
  HC12.print("b");
  HC12.print(Speed);
  Serial.println(Speed);
  delay(10);
  //-------------Pot Finished ----------------------//
  Forward=digitalRead(3);
  Reverse=digitalRead(2);
  Brake_Hold=digitalRead(5);
  Brake_Release=digitalRead(4); 
  Depth_Set=digitalRead(6);
  Depth_Reset=digitalRead(7);
  
  if ( Forward== HIGH)//Forward
  {
    Reverse=LOW;
    HC12.print("c");    
  }
  if (Reverse== HIGH)//Reverse
  {
    Forward=LOW;
    HC12.print("d");
  }
  if (Brake_Hold == HIGH)//Brake HOLD
  {
    Brake_Release=LOW;
    HC12.print("e");
  }
  if (Brake_Release== HIGH)//Brake Release
  {
    Brake_Hold=LOW;
    HC12.print("f");
  } 
  if ( Depth_Reset== HIGH)//Depth Reset
  {
    HC12.print("g");
  }
  if (Depth_Set == HIGH)//Depth Set
  {
    HC12.print("h");
  }


}
