// C++ code
//
void setup() {
  pinMode(13, OUTPUT); //Set up pin 13 as output so that we can control the LED
}

void blink(float halfperiod){ // Function to blink the LED
  digitalWrite(13, HIGH); // Turn the LED on
  delay(halfperiod);       // Wait for half the period (in milliseconds)
  digitalWrite(13, LOW); // Turn the LED off
  delay(halfperiod);    // Wait for another half the period to complete the cycle
  }

void loop() {
  for (int i=0; i<5; i++ ){ // Blink 5 times with a half-period of 500 ms (1 second full period)
    blink(500);
  }
  for (int i=0; i<5; i++ ){ // Blink 5 times with a half-period of 2000 ms (4 seconds full period)
    blink(2000);
  }
}
