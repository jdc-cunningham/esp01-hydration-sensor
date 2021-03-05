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

### 03/04/2021
This is the plan I have now. I will stagger-connect the analog pins and use the previous pin to power the next pin when doing a measurement by digital out. I think it's just under the operating voltage of the moisture sensor but this way the sensors aren't always on. Since now it can support up to 8 moisture sensors(wanted to use all pins). So the design has changed too, see the drawing below. Will have a port to accept more moisture sensors. The code will scan all analog values and send them but the web interface can say if it will ignore them or not. I'll also measure the voltage of the device so I can tell when I need to charge it. The intent at the moment is to constantly charge the battery with something like 30mA... I think generally the whole unit will only use around that amount at a time. The Seeeduino has an operating current looks like of [13.3mA](https://twitter.com/nicho810/status/1287990412758487040?lang=en).

![current concept](./plan.JPG)

The wiring will not be exactly like this. I realize a pin can power the pin to it's left/right. Also maybe you only need at least 2... the one that is not measuring powers any other pin by parallel wiring. This does work, I tested it but only one set eg. A0 to A1. Yeah I think really A0 could power all the pins and A1 can power A0.They are only one for 1 second to do a measurement. Each pin can only do 7mA and the sensor has an operating current of 5mA so it's one pin at a time while sampling.

I don't have any relays is the problem, I'm done ordering parts for a while as it's a stressful thing to do with my current living situation. I've lost at least 5 things already due to delivery problems.

Oh man... I don't think this will work actually. If the sensors are physically connected they will draw power. I will have to think about this may have a gross oversight.
### 03/03/2021
So I got the hardware serial to work which is good because I tried software serial before and it sucks/not reliable. Initially struggled with the `Serial` write not being detected by ESP but saw the `Serial1` variant for Seeeduino. Oh wow I guess this is a thing, didn't know about it ["logic level serial"](https://stackoverflow.com/questions/21944925/arduino-serial1) cool. Anyway it all works, transmits. I almost forgot to do the flush buffer thing till I started to see it concatenate in the Node server logs.

### 03/02/2021
Here we go again... just got the Seeeduino, soldered the male headers on and powered it on through the 5V. Looks like it is preloaded with some blink sketch.

Ehh.. I'm burnt today I have to program the ESP-01 then program Seeeduino then wire them up. Using this [page](https://www.instructables.com/Serial-Communication-Between-Arduino-and-ESP-01/) for the serial wiring.