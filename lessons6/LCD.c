#include <LiquidCrystal.h>
//LiquidCrystal lcd(rs, en, d4, d3, d2, d1);
//LiquidCrystal lcd(12, 11, 9, 8, 7, 6, 5, 4, 3, 2);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("ready to go, sir");
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("Please, type:   ");
  Serial.begin(9600);
}

String str;
void loop() {
  if(Serial.available()>0){
  	str = Serial.readString();
    if (str.length()<=16){
      lcd.setCursor(16-str.length(), 1);
      lcd.print(str);
    }
    
    else{
      for(int i=0;i<=str.length()-16;i++){
        lcd.setCursor(0,1);
        lcd.print(str.substring(i,i+16));
//        Serial.println(str.substring(i,i+16));
        delay(1000);
      }
    }
  }  
//  lcd.setCursor(2, 1);
//  lcd.print(Serial.available());
//  lcd.print(millis() / 1000);
  delay(100);
}
