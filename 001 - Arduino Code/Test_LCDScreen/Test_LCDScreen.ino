// Necessary Library 
#include <Wire.h>
#include <Waveshare_LCD1602_RGB.h>

// Sensors Definition - Arduino Pin
#define PIN_MOISTURE A1

// Define LEDs
const int PIN_LED1 = 2;
const int PIN_LED2 = 3;
const int PIN_LED3 = 4;

// Define the LCD Screen
Waveshare_LCD1602_RGB lcd(16,2);  //16 characters and 2 lines
int r,g,b,t=0; 

void setup(){
    // SetUp the LCD screen 
    lcd.init();

    lcd.setCursor(0,0);
    lcd.send_string("Hello World!");
    lcd.setCursor(0,1);
    lcd.send_string("Nature & Electr.");
}

void loop(){
    r = (abs(sin(3.14*t/180)))*255;
    g = (abs(sin(3.14*(t + 60)/180)))*255;
    b = (abs(sin(3.14*(t + 120)/180)))*255;
    t = t + 3;
    lcd.setRGB(r,g,b);
    delay(150);
}
