// Necessary Library 
#include <Wire.h>
#include <Waveshare_LCD1602_RGB.h>

// Library for Temperature & Servo Motor
#include <DHT.h>
#include <Servo.h>

// Pre-defined Tone and Songs
#include "pitches.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sensors Definition - Arduino Pin
// Moisture 
const int PIN_MOISTURE = A1;
int maxValueMoisture = 1020;
int maxPercMoisture = 100;
char moist_str;

// Define LEDs
const int PIN_LED1 = 2;
const int PIN_LED2 = 3;
const int PIN_LED3 = 4;

// Temperature
const int PIN_TEMPERATURE = 8;
#define DHTTYPE DHT22
DHT dht(PIN_TEMPERATURE,DHTTYPE);
char temp_str;
char humd_str;

// Servo Motor
// Define Servo Motor - Create Servo Object
const int PIN_SERVO = 5;
Servo myservo;
int servoPos, moveTime;

// Light & Speaker
const int PIN_LIGHT = A0;
char light_str;
const int PIN_SPEAKER = 9; 
int divider = 0, noteDuration = 0;

// Define the LCD Screen
Waveshare_LCD1602_RGB lcd(16,2);  //16 characters and 2 lines
int r,g,b = 0; 
char buffer [4]; // Value between 0-1023

// Songs for Dark, Dim, Light, Bright, Very Bright

int dark_tempo = 114;
int dark_melody[] = {
  // Mii Channel theme 
  // Score available at https://musescore.com/user/16403456/scores/4984153
  // Uploaded by Catalina Andrade 
  NOTE_FS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8,NOTE_A4,8, REST,8, NOTE_FS4,8, //1
  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, REST,4, REST,8, NOTE_CS4,8,
  NOTE_D4,8, NOTE_FS4,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_F4,8,
  NOTE_E5,-4, NOTE_DS5,8, NOTE_D5,8, REST,8, REST,4,  
};

int dim_tempo = 120;
int dim_melody[] = {
  // Pink Panther theme
  // Score available at https://musescore.com/benedictsong/the-pink-panther
  // Theme by Masato Nakamura, arranged by Teddy Mason
  REST,2, REST,4, REST,8, NOTE_DS4,8, 
  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
  NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
  NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,
};

int light_tempo = 160;
int light_melody[] = {
  // Keyboard cat
  // Score available at https://musescore.com/user/142788/scores/147371
    REST,1,
    NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
    NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
    NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
};

int bright_tempo = 144;
int bright_melody[] = { 
  // Tetris Theme - Korobeiniki
  //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192 
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,
};

int verybright_tempo = 105;
int verybright_melody[] = {
  // Pacman
  // Score available at https://musescore.com/user/85429/scores/107109
  NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, //1
  NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
  NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,
};

void setup(){

    // SetUp the LCD screen 
    lcd.init();
    lcd.setCursor(0,0);
    lcd.send_string("Hello World!");
    lcd.setCursor(0,1);
    lcd.send_string("Measure Nature");
    lcd.setRGB(255,100,70); //Define the color of the screen

    // SetUp the LED 
    pinMode(PIN_LED1,OUTPUT);
    pinMode(PIN_LED2,OUTPUT);
    pinMode(PIN_LED3,OUTPUT);

    // Start Temperature Sensor
    dht.begin();
    // Define Servo Pin
    myservo.attach(PIN_SERVO);

    // SetUp the pin input, output
    pinMode(PIN_SPEAKER,OUTPUT);

    // Serial Start
    Serial.begin (9600);
    delay(5000);
}

void loop(){
    // Moisture Measurement
    Funct_MeasureMoist();
    delay(10000); // Wait 10 seconds before a new reading. 
    // Temperature & Hum.
    Funct_MeasureTemp();
    delay(10000); // Wait 10 seconds before a new reading. 
    // Light
    Funct_MeasureLight();
    delay(10000); // Wait 10 seconds before a new reading. 
}


// ----- Functions ----- //
void Funct_MeasureMoist(){
  //Read Sensors Values
  int moistureValue = analogRead(PIN_MOISTURE);
  int moisturePercValue = map(moistureValue, 0, maxValueMoisture, 0, maxPercMoisture);
  Serial.println(moistureValue);
  Serial.println(moisturePercValue);
  Serial.println("");
  // Print Value LCD Display
  lcd.clear();
  lcd.send_string("Soil Moisture:");
  lcd.setCursor(0,1);
  
  //Convert int value into string - itoa()
  scanf ("&d",&moisturePercValue);
  itoa(moisturePercValue, buffer, 10);
  // Send the value to the LCD Screen.
  lcd.send_string(buffer);
  
  // Change LEDs Colors regarding to Moisture Value
  if (moisturePercValue < 30){
    // Add a note and sent it to the LCD Screen
    char moist_str[]="% Dry. Water!";
    lcd.send_string(moist_str);
    // Set the LEDs color
    digitalWrite(PIN_LED1,LOW);
    digitalWrite(PIN_LED2,HIGH);
    digitalWrite(PIN_LED3,HIGH);    
    } 
      else if ((moisturePercValue > 30) && (moisturePercValue < 70)){
      // Add a note and sent it to the LCD Screen
      char moist_str[]="% Avg. Moist!";
      lcd.send_string(moist_str);
      // Set the LEDs color
      digitalWrite(PIN_LED1,HIGH);
      digitalWrite(PIN_LED2,LOW);
      digitalWrite(PIN_LED3,HIGH);
      } 
        else {
        // Add a note and sent it to the LCD Screen
        char moist_str[]="% Very Wet!";
        lcd.send_string(moist_str);
        // Set the LEDs color
        digitalWrite(PIN_LED1,HIGH);
        digitalWrite(PIN_LED2,HIGH);
        digitalWrite(PIN_LED3,LOW);
        }
}

