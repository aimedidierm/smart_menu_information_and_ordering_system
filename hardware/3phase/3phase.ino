#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
SoftwareSerial mySerial(3,4);//(Tx,Rx) 
double sensorValue1 = 0;
double sensorValue2 = 0;
double sensorValue3 = 0;
int crosscount = 0;
int climb_flag = 0;
int val[100];
int max_v = 0;
double VmaxD = 0;
double VeffD = 0;
double Veff = 0;
double V1 = 0,V2 = 0,V3 = 0;
int flag=0;
int relay1 =2;
int relay2 =3; 
int relay3 =4;
int green=5;
int red=6;
int buzzer=7;
void setup() {
  Serial.begin(9600);
}

void loop() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  if(V1<180&&flag==0){
    fdetected();
}
        else if(V2<180&&flag==0){
    fdetected();
     flag=1;}
        else if(V3<180&&flag==0){
    fdetected();
     flag=1;}
     else if(V1<180){
       digitalWrite(relay1,LOW);}
        else if(V2<180){
       digitalWrite(relay2,LOW);}
        else if(V3<180){
       digitalWrite(relay3,LOW);}
     
    else{Serial.println("okoko");
    lcd.clear();
     lcd.setCursor(0,0);
      lcd.print("No fail");
      lcd.setCursor(0,1);
      lcd.print("detected");
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
     }
}
void voltagec(){
  for ( int i = 0; i < 100; i++ ) {
    sensorValue1 = analogRead(A0);
    if (analogRead(A0) > 511) {
      val[i] = sensorValue1;
    }
    else {
      val[i] = 0;
    }
    delay(1);
  }

  max_v = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val[i] > max_v )
    {
      max_v = val[i];
    }
    val[i] = 0;
  }
  if (max_v != 0) {


    VmaxD = max_v;
    VeffD = VmaxD / sqrt(2);
    Veff = (((VeffD - 420.76) / -90.24) * -210.2) + 210.2;
  }
  else {
    Veff = 0;
  }
  Serial.print("Voltage1: ");
  V1=Veff;
  Serial.println(V1);
  VmaxD = 0;
  //v1
  for ( int i = 0; i < 100; i++ ) {
    sensorValue2 = analogRead(A1);
    if (analogRead(A1) > 511) {
      val[i] = sensorValue2;
    }
    else {
      val[i] = 0;
    }
    delay(1);
  }

  max_v = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val[i] > max_v )
    {
      max_v = val[i];
    }
    val[i] = 0;
  }
  if (max_v != 0) {


    VmaxD = max_v;
    VeffD = VmaxD / sqrt(2);
    Veff = (((VeffD - 420.76) / -90.24) * -210.2) + 210.2;
  }
  else {
    Veff = 0;
  }
  Serial.print("Voltage2: ");
  V2=Veff;
  Serial.println(V2);
  VmaxD = 0;
  //v1
  for ( int i = 0; i < 100; i++ ) {
    sensorValue3 = analogRead(A2);
    if (analogRead(A2) > 511) {
      val[i] = sensorValue3;
    }
    else {
      val[i] = 0;
    }
    delay(1);
  }

  max_v = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val[i] > max_v )
    {
      max_v = val[i];
    }
    val[i] = 0;
  }
  if (max_v != 0) {


    VmaxD = max_v;
    VeffD = VmaxD / sqrt(2);
    Veff = (((VeffD - 420.76) / -90.24) * -210.2) + 210.2;
  }
  else {
    Veff = 0;
  }
  Serial.print("Voltage3: ");
  V3=Veff;
  Serial.println(V3);
  VmaxD = 0;

  delay(100);
  }
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
    lcd.print("Line fail");
    lcd.setCursor(0,1);
    lcd.print("detected");
    delay(1000);
}
