// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        3 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {


  //pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  //for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    //pixels.setPixelColor(i, pixels.Color(0, 150, 0));

 //   pixels.show();   // Send the updated pixel colors to the hardware.

   // delay(DELAYVAL); // Pause before next pass through loop
  //}

 for(int i = 0; i <= 1192; i++){

setAndWrite(i);

delay(DELAYVAL);
 }



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


 for(int i = 0; i <= NUMPIXELS; i++) {

//leds[i].setRGB(currentcolor, 0, 0);
 pixels.setPixelColor(i, pixels.Color(currentcolors, 0, 0));
 pixels.show();
 //FastLED.show(); 

 }




}






if(option==1){

//this option cycles through the increment for all colors, with all parameters being inputted with the 
//current incremenet.




colorincrement=maxcolor/maxdistance;

currentcolor=colorincrement*distance;


 for(int i = 0; i <= NUMPIXELS; i++) {

//leds[i].setRGB(currentcolor, currentcolor, currentcolor);
// FastLED.show(); 

 pixels.setPixelColor(i, pixels.Color(currentcolors, 0, 0));
 pixels.show();

 }




}


 pixels.clear();



}

















