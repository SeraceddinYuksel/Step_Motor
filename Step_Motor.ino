#include <LiquidCrystal_I2C.h>

#include <Wire.h>

// defines pins numbers


LiquidCrystal_I2C lcd(0x27,16,2);

const int stepPin = 4; 
const int dirPin = 2; 
const int limitPin = 8;
const int butonPin = 10;
const int tusPin = 12;
int sabit = 0;
int stepcount = 0;

void baslama()
{
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1500); 
}
void durdurma()
{
     digitalWrite(stepPin,LOW);
     delay(100);}
 void dortileriucgeri()
{
     digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
   // Makes 200 pulses for making one full cycle rotation
   for(int x = 0; x < 300; x++) {
 digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1400); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1400); 
  }
   delay(300); // One second delay

   digitalWrite(dirPin,LOW); //Changes the rotations direction
   // Makes 400 pulses for making two full cycle rotation
   for(int x = 0; x < 250; x++) {
  digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1400); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1400); 
  }
   delay(300);
  
}
void ucileriucgeri()
{
     digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
   // Makes 200 pulses for making one full cycle rotation
   for(int x = 0; x < 250; x++) {
   digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1400); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1400); 
  }
   delay(300); // One second delay

   digitalWrite(dirPin,LOW); //Changes the rotations direction
   // Makes 400 pulses for making two full cycle rotation
   for(int x = 0; x < 250; x++) {
 digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1400); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1400); 
  }
   delay(300);
  
}


void setup() {
  Serial.begin(9600);
  
  pinMode(limitPin,INPUT);
  pinMode(butonPin,INPUT);
  pinMode(tusPin,INPUT);
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  digitalWrite(dirPin,LOW);
  
  lcd.init();
  lcd.setCursor(0,0);
  lcd.print("calistirilabilir");
  
}


void loop() 
{
  
 
 if( digitalRead(butonPin)== LOW )
 {
 if(digitalRead(limitPin) == HIGH && sabit == 0 )
 {
 baslama();
 }
 else if( digitalRead(limitPin) == LOW && digitalRead(tusPin) == HIGH && sabit == 0 )
 {
  lcd.clear();
  durdurma();
 sabit = 1 ;
 delay(100);
 }
 else if( digitalRead(limitPin) == LOW && digitalRead(tusPin)== LOW && sabit == 1 )
 {
  lcd.setCursor(4,0);
  lcd.print("Adim:");
  dortileriucgeri();
  delay(100);   
 }
  else if( digitalRead(limitPin) == HIGH && digitalRead(tusPin)== LOW && sabit == 1)
 {
   stepcount++;
   lcd.setCursor(9,0);
   lcd.print(stepcount);
   ucileriucgeri();   
 }
 else if( digitalRead(limitPin) == HIGH && digitalRead(tusPin)== HIGH && sabit == 1)
  {
   durdurma(); 

  }
 
 }

 
 
 else if( digitalRead(butonPin)== HIGH  )
 {
  stepcount = 0;
  durdurma();
  sabit = 0 ;
  lcd.clear();
 }
 
}
  
