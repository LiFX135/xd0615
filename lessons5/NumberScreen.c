#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
void init_mine(){
  	digitalWrite(S1,LOW);
  	digitalWrite(S2,LOW);
 	digitalWrite(S3,LOW);
  	digitalWrite(S4,LOW);
    digitalWrite(IN1,0);
    digitalWrite(IN2,0);
    digitalWrite(IN3,0);
    digitalWrite(IN4,0);
    digitalWrite(S1,HIGH);
  	digitalWrite(S2,HIGH);
  	digitalWrite(S3,HIGH);
  	digitalWrite(S4,HIGH);
}

void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  
  Serial.begin(9600);

}

byte income=0;
int i,n,S,max;
String str,strl;

void loop()
{
  if(Serial.available()>0)
  {
	init_mine();
    str=Serial.readString();
    max = str.length();
    if (max<=4)
    {
      for(i=0;i<max;i++)
      {
        income = str[i];
        S = 12-max+i;
        income=income-'0';
        digitalWrite(S,LOW);
        digitalWrite(IN1,income&0x1);
        digitalWrite(IN2,(income>>1)&0x1);
        digitalWrite(IN3,(income>>2)&0x1);
        digitalWrite(IN4,(income>>3)&0x1);
        digitalWrite(S,HIGH);
        delay(500);
      }
    }
    
    else
    {
      for(n=0;n<max-3;n++)
      {
        strl = str.substring(n,n+4);
        for(i=0;i<4;i++)
        {
          income = strl[i];
          S = 8+i;
          income=income-'0';
          digitalWrite(S,LOW);
          digitalWrite(IN1,income&0x1);
          digitalWrite(IN2,(income>>1)&0x1);
          digitalWrite(IN3,(income>>2)&0x1);
          digitalWrite(IN4,(income>>3)&0x1);
          digitalWrite(S,HIGH);
          delay(500);
        }
      }
    }
  }
}