void setup(){
}

// Code to sound a piezo buzzer connected to pin 8 at two different frequencies
void loop(){
	tone(8, 988, 1000); // Pin 8, 988 Hz for 1 second
	delay(1000);
	tone(8, 1047, 1000);
	delay(1000);

}