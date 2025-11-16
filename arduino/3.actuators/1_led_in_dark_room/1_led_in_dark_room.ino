// Build a circuit that lights an LED when it is sufficiently dark in a room. 
// Demonstrate the circuit by covering the photoresistor to simulate darkness.

// We've used R1 = 10k ohms in the voltage divider with the photoresistor.
// We've used R2 = 220 ohms in series with the LED to limit current.

void setup() {
  pinMode(13, OUTPUT); // Set pin 13 as output to control the LED
  pinMode(A0, INPUT); // Set pin A0 as input to read the photoresistor
  Serial.begin(9600); // Initialize serial communication at 9600 bps
}

void loop() {
  int sensorValue = analogRead(A0); // Read the value from the photoresistor
  Serial.print("Photoresistor Value: ");
  Serial.println(sensorValue); // Print the sensor value to the serial monitor

  // If the sensor value is below a certain threshold, turn on the LED
  if (sensorValue < 500) { // Adjust threshold as needed
    digitalWrite(13, HIGH); // Turn on LED
  } else {
    digitalWrite(13, LOW); // Turn off LED
  }

  delay(1000); // Wait for 1 second before the next reading
}