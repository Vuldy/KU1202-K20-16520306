#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
const int pingPin = A1;
long duration, cm;

void setup()
{
  lcd.begin(16,2);
  lcd.print("PING Sensor");
}

void loop()
{
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  
  lcd.setCursor(0,1);
  lcd.print("Jarak");
  lcd.setCursor(6,1);
  lcd.print(cm);
  lcd.print("cm ");
}
long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;
}