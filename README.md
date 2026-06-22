# Joystick-led-controller
A simple Arduino project that maps joystick movements to a 3x3 LED grid. Push the joystick in any direction and the corresponding LED lights up. Press down to trigger the click LED.

### Overview 
This project uses an HW-504 analog joystick to control 10 LEDs arranged in a 3x3 grid plus a click indicator. The joystick's X and Y axes are read as analog values, converted into one of 9 directional positions, and the corresponding LED is illuminated in real-time.

### Features  
-9-direction LED feedback (8 directions + center)  
-Joystick press detection with dedicated LED  
-Smooth, responsive control  

### Components  
Arduino Mega 2560	1EA  
HW-504 Joystick	2-axis + push button	1EA  
LEDs	5mm, any color	10EA  
Resistors	220Ω	10EA  
Breadboard	Half-size or larger	1EA  
Jumper Wires	Male-to-male	~20EA  
Jumper Wires	Male-to-Female	5EA   

### Wiring and Connections  
**Joystick Connections**
```markdown
 Joystick Pin | Arduino Pin | Wire Color | Description 
------------- | ------------| -----------| -------------         
 GND          | GND         | Black      | Ground      
 VCC          | 5V          | Red        | PWR supply (5V) 
 VRx          | A0          | Yellow     | X-axis analog output 
 VRy          | A1          | Orange     | Y-axis analog output 
 SW           | A2          | Blue       | Push button (active LOW)
```
**LED Connections**  
Each LED is wired in this format :- Arduino Pin - 220Ω Resistor - LED Anode - LED Cathode - GND

```markdown
 LED | Position      | Arduino Pin 
 ----|-------------- |--------------
 1   | Bottom-Left   | D2 
 2   | Bottom-Center | D3 
 3   | Bottom-Right  | D4 
 4   | Mid-Left      | D5 
 5   | Center        | D6 
 6   | Mid-Right     | D7 
 7   | Top-Left      | D8 
 8   | Top-Center    | D9 
 9   | Top-Right     | D10 
 10  | Click         | D11 

```
**Note:** All LED cathodes connect to a common ground rail, which connects to Arduino GND with a single wire.






