// Define variables
int analogValue;        // This is where we'll store our audio to digital value. Larger value indicates louder sound.
const int LED = 13;     // Set up the LED indicator. We can use const because it's not going to change.
int ledPins[] = {12,11,10}; // Array of pin values
boolean toggle = false; // This boolean is going to have to go, because we're going to have more than one mode.
int modeToggle = 0;     // This is how we'll decide which mode we're in.

// Setup
void setup() {
  pinMode(LED, OUTPUT); // Pin#2 should be conencted to an LED through a 300-600 ohm resistor    
  Serial.begin(9600);   // This is optional - It just helps you to calibrate sensitivity after the fact
  // Set up pins
  for (int thisPin = 0; thisPin < 2; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

// Main

void loop() {
  // Take a "volume reading".
  analogValue = analogRead(0);
  // If the volume is loud enough ...
  if (analogValue > 8) {
    // then increment the modeToggle variable.
    modeToggle = modeToggle + 1;
    // Prevent the modeToggle value from exceeding range 0, 1, 2
    modeToggle = modeToggle % 5; 
    // Pause for 200ms (I can't remember why we do this).
    delay(200);
  }
  // Print what mode we're in.
  Serial.print("Mode ");
  Serial.println(modeToggle);
  // Do different things based on modeToggle value
  if (modeToggle == 0) {
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
  }
  else if (modeToggle == 1) {
    // Mode 1 (Blue only)
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
  }
  else if (modeToggle == 2) {
    // Mode 2 (Blue and green)
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
  }    
  else if (modeToggle == 3){
    // Mode 3 (Blue, green and red)
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
  }
  else {
    // Mode 4 (Red only)
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], HIGH);
  }
}
