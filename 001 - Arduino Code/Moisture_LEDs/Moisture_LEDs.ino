// Necessary Library 
#include <Wire.h>
#include <Waveshare_LCD1602_RGB.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sensors Definition - Arduino Pin
const int PIN_MOISTURE = A1;

// Define LEDs
const int PIN_LED1 = 2;
const int PIN_LED2 = 3;
const int PIN_LED3 = 4;

// Define Sensors Value
// int moistureValue = 0;
char moist_str;

// Define the LCD Screen
Waveshare_LCD1602_RGB lcd(16,2);  //16 characters and 2 lines
int r,g,b = 0; 
char buffer [5]; // Value between 0-1023

void setup(){
    // SetUp the LCD screen 
    lcd.init();
    lcd.setCursor(0,0);
    lcd.send_string("Hello World!");
    lcd.setCursor(0,1);
    lcd.send_string("Let's Measure Nature");
    lcd.setRGB(255,100,70); //Define the color of the screen

    // SetUp the LED 
    pinMode(PIN_LED1,OUTPUT);
    pinMode(PIN_LED2,OUTPUT);
    pinMode(PIN_LED3,OUTPUT);

    // Serial Start
    Serial.begin (9600);
    delay(1000);
}

void loop(){
  
    //Read Sensors Values
    int moistureValue = analogRead(PIN_MOISTURE);

    // Print Value LCD Display
    lcd.clear();
    lcd.send_string("Soil Moisture:");
    lcd.setCursor(0,1);
    
    //Convert int value into string - itoa()
    scanf ("&d",&moistureValue);
    itoa(moistureValue, buffer, 10);
    // Send the value to the LCD Screen.
    lcd.send_string(buffer);
    
    // Change LEDs Colors regarding to Moisture Value
    if (moistureValue < 400){
      // Add a note and sent it to the LCD Screen
      char moist_str[]=" Very Wet!";
      lcd.send_string(moist_str);
      // Set the LEDs color
      digitalWrite(PIN_LED1,LOW);
      digitalWrite(PIN_LED2,HIGH);
      digitalWrite(PIN_LED3,HIGH);    
      } 
        else if ((moistureValue > 400) && (moistureValue < 800)){
        // Add a note and sent it to the LCD Screen
        char moist_str[]=" Moist! Avg.";
        lcd.send_string(moist_str);
        // Set the LEDs color
        digitalWrite(PIN_LED1,HIGH);
        digitalWrite(PIN_LED2,LOW);
        digitalWrite(PIN_LED3,HIGH);
        } 
          else {
          // Add a note and sent it to the LCD Screen
          char moist_str[]=" Dry. Water!!";
          lcd.send_string(moist_str);
          // Set the LEDs color
          digitalWrite(PIN_LED1,HIGH);
          digitalWrite(PIN_LED2,HIGH);
          digitalWrite(PIN_LED3,LOW);
          }
    //Measure the value every 10sec.
    delay(10000); 
}
