### Tasks

- [x] interface with Seeeduino
  - [x] program it
  - [x] check ADC value against DMM
    - it's okay, seems to be off 0.03V
- [x] connect Seeeduino with ESP-01
  - [x] try serial, software serial sucked
    - using this `Serial1` thing not regular Serial maybe can use both at the same time i.e. the serial monitor
- [x] connect moisture sensor to ADC/make sure it works/value sent
- [ ] add voltage divider for power measurement
  - looks like using 2 M Ohm resistors for 6.4V to < 3.3V
- [ ] test solar panels
  - [ ] wire up
    - using a step down converter after all since need 6-7V.
  - [ ] see if it charges battery noticeably
  - serial connection, backflow diodes in place to charge 4cell can battery
- [ ] design parts
- [ ] print
- [ ] assemble
- [ ] deploy
- [ ] write server side code
- [ ] write basic "mobile" app
- [ ] do a test of battery duration/consumption over a day

### 03/03/2021
So I got the hardware serial to work which is good because I tried software serial before and it sucks/not reliable. Initially struggled with the `Serial` write not being detected by ESP but saw the `Serial1` variant for Seeeduino. Oh wow I guess this is a thing, didn't know about it ["logic level serial"](https://stackoverflow.com/questions/21944925/arduino-serial1) cool. Anyway it all works, transmits. I almost forgot to do the flush buffer thing till I started to see it concatenate in the Node server logs.

### 03/02/2021
Here we go again... just got the Seeeduino, soldered the male headers on and powered it on through the 5V. Looks like it is preloaded with some blink sketch.

Ehh.. I'm burnt today I have to program the ESP-01 then program Seeeduino then wire them up. Using this [page](https://www.instructables.com/Serial-Communication-Between-Arduino-and-ESP-01/) for the serial wiring.