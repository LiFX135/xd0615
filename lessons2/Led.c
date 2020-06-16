int i;
void setup()
{
  for(i=8; i <= 13; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  for(i=13; i >= 8; i--){
    digitalWrite(i, HIGH);
    delay(i*i); 
    digitalWrite(i, LOW);
    delay(i*i);
  }
  for( ; i <= 13; i++){
    digitalWrite(i, HIGH);
    delay(i*i*2); 
    digitalWrite(i, LOW);
    delay(i*i*2);
  }
}