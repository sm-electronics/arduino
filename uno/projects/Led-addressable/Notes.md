# Arduino LED Addressable WS28 LED Strip

### Features
- The WS2812B addressable LED strip comes in several varieties that differ in size, sealant or LED density
- This LED strip is made by WS2812B LEDs wired in series. These LEDs have a IC built right into the LED. This allows a communication via a one-wire interface. This means that we can control lots of LEDs using just one digital pin of your Arduino.
- This kind of strips are very flexible and can be cut to any length you want. Each strip is divided into segments, and each segment contains one RGB LED.  
- The LED strip should be powered using a 5V power source. At 5V, each LED draws about 50mA, when set to its full brightness.  This means that for every 30 LEDs, the strip may draw as much as 1.5 A. Make sure you select a power source that matches the strip’s needs.

### Schematics
![](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2016/09/WS2812B-with-Arduino_bb.png?w=700&ssl=1)

### Additional connectors
- Use a capacitor with a capacitance between 100uF and 1000uF from power to ground to smooth out the power supply.
- Add a 220 or 470 Ohm resistor between the Arduino digital output pin and the strip data input pin to reduce noise on that line.
- Make your wires between the arduino, power supply and the strip as short as possible to minimize voltage loss.
- If the strip gets damaged and doesn’t work, check if the first LED is broken. If so, cut it, resolder the header pins, and it should be working again.

### Libraries Used
- To control the WS2812B LED strip, you’ll need to download the FastLED library
- Neopixel - need to try out this library as well

### Notes
- Using 30 LEDs in each strip
- Next use BBC Micro to control 

### Issues 
The following #define line is needed in order to get rid of the pragma messages which is a IDE bug, otherwise this code will not compile. Put this line before including the FASTLed library
```
  #define FASTLED_INTERNAL
```
