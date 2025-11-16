// Write a program that allows the user to control the LED connected to pin 13 of the Arduino. 
// When the program is started, the LED should be off. The user should open the serial monitor to communicate with the Arduino. 
// If the user sends the character '1' through the serial monitor then the LED should turn on. 
// If the user sends the character '0' through the serial monitor then the LED should turn off. 


void setup() {
  Serial.begin(9600); // Initialize UART protocol with Baud rate at 9600 bps
  pinMode(13, OUTPUT); // We want to control this LED
  digitalWrite(13, LOW); // We want the LED to start off

}

void loop() {
  
  int display_count = 0; // Variable to control the number of time we display prompt
    
  // Wait for user input
  while (Serial.available() == 0) {
    if (display_count == 0) {
      	// Prompt user for input once (avoid flooding)
    	Serial.println("Please, enter 0 to turn off and 1 to turn on the LED");
    	display_count++;
    	}
    }
  
  if (Serial.available() > 0) {     // Only read if data is available
    
    char user_input = Serial.read();  // Read as a character
    
    Serial.print("User Input: ");
    Serial.println(user_input);
    
    if (user_input == '1') {
      if (digitalRead(13) == LOW){
      	digitalWrite(13, HIGH);
      	Serial.println("PIN 13 is HIGH, LED is now ON");
      }
      
      else {
        Serial.println("PIN 13 is HIGH, LED was already ON");
      }
    }
    
    else if (user_input == '0'){
      if (digitalRead(13) == HIGH) {
      	digitalWrite(13, LOW);
      	Serial.println("PIN 13 is LOW, LED is now OFF");
      }
      
      else
      {
        Serial.println("PIN 13 is LOW, LED was already OFF");
      }
    }
    
    else {
      // DO NOTHING FOR ANY OTHER INPUT THAN 0 or 1
      Serial.println("Invalid input—only 0 or 1 accepted.");
    }
      
    };

  }

}

}
