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
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
const int buttonPin = 10;
int buttonState = 0;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int i=0,j=0,m=0,x=0,s=0,k=0;
char newNum[12]="";
void setup()
{
Serial.begin(9600);
pinMode(buttonPin, INPUT);
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
lcd.print(".Press # to confirm..");
delay(3000);
}
void loop(){
    int key = keypad.getKey();
    if (key=='*') {
    lcd.clear();
    while(k==0){
    int key = keypad.getKey();
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      Serial.println("call=123");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Call send");
      delay(3000);
    }
    lcd.setCursor(0,0);
    lcd.print(" Select your order");
    lcd.setCursor(0,1);
    lcd.print("1. Bueff  = 1500 Rwf");
    lcd.setCursor(0,2);
    lcd.print("2. Rolex  = 2500 Rwf");
    lcd.setCursor(0,3);
    lcd.print("3. Coffe  = 1000 Rwf");
    if (key=='1') {
      Serial.println("order=Bueff&price=1500");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Your order send");
      delay(2000);
      }
    if (key=='2') {
    Serial.println("order=Rolex&price=2500");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Your order send");
    delay(2000);
    }
    if (key=='3') {
    Serial.println("order=Coffe&price=1000");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Your order send");
    delay(2000);
    }
}
}
}
