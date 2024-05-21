#define cap1 34
#define cap2 35
#include <Ultrasonic.h>
Ultrasonic ultrasonic(14, 15);
Ultrasonic ultrasonic2(16, 17);
int threshold = 75;
#define in1 2
#define in2 3 
#define in3 4 
#define in4 5

#define in11 9
#define in12 10
#define in13 11
#define in14 12

void moveforward(){
  Serial.println("Forward");
  digitalWrite(in1,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in11,HIGH);
  digitalWrite(in14,HIGH);
  }
  void movebackward(){
  Serial.println("Backward");
  digitalWrite(in3,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in13,HIGH);
  digitalWrite(in12,HIGH);
  }

  void stop(){
        Serial.println("Stop");
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        digitalWrite(in11,LOW);
        digitalWrite(in12,LOW);
        digitalWrite(in13,LOW);
        digitalWrite(in14,LOW);
        }
void setup() {
  Serial.begin(115200);
pinMode(cap1,INPUT);
pinMode(cap2,INPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(in11,OUTPUT);
pinMode(in12,OUTPUT);
pinMode(in13,OUTPUT);
pinMode(in14,OUTPUT);

}

void forward(){
  int distance = ultrasonic2.read();
  Serial.print("Distance");
Serial.println(distance);
  while(distance>threshold){
    moveforward();
    Serial.print("Distance");
Serial.println(distance);
distance = ultrasonic2.read();
delay(100);
  }
  stop();
}


void backward(){
  int distance = ultrasonic.read();
  Serial.print("Distance");
  Serial.println(distance);
  while(distance>threshold){
    movebackward();
    Serial.print("Distance");
Serial.println(distance);
distance = ultrasonic.read();
delay(100);
  }
  stop();
}

void loop() {
int val1 = digitalRead(cap1);
Serial.print("Val1");
Serial.println(val1);
if(val1 == 1){
  forward();
  delay(50);
}
int val2 = digitalRead(cap2);
Serial.print("Val2");
Serial.println(val2);
if(val2 == 1){
  backward();
  delay(50);
}
delay(50);
}
