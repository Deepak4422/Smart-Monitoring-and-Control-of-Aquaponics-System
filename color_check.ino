#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define commonAnode true
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


/*
 * color sensor setup
 */
void colorStart(){
  if (tcs.begin()) {
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); 
  }
  delay(100);
}


/*
 * returns the HUE of the color in degrees
 * Return Type: int
 */
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


/*
 * returns a statement according to the amount of ammonia present 
 * Return Type- sring
 */
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


/*
 * returns a statement according to the amount of nitrate present 
 * Return Type- sring
 */
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
