#Notes on Arduino Nano r3 

1. Arduino IDE - Issue
While trying to upload a sketch, I got the following error

```
avrdude: set_open(): ser_open(): can't open device "/dev/ttyACM0": Permission denied
```
  To fix it, enter the command:

  ```
  sudo usermod -a -G dialout <username>
  sudo chmod a+rw <devicepath>
  ```
