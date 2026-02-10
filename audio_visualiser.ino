#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
int start=60;
int width=8;
int height=8;
int top=28;
int minHeight=8;
int maxHeight=40;
Adafruit_SSD1306 oled(128,64,&Wire,-1);

void setup(){
 oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
 oled.clearDisplay();
 Serial.begin(9600);
 }
void loop(){
 int val=analogRead(A1);
 val=abs(val-512);
 val=map(val,0,300,minHeight,maxHeight);
 val=constrain(val,minHeight,maxHeight);
 oled.clearDisplay();
 Serial.println(val);
 
 
 oled.fillRect(start,top-val+minHeight,width,val,WHITE);
 oled.display();
 delay(150);}
 
 
   

