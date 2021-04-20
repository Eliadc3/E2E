 /*
 Name:		ControlledBlink.ino
 Created:	3/16/2021 5:15:01 PM
 Author:	Eliad
*/
#define BtnPin_Red 6
#define BtnPin_Blue 9
#define BtnPin_Yellow 10
#define BtnPin_Green 11

#define LedPin_Red 3
#define LedPin_Blue 2
#define LedPin_Yellow 4
#define LedPin_Green 12

#define potzPin A0

int prd = 200;
// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LedPin_Green, OUTPUT);
	pinMode(LedPin_Blue, OUTPUT);
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	int rotation = analogRead(potzPin);
	int LedVal = map(rotation, 0, 1023, 0, 255);
	prd = map(rotation, 0, 1023, 600, 200);
	//Serial.println(rotation);

	analogWrite(LedPin_Blue, LedVal);

	digitalWrite(LedPin_Green, HIGH);
	delay(prd);
	digitalWrite(LedPin_Green, LOW);
	delay(prd);
  
}