//  -------------------             -------------------- //
void Funct_MeasureTemp(){
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
}

//  -------------------             -------------------- //
void Funct_MeasureLight(){
  //Read Sensors Values
  int lightValue = analogRead(PIN_LIGHT);
  Serial.println("Light Intensity");
  Serial.println(lightValue);

  // Print Value LCD Display
  lcd.clear();
  // Light Intensity Value
  lcd.send_string("Light Intensity");
  //Convert float value into string - Send to LCD Screen
  lcd.setCursor(0,1);
  dtostrf(lightValue,3,0,buffer);
  lcd.send_string(buffer);

  // Change LCD Screen based on Light Value
  if (lightValue < 100) {
    char light_str[]=" Dark";
    lcd.send_string(light_str);
    // Song Variables
    int notes = sizeof(dark_melody) / sizeof(dark_melody[0]) / 2;
    int wholenote = (60000 * 4) / dark_tempo;
    
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
      // calculates the duration of each note
      divider = dark_melody[thisNote + 1];
      if (divider > 0) {
          // regular note, just proceed
          noteDuration = (wholenote) / divider;
      } else if (divider < 0) {
          // dotted notes are represented with negative durations!!
          noteDuration = (wholenote) / abs(divider);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
      }
      // we only play the note for 90% of the duration, leaving 10% as a pause
      tone(PIN_SPEAKER, dark_melody[thisNote], noteDuration*0.9);
      
      // Wait for the specief duration before playing the next note.
      delay(noteDuration);
    
      // stop the waveform generation before the next note.
      noTone(PIN_SPEAKER);
      }
    delay(5000); 
    } 
    else if (lightValue < 200) {
      char light_str[]=" Dim";
      lcd.send_string(light_str);
      // Song Variables
      int notes = sizeof(dim_melody) / sizeof(dim_melody[0]) / 2;
      int wholenote = (60000 * 4) / dim_tempo;
      
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
        // calculates the duration of each note
        divider = dim_melody[thisNote + 1];
        if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
        }
        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(PIN_SPEAKER, dim_melody[thisNote], noteDuration*0.9);
        
        // Wait for the specief duration before playing the next note.
        delay(noteDuration);
      
        // stop the waveform generation before the next note.
        noTone(PIN_SPEAKER);
        }
      delay(5000);
    } 
    else if (lightValue < 500) {
      char light_str[]=" Light";
      lcd.send_string(light_str);
      // Song Variables
      int notes = sizeof(light_melody) / sizeof(light_melody[0]) / 2;
      int wholenote = (60000 * 4) / light_tempo;
      
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
        // calculates the duration of each note
        divider = light_melody[thisNote + 1];
        if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
        }
        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(PIN_SPEAKER, light_melody[thisNote], noteDuration*0.9);
        
        // Wait for the specief duration before playing the next note.
        delay(noteDuration);
      
        // stop the waveform generation before the next note.
        noTone(PIN_SPEAKER);
        }
      delay(5000);
    }
    else if (lightValue < 800) {
      char light_str[]=" Bright";
      lcd.send_string(light_str);
      // Song Variables
      int notes = sizeof(bright_melody) / sizeof(bright_melody[0]) / 2;
      int wholenote = (60000 * 4) / bright_tempo;
      
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
        // calculates the duration of each note
        divider = light_melody[thisNote + 1];
        if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
        }
        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(PIN_SPEAKER, bright_melody[thisNote], noteDuration*0.9);
        
        // Wait for the specief duration before playing the next note.
        delay(noteDuration);
      
        // stop the waveform generation before the next note.
        noTone(PIN_SPEAKER);
        }
      delay(5000);
    } 
    else {
      char light_str[]=" Very Bright";
      lcd.send_string(light_str);
      // Song Variables
      int notes = sizeof(verybright_melody) / sizeof(verybright_melody[0]) / 2;
      int wholenote = (60000 * 4) / verybright_tempo;
      
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
        // calculates the duration of each note
        divider = light_melody[thisNote + 1];
        if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
        }
        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(PIN_SPEAKER, verybright_melody[thisNote], noteDuration*0.9);
        
        // Wait for the specief duration before playing the next note.
        delay(noteDuration);
      
        // stop the waveform generation before the next note.
        noTone(PIN_SPEAKER);
        }
      delay(5000);
    }
}  
