/* ***********************************************************
 *  PWM - Test
 *
 * Only digital pins 3, 5, 6, 9, 10, and 11 on a regular Arduino board can be used for PWM. They are marked on the Arduino board with a tilde (~)
 * To creat a PWM signal we use analogWrite function instead of digitalWrite.
 * 
 * The following program uses 3, 5 and 6 
 * smtechnocrat 
 ***************************************************************/

// constants won't change. Used here to set a pin number :
const int ledPin3 =  3;      // the number of the LED pin
const int ledPin5 =  5;      // the number of the LED pin
const int ledPin6 =  6;      // the number of the LED pin

// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pins as output:
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
}

void loop() {

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    int d = 500;
    for ( int a = 6 ; a >  1 ; a-- ) {
      analogWrite(a, ledState);
      delay(d);
      analogWrite(a, ledState);
      delay(d);
    }
  }
}