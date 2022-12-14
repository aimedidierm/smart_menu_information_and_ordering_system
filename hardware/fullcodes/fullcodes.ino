#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {

    {'1','2','3'},

    {'4','5','6'},

    {'7','8','9'},

    {'*','0','#'}

};

byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int i=0,j=0,m=0,x=0,s=0,k=0;
char newNum[12]="";
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
lcd.print(".Press # to confirm..");
delay(3000);
lcd.clear();
}
void loop(){
    int key = keypad.getKey();
    //if (key=='*') {
    lcd.setCursor(0,0);
    lcd.print(" Select your order");
    lcd.setCursor(0,1);
    lcd.print("1. Rice   4. Banana");
    lcd.setCursor(0,2);
    lcd.print("2. Beans  5. Chipps");
        if (key!=NO_KEY && key!='#' && key!='*'){
            newNum[j] = key;
            newNum[j+1]='\0';   
            j++;
            lcd.setCursor(0,3);
            lcd.print(newNum);
        }
        if (key=='#'&& j>0){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(" Your order send");
          delay(3000);
          }
    delay(500);
  //}
}
