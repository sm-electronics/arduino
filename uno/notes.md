# Arduino Notes

1. Only digital pins 3, 5, 6, 9, 10, and 11 on a regular Arduino board can be used for PWM. They are marked on the Arduino board 
with a tilde (~)

2. To creat a PWM signal we use analogWrite function instead of digitalWrite.

3. Each digital output pin on the Arduino Uno can offer a maximum of 40 mA of current per pin and 200 mA total for all pins.

4. For error ser_open "Cant open device permission denied", run the following command
  ```
   sudo chown root:YOURUSERNAME /dev/ttyUSB0
  ```
5. Tutorial on [how to use shift registers](https://www.arduino.cc/en/Tutorial/ShiftOut)
