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
    // Pause for 200ms (I can't remember why we do this).
    delay(200);
  }
  // Print what mode we're in.
  Serial.print("Mode ");
  Serial.println(modeToggle);
  
  // Clever code that divides the modeToggle by three to work out what mode it's in goes here.
  
  if (toggle == false) {           // When you power up your arduino, boolean "toggle" is set to false, so the following section of code will commence. The "ELSE" is ignored for now.
      digitalWrite(LED, LOW);      // Turn the LED off
      analogValue = analogRead(0); // Take an analog reading from A0 line.  No sounds should be offer a returned value of "0"
      if (analogValue > 8) {       // If higher than 8 is returned, then change state of boolean "toggle" to true, display analogValue to serial monitor and wait 200ms. The higher the value in the above "if" statement, the less sensitive your clapper will be.  Use the serial monitor to calibrate to your wanted sensitivity =D
        toggle = true;
        Serial.println(analogValue);
        delay(200);
      }
  }
  else {                         // If boolean "toggle" has beenchanged to true, then the above section of code will be ignored, and the code below will commence.
    digitalWrite(LED, HIGH);     // Turn the LED on
    analogValue = analogRead(0); // Take an analog reading from A0 line.  No sounds should be offer a returned value of "0"
    if (analogValue > 8) {       // If higher than 8 is returned, then change state of boolean "toggle" back to false, print analogValue to serial monitor and wait 200ms. The higher the value in the above "if" statement, the less sensitive your clapper will be.  Use the serial monitor to calibrate to your wanted sensitivity =D
        toggle = false;
        Serial.println(analogValue);
        delay(200);
    }
  }
}

// Functions will go here.
