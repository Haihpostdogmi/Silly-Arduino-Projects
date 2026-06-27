//define Pins

#define BLUE 3
#define GREEN 5
#define RED 6
#define BLUES 9
#define GREENS 10
#define REDS 11

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BLUES, OUTPUT);
  pinMode(GREENS, OUTPUT);
  pinMode(REDS, OUTPUT);
}

// color palette: each column is one color (R, G, B)
int reds[]   = {255,   0,   0, 255,   0, 255, 255};
int greens[] = {  0,  90,   0,  50,  90,   0, 110};
int blues[]  = {  0,   0, 255,   0, 110, 255, 130};
int numColors = 14;

void led1(int r, int g, int b) {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}
void led2(int r, int g, int b) {
  analogWrite(REDS, r);
  analogWrite(GREENS, g);
  analogWrite(BLUES, b);
}

void loop() {
  analogWrite(REDS,0);
  analogWrite(GREENS,0);
  analogWrite(BLUES,0);
  delay(400);

  analogWrite(REDS,0);
  analogWrite(GREENS,0);
  analogWrite(BLUES,255);
  delay(2200);
  
  //turns it yellow
  analogWrite(RED,255);
  analogWrite(GREEN,50);
  analogWrite(BLUE,0);
  delay(2200);

 for (int i = 0; i < numColors; i++) {
  int j = (i + 3) % numColors;   // j points to a DIFFERENT color than i

  led1(reds[i], greens[i], blues[i]);   // LED #1 = color i
  led2(reds[j], greens[j], blues[j]);   // LED #2 = color j (different)
  delay(250);
}
// both LEDs red, at the same time
analogWrite(RED, 0);   analogWrite(GREEN, 255);   analogWrite(BLUE, 0);
analogWrite(REDS, 0);  analogWrite(GREENS, 255);  analogWrite(BLUES, 0);
delay(3000); 
 // ---------- green blink at the end ----------
  for (int i = 0; i < 4; i++) {
    led1(0, 90, 0);   led2(0, 0, 0);    // both green ON
    delay(150);
    led1(0, 0, 0);    led2(0, 90, 0);     // both OFF
    delay(150);
  }
analogWrite(RED, 0);   analogWrite(GREEN, 0);   analogWrite(BLUE, 0);
analogWrite(REDS, 0);  analogWrite(GREENS, 0);  analogWrite(BLUES, 0);
delay(3000); 
}   // ← closes the for loop
// both LEDs red, at the same time
    // ← closes loop()  ← THIS is the one you were missing
