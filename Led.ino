#include <string.h>;
#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9
String str;
int r = 0;
int g = 0;
int b = 0;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(!Serial.available()){}
  str = Serial.readString();
  if(str.substring(0,1).equals("c")){
    digitalWrite(13,HIGH);
    r = str.substring(1,str.indexOf(",")).toInt();
    g = str.substring(str.indexOf(",")+1,str.lastIndexOf(",")).toInt();
    b = str.substring(str.lastIndexOf(",")+1).toInt();
    analogWrite(RED_LED,r);
    analogWrite(GREEN_LED,g);
    analogWrite(BLUE_LED,b);
  }else if(str.equals("o")){
    if(r == 0 && g == 0 && b == 0){
      analogWrite(RED_LED,255);
      analogWrite(GREEN_LED,255);
      analogWrite(BLUE_LED,255);
    }else{
      analogWrite(RED_LED,r);
      analogWrite(GREEN_LED,g);
      analogWrite(BLUE_LED,b);
    }
  }else if(str.equals("f")){
    analogWrite(RED_LED,0);
    analogWrite(GREEN_LED,0);
    analogWrite(BLUE_LED,0);
  }
  
}


