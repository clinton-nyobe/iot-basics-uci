// Write a sketch that allows a user to access data in EEPROM using the serial monitor.
// In the serial monitor the user should be able to type one of two commands: 
// “read” and “write.
// "Read" takes one argument, an EEPROM address.
// "Write" takes two arguments, an EEPROM address and a value.

// For example, if the user types “read 3” then the contents of EEPROM address 3 should be printed to the serial monitor. 
//If the user types “write 3 10” then the value 10 should be written into address 3 of the EEPROM


#include <EEPROM.h> // We are using the arduino EEPROM

String inputString = "";

// --------------------------------------------------------------
// SETUP
// --------------------------------------------------------------
void setup()
{
    Serial.begin(9600);

    Serial.println("Internal EEPROM Command Interface Ready");
    Serial.println("Commands:");
    Serial.println("  read <address>");
    Serial.println("  write <address> <value>");
    Serial.println();
}

// --------------------------------------------------------------
// MAIN LOOP – read commands from Serial
// --------------------------------------------------------------
void loop()
{
    // Read the input string as a whole.
    while (Serial.available() > 0) {
        inputString = Serial.readString();// Get the whole Input String
      	Serial.print("Input: ");
      	Serial.println(inputString);
        inputString.trim(); // remove any leftover whitespace
        processCommand(inputString);
        inputString = ""; // reset for next command
    }
}

// --------------------------------------------------------------
// PROCESS COMMANDS
// --------------------------------------------------------------
void processCommand(String cmd)
{
    cmd.trim();

    int space1 = cmd.indexOf(' '); 
    if (space1 < 0)// Space must be at least after read or write
    {
        Serial.println("Invalid command.");
        return;
    }

    String action = cmd.substring(0, space1); // Divide input string for each space
    action.toLowerCase();

    // ---------------- READ ----------------
    if (action == "read")
    {
        unsigned int address = cmd.substring(space1 + 1).toInt();

        if (address >= EEPROM.length())// We should not be over bitwidth
        {
            Serial.println("Error: Address out of range.");
            return;
        }

        byte value = EEPROM.read(address);

        Serial.print("EEPROM[");
        Serial.print(address);
        Serial.print("] = ");
        Serial.println(value);
    }

    // ---------------- WRITE ----------------
    else if (action == "write")
    {
        int space2 = cmd.indexOf(' ', space1 + 1);
        if (space2 < 0)
        {
            Serial.println("Missing value.");
            return;
        }

        unsigned int address = cmd.substring(space1 + 1, space2).toInt();
        byte value = cmd.substring(space2 + 1).toInt();

        if (address >= EEPROM.length())
        {
            Serial.println("Error: Address out of range.");
            return;
        }
        if (value > 255)
        {
            Serial.println("Error: Value must be 0-255.");
            return;
        }

        EEPROM.write(address, value);

        Serial.print("Wrote ");
        Serial.print(value);
        Serial.print(" to EEPROM[");
        Serial.print(address);
        Serial.println("]");
    }

    else
    {
        Serial.println("Unknown command.");
    }
}
