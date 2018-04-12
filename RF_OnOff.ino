//Author: Konrad Polys

#include <RCSwitch.h> // Lib from: https://rc-switch.googlecode.com/files/RCSwitch.zip
#define ON 5891 // on 5314307
#define OFF 5900 // off 5314316
#define INR 0 // pin 2
#define LED 13
#define BUZ 10

#define DEBUG

RCSwitch mySwitch = RCSwitch();

void setup() 
{
	mySwitch.enableReceive(INR);  
	#ifdef DEBUG
		Serial.begin(9600);
		Serial.println("Start");
		digitalWrite(BUZ, HIGH);
		delay(500);
		digitalWrite(BUZ, LOW);
	#endif
}

void loop() 
{
	if (mySwitch.available()) 
	{
		int value = mySwitch.getReceivedValue();
		if (value != 0) 
		{
			if (value == ON)
			{
				digitalWrite(BUZ, HIGH);
				digitalWrite(LED, HIGH);
				#ifdef DEBUG
					Serial.print("HIGH! ");
				#endif
			}

			if (value == OFF)
			{
				digitalWrite(BUZ, LOW);
				digitalWrite(LED, LOW);
				#ifdef DEBUG
					Serial.print("low ");
				#endif
			}	
		}
		mySwitch.resetAvailable();
	}
}


