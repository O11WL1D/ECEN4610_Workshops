
#include "FastLED.h"

#define NUM_LEDS  20    // number of leds 
#define PIN       3      // PIN ARDUINO





void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.clear();            
}

void loop() {
  // put your main code here, to run repeatedly:

 for(int i = 0; i <= NUM_LEDS; i++) {
 leds[i].setRGB(0, 100, 0);
 FastLED.show(); 
  delay(1000); 
   leds[i].setRGB(200, 0, 0);
   FastLED.show(); 
   delay(1000); 
    leds[i].setRGB(0, 100, 0);
    FastLED.show(); 
    delay(1000); 
     leds[i].setRGB(0, 0, 100);
     FastLED.show(); 

 }

  FastLED.clear();

}



void setAndWrite(float pdistance){












int option=0;


//this function sets the led strip to different colors based on the 
//received distance. There is an additional parameter called option which can be used to 
//toggle which pattern is desired. currently this parameter is hardcoded. 



int maxdistance=1192;
//the maxdistance measures the passive value of the sensor when there is nothing in front of it.
//This max value will be derived via experimentation with the distance sensor.


int maxcolor=255;
//this is the maximum value that can be inputted into the led_write function for any of the three parameters.




//the distance from the sensor is returned as a float, because the leds only accept discrete integer values, we need to perform a typecast
// on the passed distance to the used, internal distance.

int distance=(int)pdistance;




if(option==0){

//in this mode, a color gradient is mapped to each value on the numberline ending at the max distance. 
// for now the leds will only cycle through shades of red, further functionality will be implemeneted in other
// option switches.



colorincrement=maxcolor/maxdistance;

currentcolor=colorincrement*distance;


 for(int i = 0; i <= NUM_LEDS; i++) {

leds[i].setRGB(currentcolor, 0, 0);
 FastLED.show(); 

 }




}






if(option==1){

//this option cycles through the increment for all colors, with all parameters being inputted with the 
//current incremenet.




colorincrement=maxcolor/maxdistance;

currentcolor=colorincrement*distance;


 for(int i = 0; i <= NUM_LEDS; i++) {

leds[i].setRGB(currentcolor, currentcolor, currentcolor);
 FastLED.show(); 

 }




}


  FastLED.clear();



}
















