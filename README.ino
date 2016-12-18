#include<stdio.h> 
#define light_pin A0 
#define buzzer_pin 6 
boolean buzzer_speak; 
int light_data;//定义光敏变量 
int i = 20; 
void setup() { 
// put your setup code here, to run once: 
Serial.begin(115200);//设置波特率为115200 
pinMode(light_pin,INPUT);//定义引脚A0为输入模式 
pinMode(buzzer_pin,OUTPUT);//定义引脚 
} 
void loop() { 
// put your main code here, to run repeatedly: 
light_data=analogRead(light_pin); 
Serial.println(light_data); 
if(light_data<200) 
{ 
buzzer_speak = true;//蜂鸣器使能值为真，即开启蜂鸣器 
tone(buzzer_pin, i);//产生输出给压电扬声器的频率为i，前一个参数为连接到压电扬声器的数字引脚，后一个参数为以Hz为单位的频率值， 
//产生的声音一直持续直到输出一个不同的声音或使用noTone(pin)函数结束在指定引脚上产生的声音 
} 
else 
noTone(buzzer_pin);//tone（)产生的声音在此结束 
delay(100); 
} 
