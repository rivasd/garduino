#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//The setup function is called once at startup of the sketch

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //creation de l'objet qui permet de communiquer avec l'ecran LCD


const int pump	=	2; //numero de la pin ou brancher la pompe
const int humid	=	0; //numero de la pin ou brancher le senseur d'humidite
const int bouton	= 7; //numero de la pin ou est connecte le bouton
const int senseurOn	= 3; //numero de la pin qui allume le senseur dhumidite

void setup()
{
// Add your initialization code here
	pinMode(bouton, INPUT_PULLUP);
	pinMode(3, OUTPUT);
	pinMode(0, INPUT);

	lcd.begin(16, 2);
	lcd.home();
	lcd.print(" Bienvenue ");
	//lcd.setCursor(1,0);
	lcd.print(" au Jarduino! ");
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	//lcd.print("hey!");
	if(!digitalRead(bouton)){
		lcd.display();
		lcd.on();
		digitalWrite(senseurOn, HIGH);
		lcd.clear();
		lcd.print("humidite: ");
		lcd.print(analogRead(humid), DEC);
		delay(500);
	}
	else{
		digitalWrite(senseurOn, LOW);
		lcd.clear();
		lcd.noDisplay();
		lcd.off();
	}

}
