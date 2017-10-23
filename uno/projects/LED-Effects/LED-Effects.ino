/**
 * Uses FastPixel Library to create several light effects
 * 
 */
#define FASTLED_INTERNAL
#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    30
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
   
}

void loop() {
  // call any effects function from here :
  //RGBLoop();
  
  //Fade inout any colors
  fadeInOut(0xff,0x00,0x00); //red
  fadeInOut(0xff,0xff,0xff);  //white
  fadeInOut(0x00,0x00,0xff); //blue
}

void showStrip() {
  FastLED.show();
}

void setPixel(int pixel, byte red, byte green, byte blue) {
  leds[pixel].r = red;
  leds[pixel].g = green;
  leds[pixel].b = blue;
}

void setAllPixels(byte red, byte green, byte blue) {
  for(int i=0; i < NUM_LEDS; i++) {
      setPixel(i, red, green, blue);
  }  
  showStrip();
}

/**
 * This effect uses fixed set of colors for all LEDs, in sequence, red, green and blue. 
 * The brightness is increased slowly until maximum brightness level is reached and then
 * it is decreased until the LEDs are off
 * 
 */
void RGBLoop() {
  for(int col = 0; col < 3; col++) {
    //Fade in
    for (int k=0;k<256;k++) {
      switch(col) {
        case 0: setAllPixels(k,0,0);
                break;
        case 1: setAllPixels(0,k,0);
                break;
        case 2: setAllPixels(0,0,k);
                break;
      }
      showStrip();
      delay(3);
    }
    //FADE OUT
    for (int k=255;k>=0;k--) {
      switch(col) {
        case 0: setAllPixels(k,0,0);
                break;
        case 1: setAllPixels(0,k,0);
                break;
        case 2: setAllPixels(0,0,k);
                break;
      }
      showStrip();
      delay(3);
    }
  }
}

/**
 * Fade in and out, any own color
 * 
 */
void fadeInOut(byte red, byte green, byte blue) {
  float r, g, b;

  //FADE IN
  for (int k=0;k<256; k++) {
    r = (k/256.0) * red;
    g = (k/256.0) * green;
    b = (k/256.0) * blue;
    setAllPixels(r,g,b);
    showStrip();  
  }
  //FADE OUT
  for (int k=255;k >=0; k = k-2) {
    r = (k/256.0) * red;
    g = (k/256.0) * green;
    b = (k/256.0) * blue;
    setAllPixels(r,g,b);
    showStrip();  
  }
}

