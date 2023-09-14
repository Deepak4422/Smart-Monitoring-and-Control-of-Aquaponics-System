const int shakerMotor=10;
const int screwMotor=9;
const int Na=0
const int Ni=0
const int Am=0


void motorsStart(){
  pinMode(shakerMotor,OUTPUT);
  pinMode(screwMotor,OUTPUT);
}

void shake(int Time){
  digitalWrite(shakerMotor,HIGH);
  delay(Time);
  digitalWrite(shakerMotor,LOW);
}

void screw(String test){
 if(test=="nitrate"){
  digitalWrite(screwMotor,HIGH);
  int steps=Na,stepCount=0;
   while(steps<stepCount){
    if(digitalRead(encoder)==HIGH)
      stepCount++;
   }
   digitalWrite(screwMotor,LOW);
 }
 
 else if(test=="nitrite"){
  digitalWrite(screwMotor,HIGH);
  int steps=Ni,stepCount=0;
   while(steps<stepCount){
    if(digitalRead(encoder)==HIGH)
      stepCount++;
   }
   digitalWrite(screwMotor,LOW);
 }
 

 else if(test=="ammonia"){
  digitalWrite(screwMotor,HIGH);
  int steps=Am,stepCount=0;
   while(steps<stepCount){
    if(digitalRead(encoder)==HIGH)
      stepCount++;
   }
   digitalWrite(screwMotor,LOW);
 }
}
