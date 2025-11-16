// Write a program that allows the user to control the LED connected to pin 13 of the Arduino.
// When the program is started, the LED should be off. The user should open the serial monitor to communicate with the Arduino.
// If the user sends the character '1' through the serial monitor then the LED should turn on.
// If the user sends the character '0' through the serial monitor then the LED should turn off.

int ledPin = 13;      // Define the pin where the LED is connected
void setup()
{
  Serial.begin(9600);    // Initialize UART protocol with Baud rate at 9600 bps
  pinMode(ledPin, OUTPUT);   // We want to control this LED
  digitalWrite(ledPin, LOW); // We want the LED to start off
}

void loop()
{

  int display_count = 0; // Variable to control the number of time we display prompt

  // Wait for user input
  while (Serial.available() == 0)
  {
    if (display_count == 0)
    {
      // Prompt user for input once (avoid flooding)
      Serial.print("[INFO] Using PIN ");
      Serial.println(ledPin);
      Serial.println("[INFO] Please, enter 0 to turn off and 1 to turn on the LED");
      display_count++;
    }
  }

  if (Serial.available() > 0)
  { // Only read if data is available

    char user_input = Serial.read(); // Read as a character
    
    if (user_input == '1')
    {
      Serial.print("[INFO] User Input: ");
      Serial.println(user_input);
      if (digitalRead(ledPin) == LOW)
      {
        digitalWrite(ledPin, HIGH);
        Serial.println("[OUTPUT] PIN 13 is HIGH, LED is now ON");
      }

      else
      {
        Serial.println("[OUTPUT] PIN 13 is HIGH, LED was already ON");
      }
    }

    else if (user_input == '0')
    {
      if (digitalRead(ledPin) == HIGH)
      {
        Serial.print("[INFO] User Input: ");
        Serial.println(user_input);
        digitalWrite(ledPin, LOW);
        Serial.println("[OUTPUT] PIN is LOW, LED is now OFF");
      }

      else
      {
        Serial.println("[OUTPUT] PIN is LOW, LED was already OFF");
      }
    }

    // Avoid considering newlines, space and carriage returns as input
    else if (user_input == '\n' || user_input == '\r' || user_input == ' ') {
     // Do nothing there
    }

    else
    {
      // DO NOTHING FOR ANY OTHER INPUT THAN 0 or 1
      Serial.print("[ERROR] Invalid input—only 0 or 1 accepted. ");
      Serial.print("You have inputted : ");
      Serial.println(user_input);
    }
  };
}
