#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
SoftwareSerial mySerial(3,4);//(Tx,Rx) 
///////////////
double sensorValue1 = 0;
int val1[100];
int max_v1 = 0;
double VmaxD1 = 0;
double VeffD1 = 0;
double Veff1 = 0;
int Voltage1 = 0;
/////////////////////////////////////////
double sensorValue2 = 0;
int val2[100];
int max_v2 = 0;
double VmaxD2 = 0;
double VeffD2 = 0;
double Veff2 = 0;
int Voltage2 = 0;
////////////////////////
double sensorValue3 = 0;
int val3[100];
int max_v3 = 0;
double VmaxD3 = 0;
double VeffD3 = 0;
double Veff3 = 0;
int Voltage3 = 0;
int flag=0;
/////////////////////////////////////
int relay1 =2;
int relay2 =3; 
int relay3 =4;
int green=5;
int red=6;
int buzzer=7;
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.init();
  lcd.init();
  lcd.backlight();
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("No fail");
  lcd.setCursor(0,1);
  lcd.print("detected");
  delay(5000);
}

void loop() {
    voltage1();
    voltage2();
    voltage3();
   if(Voltage1<180){
    fdetected();
    } else if(Voltage2<180&&flag==0){
    fdetected();
    flag=1;
    } else if(Voltage2<180&&flag==0){
    fdetected();
     flag=1;
    } else if(Voltage1<180){
       digitalWrite(relay1, LOW);
       }
        else if(Voltage2<180){
       digitalWrite(relay2, LOW);
       }
        else if(Voltage3<180){
       digitalWrite(relay3, LOW);
       }
       if(Voltage1>180){
    fdetected();
    } else if(Voltage2>180&&flag==0){
    fdetected();
    flag=1;
    } else if(Voltage2>180&&flag==0){
    fdetected();
     flag=1;
    } else if(Voltage1>180){
       digitalWrite(relay1, HIGH);
       }
        else if(Voltage2>180){
       digitalWrite(relay2, HIGH);
       }
        else if(Voltage3>180){
       digitalWrite(relay3, HIGH);
       }
    else{Serial.println("okoko");
     digitalWrite(relay1, HIGH);
     digitalWrite(relay2, HIGH);
     digitalWrite(relay3, HIGH);
     lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("No fail");
      lcd.setCursor(0,1);
      lcd.print("detected");
}
}
      void voltage1(){
        for ( int i = 0; i < 100; i++ ) {
            sensorValue1 = analogRead(A0);
        if (analogRead(A0) > 511) {
            val1[i] = sensorValue1;
        }
        else {
            val1[i] = 0;
        }
            delay(1);
        }
  max_v1 = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val1[i] > max_v1 )
    {
      max_v1 = val1[i];
    }
    val1[i] = 0;
  }
  if (max_v1 != 0) {
    VmaxD1 = max_v1;
    VeffD1 = VmaxD1 / sqrt(2);
    Veff1 = (((VeffD1 - 420.76) / -90.24) * -210.2);
     //Veff1 = (((VeffD1 - 420.76) / -90.24) * -210.2)+120 ;
  }
  else {
    Veff1 = 0;
  }
  VmaxD1 = 0;
  delay(400);
  if(Veff1<0){
    Voltage1=0;}
    else{
      Voltage1=Veff1+120;
      }
       Serial.print("Voltage1: ");
  Serial.println(Voltage1);}
//////////////////////////////
      void voltage2(){
        for ( int i = 0; i < 100; i++ ) {
    sensorValue2 = analogRead(A1);
    if (analogRead(A1) > 511) {
      val2[i] = sensorValue2;
    }
    else {
      val2[i] = 0;
    }
    delay(1);
  }

  max_v2 = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val2[i] > max_v2 )
    {
      max_v2 = val2[i];
    }
    val2[i] = 0;
  }
  if (max_v2 != 0) {
    VmaxD2 = max_v2;
    VeffD2 = VmaxD2 / sqrt(2);
    Veff2 = (((VeffD2 - 420.76) / -90.24) * -210.2);
    //Veff2 = (((VeffD2 - 420.76) / -90.24) * -210.2)+163;
  }
  else {
    Veff2 = 0;
  }

  VmaxD2 = 0;
  delay(400);
  if(Veff2<0){
    Voltage2=0;}
    else{
      Voltage2=Veff2+163;}
      Serial.print("Voltage2: ");
  Serial.println(Voltage2);
  //if(Voltage2<120){Serial.print("Voltage2nooo: ");}
  }
 //////////////////////////// 
  void voltage3(){
        for ( int i = 0; i < 100; i++ ) {
    sensorValue3 = analogRead(A2);
    if (analogRead(A2) > 511) {
      val3[i] = sensorValue3;
    }
    else {
      val3[i] = 0;
    }
    delay(1);
  }

  max_v3 = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val3[i] > max_v3 )
    {
      max_v3 = val3[i];
    }
    val3[i] = 0;
  }
  if (max_v3 != 0) {
    VmaxD3 = max_v3;
    VeffD3 = VmaxD3 / sqrt(2);
    Veff3 = (((VeffD3 - 420.76) / -90.24) * -210.2) ;
    //Veff3 = (((VeffD3 - 420.76) / -90.24) * -210.2) ;
  }

  else {
    Veff3 = 0;
  }

  VmaxD3 = 0;
  delay(400);
  if(Veff3<0){
    Voltage3=0;}
    else{
      Voltage3=Veff3+204;}
       Serial.print("Voltage3: ");
  Serial.println(Voltage3);}
      
    void fdetected()
{
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Fail detected");
    delay(1000);
}
