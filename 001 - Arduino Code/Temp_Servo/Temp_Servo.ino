// Necessary Library 
#include <Wire.h>
#include <Waveshare_LCD1602_RGB.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <DHT.h>
#include <Servo.h>

// Sensors Definition - Arduino Pin
const int PIN_TEMPERATURE = 8;

// Define Temperature Sensor
#define DHTTYPE DHT11
DHT dht(PIN_TEMPERATURE,DHTTYPE);
char temp_str;

// Define Servo Motor - Create Servo Object
const int PIN_SERVO = 5;
Servo myservo;
int servoPos, moveTime;

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

    // Start Temperature Sensor
    dht.begin();
    
    // Define Servo Pin
    myservo.attach(PIN_SERVO);

    // Serial Start
    Serial.begin (9600);
    delay(1000);
}

void loop(){
    //Read Sensors Values
    float tempValue = dht.readTemperature();
    float humdValue = dht.readHumidity();

    Serial.println("Temperature");
    Serial.println(tempValue);
    Serial.println("Humidity");
    Serial.println(humdValue);
    
    // Print Value LCD Display
    lcd.clear();

    // Temperature Value
    lcd.setCursor(0,0);
    lcd.send_string("Temperature ");
    //Convert float value into string - Send to LCD Screen
    dtostrf(tempValue,2,1,buffer);
    lcd.send_string(buffer);

    // Humidity Value
    lcd.setCursor(0,1);
    lcd.send_string("Humidity ");
    //Convert float value into string - Send to LCD Screen
    dtostrf(humdValue,2,1,buffer);
    lcd.send_string(buffer);

    for (servoPos = 0; servoPos <= 180; servoPos += 1){
      moveTime = (100-abs(tempValue)*2)/3;
      moveTime = map(moveTime,0,100,0,1000);
      myservo.write(servoPos);
      delay(moveTime);
      }
      for (servoPos=180; servoPos>=0; servoPos -= 1){
        moveTime = (100-abs(humdValue))/2;
        moveTime = map(moveTime,0,100,0,1000);
        myservo.write(servoPos);
        delay(moveTime);
        }
        
    delay(5000); // Wait 10 seconds before a new reading. 
  }
