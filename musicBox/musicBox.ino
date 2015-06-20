//#include "musicBox.h" //this is for our tones and is for reference. 
int knob = A4; 
int btn = 12; 

void setup() {
Serial.begin(57600); 
pinMode(knob, INPUT);	
pinMode(btn, INPUT_PULLUP);
}

void loop() {

	digitalWrite(knob, HIGH);
	int data = analogRead(knob);
	int btnState = digitalRead(btn);
	//Serial.println(btnState);
	data = map(data, 0, 1024, 65, 800);
	if(btnState==0)
	{
		int pauseBetweenNotes = 2 * 1.30;
		tone(8, data,500);
		delay(pauseBetweenNotes);
		Serial.println(data); 
		noTone(8);
	}else{
		noTone(8);
	}
}
