// Define variables
int analogValue;        // This is where we'll store our audio to digital value. Larger value indicates louder sound.
const int LED = 13;     // Set up the LED indicator. We can use const because it's not going to change.
boolean toggle = false; // This boolean is going to have to go, because we're going to have more than one mode.
int modeToggle = 0;     // This is how we'll decide which mode we're in.

// Setup
void setup() {
  pinMode(LED, OUTPUT); // Pin#2 should be conencted to an LED through a 300-600 ohm resistor    
  Serial.begin(9600);   // This is optional - It just helps you to calibrate sensitivity after the fact
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
    modeToggle = modeToggle % 3; 
    // Pause for 200ms (I can't remember why we do this).
    delay(200);
  }
  // Print what mode we're in.
  Serial.print("Mode ");
  Serial.println(modeToggle);
  // Do different things based on modeToggle value
  if (modeToggle == 0) {
    // Mode 1 (this is the first, starting mode)
  }
  else if (modeToggle == 1) {
    // Mode 2 (this will be active when we clap for the first time)
  }
  else {
    // Mode 3 (this will be active after two claps)
  }
}
