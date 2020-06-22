#include <MsTimer2.h>
int d1 = 8;
int d2 = 9;
int d3 = 10;
int d4 = 11;
int lock = 5;
int blank = 6;
int test = 7;
int pinInterrupt = 2;
byte t = 0;

void Clear(){
   if ( digitalRead(pinInterrupt) == LOW )
      t = 0;
}


void tick(){
  digitalWrite(lock,LOW);
  digitalWrite(d1,t&0x1);
  digitalWrite(d2,(t>>1)&0x1);
  digitalWrite(d3,(t>>2)&0x1);
  digitalWrite(d4,(t>>3)&0x1);
  digitalWrite(lock,HIGH);
  t++;
  
  if(t==10)
    t = 0;
}
  
 
void setup()
{
  pinMode( pinInterrupt, INPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(lock, OUTPUT);
  pinMode(blank, OUTPUT);
  pinMode(test, OUTPUT);
  digitalWrite(test,HIGH);
  digitalWrite(blank,HIGH);
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), Clear, CHANGE);
  MsTimer2::set(1000, tick);
  MsTimer2::start();
}
 
void loop()
{
//  digitalWrite(lock,LOW);
//  digitalWrite(d1,t&0x1);
//  digitalWrite(d2,(t>>1)&0x1);
//  digitalWrite(d3,(t>>2)&0x1);
//  digitalWrite(d4,(t>>3)&0x1);
//  digitalWrite(lock,HIGH);
//  t++;
  
//  if(t==10)
//    t = 0;
}
