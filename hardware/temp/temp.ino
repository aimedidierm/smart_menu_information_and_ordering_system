#include <Ethernet.h>
#include <SPI.h>
#include <UbidotsEthernet.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); // Change to (0x27,20,4) for 20x4 LCD.
char const * TOKEN = "BBFF-6QW6O3Bozf4KDTEzeI9kWPWkqUynkb"; // Assign your Ubidots
TOKEN
char const * VARIABLE_LABEL_1 = "menu"; // Assign the unique variable label to send the data
char const * VARIABLE_LABEL_2 = "humidity"; // Assign the unique variable label to send the data
char const * VARIABLE_LABEL_3 = "pressure"; // Assign the unique variable label to send the data
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
Ubidots client(TOKEN);
long str;
long h,h1,h2,h3,h4,h5,h6,h7,h8,f;
//Keymap for 4x4 Keypad
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
char keymap[numRows][numCols]=
{
{'1', '4', '7', '*'},
{'2', '5', '8', '0'},
{'3', '6', '9', 'C'},
{'A', 'B', 'C', 'D'}};
char keypressed;
//Where the keys are stored it changes very often
char code[]= {'1','0','2'}; //The default code, you can change it or make it a 'n' digits one
char code_buff1[sizeof(code)]; //Where the new key is stored - sizeof function gives the size of the
character array
char code_buff2[sizeof(code)]; //Where the new key is stored again so it's compared to the previous one
char code1[]= {'1','0','0','3'}; //The default code, you can change it or make it a 'n' digits one
char code_buff3[sizeof(code1)]; //Where the new key is stored - sizeof function gives the size of the
character array
char code_buff4[sizeof(code1)]; //Where the new key is stored again so it's compared to the previous one
char code2[]= {'0','2','0','0','3'}; //The default code, you can change it or make it a 'n' digits one
char code_buff5[sizeof(code2)]; //Where the new key is stored - sizeof function gives the size of the
character array
char code_buff6[sizeof(code2)]; //Where the new key is stored again so it's compared to the previous one
char code3[]= {'1','0','2','0','0','3'}; //The default code, you can change it or make it a 'n' digits one
char code_buff7[sizeof(code3)]; //Where the new key is stored - sizeof function gives the size of the
character array
char code_buff8[sizeof(code3)]; //Where the new key is stored again so it's compared to the previous
one*/
char code4[]= {'1','0','1','1','0','0','2'}; //The default code, you can change it or make it a 'n' digits one
char code_buff9[sizeof(code4)]; //Where the new key is stored - sizeof function gives the size of the
character array
char code_buff10[sizeof(code4)]; //Where the new key is stored again so it's compared to the previous
one
char code5[]= {'1','0','1','1','0','0','0','3'}; //The default code, you can change it or make it a 'n' digits one
char code_buff11[sizeof(code5)]; //Where the new key is stored - sizeof function gives the size of the
character array
char code_buff12[sizeof(code5)]; //Where the new key is stored again so it's compared to the previous
one
char code6[]= {'1','0','0','2','1','0','0','0','3'}; //The default code, you can change it or make it a 'n' digits one
char code_buff13[sizeof(code6)]; //Where the new key is stored - sizeof function gives the size of the
character array
char code_buff14[sizeof(code6)]; //Where the new key is stored again so it's compared to the previous
onechar code7[]= {'1','0','1','1','0','0','2','1','0','0','0','3'}; //The default code, you can change it or make it a 'n'
digits one
char code_buff15[sizeof(code7)]; //Where the new key is stored - sizeof function gives the size of the
character array
char code_buff16[sizeof(code7)]; //Where the new key is stored again so it's compared to the previous
one*/
int a=0,i=0,s=0,j=0;
//Variables used later
byte rowPins[numRows] = {22,24,26,28}; //Rows 0 to 3 //if you modify your pins you should modify this
too
byte colPins[numCols]= {30,32,34,36}; //Columns 0 to 3
int access=0;
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
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
Serial.print(F("Starting ethernet..."));
if (!Ethernet.begin(mac)) {
Serial.println(F("failed"));
} else {Serial.println(Ethernet.localIP());
}
/* Give the Ethernet shield a second to initialize */
delay(1000);
Serial.println(F("Ready"));
}
void loop()
{
Ethernet.maintain();
keypressed = myKeypad.getKey();
yield();//Constantly waiting for a key to be pressed
if(keypressed == '*'){
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" Table 1 Table 2");
lcd.setCursor(0,1);
lcd.print("1. Rice 101. Rice");
lcd.setCursor(0,2);
lcd.print("02. Bean 1002. Bean");
lcd.setCursor(0,3);
lcd.print("003.Egg 10003.Egg");
GetCode(); //Getting code function
yield();
if(a==sizeof(code))
the size of the code array)
{ //The GetCode function assign a value to a (it's correct when it has
client.add(VARIABLE_LABEL_1, 1);
client.sendAll();
delay(1000);
menu(); access=0;yield();//Open lock function if code is correct
}
else if(a==sizeof(code1))
it has the size of the code array)
{ //The GetCode function assign a value to a (it's correct when
client.add(VARIABLE_LABEL_1, 2);
client.sendAll();
delay(1000);
menu1(); access=0;
yield();//Open lock function if code is correct
}
else if(a==sizeof(code2))
it has the size of the code array)
{ //The GetCode function assign a value to a (it's correct when
client.add(VARIABLE_LABEL_1,3);
client.sendAll();
delay(1000);
menu2(); access=0;
yield();//Open lock function if code is correct
}
if(a==sizeof(code3))
has the size of the code array)
{ //The GetCode function assign a value to a (it's correct when it
client.add(VARIABLE_LABEL_1,4);
client.sendAll();
delay(1000);
menu3(); access=0;
yield();//Open lock function if code is correct
}
else if(a==sizeof(code4)){
client.add(VARIABLE_LABEL_1,5);
client.sendAll();
delay(1000);menu4(); access=0;
yield();//Open lock function if code is correct
}
else if(a==sizeof(code5))
it has the size of the code array)
{ //The GetCode function assign a value to a (it's correct when
client.add(VARIABLE_LABEL_1, 6);
client.sendAll();
delay(1000);
menu5(); access=0;
yield();//Open lock function if code is correct
}
else if(a==sizeof(code6))
it has the size of the code array)
{ //The GetCode function assign a value to a (it's correct when
client.add(VARIABLE_LABEL_1, 7);
client.sendAll();
delay(1000);
menu6(); access=0;
yield();//Open lock function if code is correct
}
else if(a==sizeof(code7))
it has the size of the code array)
{ //The GetCode function assign a value to a (it's correct when
client.add(VARIABLE_LABEL_1, 8);
client.sendAll();
delay(1000);
menu7(); access=0;
yield();//Open lock function if code is correct
}
else if(f==20)
size of the code array)
{ //The GetCode function assign a value to a (it's correct when it has the
client.add(VARIABLE_LABEL_1, 0);
client.sendAll();delay(1000);
menu8(); yield();//Open lock function if code is correct
}
else{
access=access+1;
Serial.println("No requested menu");
}
yield();
delay(1000);
Serial.println("Wainting"); //Return to Wainting mode it's the message do display when waiting
yield();
}}
void GetCode(){ //Getting code sequence
//Ethernet.maintain();
i=0;
//All variables set to 0
a=0;
while(keypressed != 'A'){
can keep typing
//The user press A to confirm the code otherwise he
keypressed = myKeypad.getKey();
if(keypressed != NO_KEY && keypressed != 'A' ){
"nothing"
lcd.clear();
lcd.setCursor(0,0);
lcd.print(keypressed);
lcd.print("
T1
T2");
lcd.setCursor(0,1);
lcd.print("1. Rice 101. Rice");
lcd.setCursor(0,2);
lcd.print("02. Bean 1002. Bean");
lcd.setCursor(0,3);
lcd.print("003.Egg 10003.Egg");
//If the char typed isn't A and neitherif(keypressed == code[i]&& i<sizeof(code)){
increments to verify the next caracter
//if the char typed is correct a and i
a++;
i++;
}
else if(keypressed == code1[i]&& i<sizeof(code1)){
increments to verify the next caracter
//if the char typed is correct a and i
a++;
i++;
}
else if(keypressed == code2[i]&& i<sizeof(code2)){
increments to verify the next caracter
//if the char typed is correct a and i
a++;
i++;
}
else if(keypressed == code3[i]&& i<sizeof(code3)){
increments to verify the next caracter
//if the char typed is correct a and i
a++;
i++;
}
else if(keypressed == code4[i]&& i<sizeof(code4)){
increments to verify the next caracter
//if the char typed is correct a and i
a++;
i++;
}
else if(keypressed == code5[i]&& i<sizeof(code5)){
increments to verify the next caracter
//if the char typed is correct a and i
a++;
i++;
}
else if(keypressed == code6[i]&& i<sizeof(code6)){
increments to verify the next caracter
//if the char typed is correct a and ia++;
i++;
}
else if(keypressed == code7[i]&& i<sizeof(code7)){
increments to verify the next caracter
//if the char typed is correct a and i
a++;
i++;
}
else if(keypressed != code[i]||keypressed != code1[i]||keypressed != code2[i]||keypressed !=
code3[i]||keypressed != code4[i]||keypressed != code5[i]||keypressed != code6[i]||keypressed != code7[i]){
//if the char typed is correct a and i increments to verify the next caracter
f=20;
}
else
a--;
the size of code []
//if the character typed is wrong a decrements and cannot equal
}
yield();
}
Serial.println();
keypressed = NO_KEY;
yield();
}
void menu(){
/*Serial.println("I need rice and beans on table 1.");
client.add(VARIABLE_LABEL_1, 1);
client.sendAll();*/
h=102;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("....Thank you!!!....");lcd.setCursor(0,1);
lcd.print("..Please, Wait on...");
lcd.setCursor(0,2);
lcd.print("......Table 1.......");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");
lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
//str =String("Menu request: I need rice and beans on table 1. ")+String(" H= ")+String(h);
str =h;
}
void menu1(){
Serial.println("I need rice and Egg on table 1.");
lcd.clear();
lcd.print("....Thank you!!!....");
lcd.setCursor(0,1);
lcd.print("..Please, Wait on...");
lcd.setCursor(0,2);
lcd.print("......Table 1.......");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");
lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
h1=1003;
//str =String("Menu request: I need rice and Egg on table 1. ")+String("H= ")+String(h1);
client.add(VARIABLE_LABEL_1, 2);
client.sendAll();
delay(5000);
}
void menu2(){
Serial.println("I need beans and Egg on table 1.");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("....Thank you!!!....");
lcd.setCursor(0,1);
lcd.print("..Please, Wait on...");
lcd.setCursor(0,2);
lcd.print("......Table 1.......");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
h2=02003;
//str =String("Menu request: I need beans and Egg on table 1. ")+String("H= ")+String(h2);
client.add(VARIABLE_LABEL_1, 3);
client.sendAll();
delay(5000);
}
void menu3(){
Serial.println("I need rice, beans and Egg on table 1.");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("....Thank you!!!....");
lcd.setCursor(0,1);
lcd.print("..Please, Wait on...");
lcd.setCursor(0,2);
lcd.print("......Table 1.......");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");
lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
h3=102003;
//str =String("Menu request: I need rice, beans and Egg on table 1.")+String("H= ")+String(h3);
client.add(VARIABLE_LABEL_1, 4);client.sendAll();
delay(5000);
}
void menu4(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("....Thank you!!!....");
lcd.setCursor(0,1);
lcd.print("..Please, Wait on...");
lcd.setCursor(0,2);
lcd.print("......Table 2.......");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");
lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
h4=1011002;
client.add(VARIABLE_LABEL_1, 5);
client.sendAll();
delay(5000);
}
void menu5(){
Serial.println("I need rice and Egg on table 2.");
lcd.clear();
lcd.setCursor(0,0);lcd.print("....Thank you!!!....");
lcd.setCursor(0,1);
lcd.print("..Please, Wait on...");
lcd.setCursor(0,2);
lcd.print("......Table 2.......");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");
lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
h5=10110003;
client.add(VARIABLE_LABEL_1, h5);
client.sendAll();
delay(5000);
}
void menu6(){
Serial.println("I need beans and Egg on table 2.");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("....Thank you!!!....");
lcd.setCursor(0,1);
lcd.print("..Please, Wait on...");
lcd.setCursor(0,2);
lcd.print("......Table 2.......");
delay(5000);lcd.clear();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");
lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
h6=100210003;
client.add(VARIABLE_LABEL_1, h6);
client.sendAll();
delay(5000);
}
void menu7(){
Serial.println("I need rice, beans and Egg on table 2.");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("....Thank you!!!....");
lcd.setCursor(0,1);
lcd.print("..Please, Wait on...");
lcd.setCursor(0,2);
lcd.print("......Table 2.......");
delay(5000);
lcd.clear();
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
h7=101100210003;
client.add(VARIABLE_LABEL_1, h7);
client.sendAll();
delay(5000);
}
void menu8(){
Serial.println("No menu requested");
lcd.setCursor(0,0);
lcd.clear();
lcd.print("..Menu not found...");
lcd.setCursor(0,1);
lcd.print("......Please!......");
lcd.setCursor(0,2);
lcd.print(".....Try again.....");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(".WELCOME TO A RESTO.");
lcd.setCursor(0,1);
lcd.print("..Press* to choose...");
lcd.setCursor(0,2);
lcd.print("......your menu......");
lcd.setCursor(0,3);
lcd.print(".Press A to confirm..");
h8=00000;
client.add(VARIABLE_LABEL_1, h8);
client.sendAll();delay(5000);
}