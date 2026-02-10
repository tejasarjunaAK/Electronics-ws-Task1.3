#include <LiquidCrystal.h>
int laser =12;
int buzzer=4;

LiquidCrystal lcd(2,3,6,7,8,9);
void setup(){
 pinMode(buzzer,OUTPUT);
 pinMode(laser,OUTPUT);
 
 lcd.begin(16,2);
 lcd.clear();
}
void loop(){
 lcd.clear();
 digitalWrite(laser,HIGH);
 int val=analogRead(A0);
 if (val>100){
  noTone(buzzer);
  lcd.setCursor(0,0);
  lcd.print("No ");
  lcd.setCursor(0,1);
  lcd.print("Interference");
  }
 else{
  tone(buzzer,1000);
  lcd.setCursor(0,0);
  lcd.print("Interference");
  lcd.setCursor(0,1);
  lcd.print("there");}
 delay(100);
}
