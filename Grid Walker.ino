#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<Wire.h>
Adafruit_SSD1306 oled(128,64,&Wire,-1);
int left=2;
int right=3;
int up=4;
int down=5;
int start=64;
int top=32;
int width=8;
int height=8;
void setup(){ 
 pinMode(left,INPUT_PULLUP);
 pinMode(right,INPUT_PULLUP);
 pinMode(up,INPUT_PULLUP);
 pinMode(down,INPUT_PULLUP);
 oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
 oled.clearDisplay();
 oled.fillRect(start,top,width,height,WHITE);
 oled.display();
 }
void loop(){
 if(digitalRead(left)==LOW){
   oled.clearDisplay();
   start=(start-8+128)%128;
   oled.fillRect(start,top,width,height,WHITE);}
 else if(digitalRead(right)==LOW){
   oled.clearDisplay();
   start=(start+8)%128;
   oled.fillRect(start,top,width,height,WHITE);}
 else if(digitalRead(up)==LOW){
   oled.clearDisplay();
   top=(top-8+64)%64;
   oled.fillRect(start,top,width,height,WHITE);}
 else if(digitalRead(down)==LOW){
   oled.clearDisplay();
   top=(top+8)%64;
   oled.fillRect(start,top,width,height,WHITE);}
 oled.display();
 delay(150);}
