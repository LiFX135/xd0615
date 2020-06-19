char ch='s';
void setup()
{
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready");
}

/*
f:前进
b:后退
r:右转
l:左转
s:停止
*/
void loop()
{
  if(Serial.available()>0)
  {
  	ch=Serial.read();
    switch(ch)
    {
    case 'f':
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      break;
    case 'b':
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      break;
    case 'r':
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      break;
    case 'l':
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      break;
    case 's':
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      break;
    default:
      break;
    }
  }
}
