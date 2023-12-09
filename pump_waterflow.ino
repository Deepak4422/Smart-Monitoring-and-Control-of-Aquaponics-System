const int waterflow=12;
const int pump=13;
const float waterflowConst = 2.25;

void waterStart(){
  pinMode(waterlow,INPUT);
  pinMode(pump,OUTPUT);
  digitalWrite(pump,LOW);
  delay(100);
}

void water(int amount){
  int count=amount/2.25;
  bool state=digitalRead(waterflow);
  digitalWrite(pump,HIGH);
  while(count){
    if(digitalRead(waterflow)!=state){
      state=digitalRead(waterflow);
      count--;
    }
  }
  digitalWrite(pump,LOW);
}
