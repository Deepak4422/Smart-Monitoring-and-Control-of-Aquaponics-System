#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <Wire.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
Adafruit_BME280 bme;


#include <LiquidCrystal.h>

#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define commonAnode true
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);





const char* ssid = "Deepak";
const char* password = "radhaaurkrishna";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


/*
// Setup for LCD display----------------------------------------------------------------------------
const int rs = 4, en = 2, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void lcdStart(){
    lcd.begin(20,4);
    delay(100);
}




 // color sensor setup------------------------------------------------------------------------------
 
void colorStart(){
  if (tcs.begin()) {
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); 
  }
  delay(100);
}


 //returns the HUE of the color in degrees
 // Return Type: int
 
int SolnColor()       
{
  float red, green, blue;

  tcs.setInterrupt(false);
  delay(60);
  tcs.getRGB(&red, &green, &blue);
  tcs.setInterrupt(true);

  int hue;
  float Vmax, Vmin, diff;
  Vmax = max(red, max(green, blue));
  Vmin = min(red, min(green, blue));
  diff = Vmax - Vmin;
  if (Vmax == red)
    hue = (int)(60.0 * (green - blue) / diff + 360) % 360;
  else if (Vmax == green)
    hue = (int)(60.0 * (red - blue) / diff + 120);
  else if (Vmax == blue)
    hue = (int)(60.0 * (red - green) / diff + 240);
  if (abs(hue) == 360)hue = 0;
  return abs(hue);
}



 // returns a statement according to the amount of ammonia present 
 //Return Type- sring
 
String Ammonia(int hue){
  String s;
  
  if(hue<=65)
    "Ammonia 0ppm";
  else if(hue<=75)
    s="Ammonia 0.25ppm";
  else if(hue<=90)
    s="Ammonia 0.5pmm";
  else if(hue<=100)
    s="Ammonia 1ppm";
  else if(hue<=130)
    s="Ammonia 2.0ppm";
  else if(hue<=150)
    s="Ammonia 4ppm";
  else s="***INCORRECT RESULT***";
  return s;
  }



 // returns a statement according to the amount of nitrate present 
 // Return Type- sring
 
String Nitrate(int hue){
  String a;
  
  if(hue>=355||hue<=10)
    a="Nitrate >40ppm";
  else if(hue<=33)
    a="Nitrate 10-20 ppm";
  else if(hue<=45)
    a="Nitrate 5ppm";
  else if(hue<=70)
    a="Nitrate 0ppm";
    return a;
  }


  String Nitrite( int hue){
    String a;
    
  }

// Setup for motor operation-------------------------------------------------------------------------

  const int shakerMotor=10;
const int screwMotor=9;
const int Na=0
const int Ni=0
const int Am=0


void motorsStart(){
  pinMode(shakerMotor,OUTPUT);
  pinMode(screwMotor,OUTPUT);
}

void shake(int Time){
  digitalWrite(shakerMotor,HIGH);
  delay(Time);
  digitalWrite(shakerMotor,LOW);
}

void screw(String test){
 if(test=="nitrate"){
  digitalWrite(screwMotor,HIGH);
  int steps=Na,stepCount=0;
   while(steps<stepCount){
    if(digitalRead(encoder)==HIGH)
      stepCount++;
   }
   digitalWrite(screwMotor,LOW);
 }
 
 else if(test=="nitrite"){
  digitalWrite(screwMotor,HIGH);
  int steps=Ni,stepCount=0;
   while(steps<stepCount){
    if(digitalRead(encoder)==HIGH)
      stepCount++;
   }
   digitalWrite(screwMotor,LOW);
 }
 

 else if(test=="ammonia"){
  digitalWrite(screwMotor,HIGH);
  int steps=Am,stepCount=0;
   while(steps<stepCount){
    if(digitalRead(encoder)==HIGH)
      stepCount++;
   }
   digitalWrite(screwMotor,LOW);
 }
}



//Setup for Measuring the ph------------------------------------------------------------------------

float pH(){
  float ph=analogRead(A3);
  return ph;
}



//Setup for Waterflow pump---------------------------------------------------------------------------
const int waterflow=12;
const int pump=13;
const float waterflowConst = 2.25;

void waterStart(){
  pinMode(waterlow,INPUT);
  pinMode(pump,OUTPUT);
  digitalWrite(pump,LOW);
  delay(100);
}

void water(int amount){
  int count=amount/2.25;
  bool state=digitalRead(waterflow);
  digitalWrite(pump,HIGH);
  while(count){
    if(digitalRead(waterflow)!=state){
      state=digitalRead(waterflow);
      count--;
    }
  }
  digitalWrite(pump,LOW);
}

*/
String readBME280Temperature() {
  // Read temperature as Celsius (the default)
  float t = bme.readTemperature();
  // Convert temperature to Fahrenheit
  //t = 1.8 * t + 32;
  if (isnan(t)) {    
    Serial.println("Failed to read from BME280 sensor!");
    return "";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

String readBME280Humidity() {
  float h = bme.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from BME280 sensor!");
    return "";
  }
  else {
    Serial.println(h);
    return String(h);
  }
}

String readBME280Pressure() {
  
    
    float ans=5;
    Serial.println(ans);
    return String(ans);
  
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  bool status; 
  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    //while (1);
  }

  // Initialize SPIFFS
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Temperature().c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Humidity().c_str());
  });
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Pressure().c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){
  
}
