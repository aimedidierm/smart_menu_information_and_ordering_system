#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {

    {'1','2','3','A'},

    {'4','5','6','B'},

    {'7','8','9','C'},

    {'*','0','#','D'}

};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, A0,A1}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup()
{
Serial.begin(9600);
lcd.begin(20,4);
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");
lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
delay(3000);
}
void loop(){
    int key = keypad.getKey();
    if (key=='*') {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Select what you want");
    lcd.setCursor(0,1);
    lcd.print("1. Rice 4. Banana");
    lcd.setCursor(0,2);
    lcd.print("2. Beans 5. Chipps");
    lcd.setCursor(0,3);
    lcd.print("3.Egg 6. Apple");
    delay(2000);
  }
}
