# Silly Japanese Children's Color Mixing Song 🎨🧡 (or "Aka Kiro Color Mixing Lights")

Two RGB LEDs synced to the viral 'Aka Kiro' color-mixing song from the Japanese kids' show DokoDemoJamboree — blue + yellow = green, in light form.

## Parts
- Arduino Uno
- Breadboard
- 6 resistors (220 Ω)
- 2 RGB LED
- 9 M to M wires

## Wiring
Two common-cathode RGB LEDs, each with 4 legs: red, green, blue, and one common (the longest leg).
The long (common) leg of both LEDs goes to GND — both share the breadboard's – (negative) rail, with one wire running from that rail to the Arduino's GND pin.
Each color leg connects to its Arduino pin through a 220 Ω resistor — 3 resistors per LED, 6 resistors total — to limit current and protect the LEDs and pins.

## LED #1 pin connections:

Red leg → pin 6 (via resistor)
Green leg → pin 5 (via resistor)
Blue leg → pin 3 (via resistor)


## LED #2 pin connections:

Red leg → pin 11 (via resistor)
Green leg → pin 10 (via resistor)
Blue leg → pin 9 (via resistor)

## How it works
When the Arduino powers on, setup() runs once and makes all six pins outputs, then loop() runs forever, playing your light show top to bottom. First the wake-up — LED #2 turns blue and holds for about 2.2 seconds, then LED #1 joins as yellow for another 2.2 seconds. Next the for loop does the color hop: it walks through your palette of colors, showing LED #1 on color i and LED #2 on color j (three steps ahead, wrapped around with the % so they're always on different colors), each pair held 250 ms. After that, both LEDs go green together and hold for 3 seconds, then the green-blink loop runs four quick rounds — though note it actually alternates the two LEDs (LED #1 green while LED #2 is off, then they swap) rather than blinking both together like the comments say. Finally both LEDs turn off, hold 3 seconds, and loop() starts over from the top. The one thing to fix is numColors = 14 — your palette only has 7 colors, so the hop reads past the end of the arrays and shows random garbage colors for the second half; change it to int numColors = 7; (or use sizeof(reds)/sizeof(reds[0]) to auto-count) and it'll behave correctly.

## How to run
0. Set up your Ardruino
1. Open the .ino in the Arduino IDE
2. Select Board: Arduino Uno + the right Port
3. Click Upload

## Notes / customizing
- Just change the numbers for the RGB colors on analogWrite right after void loop and the code comment that says // both LEDs red, at the same time (Like, I know I wrote the comment wrong but it's ok).
