/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.

  OPEN THE SERIAL MONITOR TO VIEW THE OUTPUT >> 
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/


// the setup routine runs once when you press reset:
void setup() {
  // 初始化串口——9600比特每秒:
  Serial.begin(9600);
}

// 主循环
void loop() {
  // 设置模拟pin-A0为读取:
  int sensorValue = analogRead(A0);
  // 将模拟信号读数(0 - 1023)转化成电压伏特数(0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // 串口打印电压读数:
  Serial.println(voltage);
}