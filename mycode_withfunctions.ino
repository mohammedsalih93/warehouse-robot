#define m1 4  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 2  //Left Motor MB1
#define m4 3  //Left Motor MB2
#define e1 9  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define near1 A2
#define ir4 A3
#define ir5 A4
#define ir3 A5
//*************************************************//
 
  



void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(near1,INPUT);
  

}

void loop() {
  if(digitalRead(near1)==0){
    control();
  }
  else{
    stop();
  }
  
}


void control(){
  if((digitalRead(ir1)==1)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==1)){
    forward();
  }
  if((digitalRead(ir1)==1)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==1)){
  right();

  }
  if((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==1)){
  right90();
  }
  if((digitalRead(ir1)==0)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==1)){
  right90();
  }
  if((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==1)){
  right90();
  }
  if((digitalRead(ir1)==1)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==0)&&(digitalRead(ir5)==1)){
    left();
  }
  if((digitalRead(ir1)==1)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==0)&&(digitalRead(ir5)==0)){
    left90();
    
  }
  if((digitalRead(ir1)==1)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==0)){
    left90();
  }
  if((digitalRead(ir1)==1)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==0)&&(digitalRead(ir5)==0)){
    left90();
  }
  if(((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==0)&&(digitalRead(ir5)==0))||((digitalRead(ir1)==1)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==1)))
  
    {
    stop();
  }
}


void turnback()
  {
    //going left with full speed 
    analogWrite(e1, 150); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 150); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    
    
  }
  void stop()
  
    {
    //stop
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  //void reading()
  
     //Reading Sensor Values
  //int s1 = digitalRead(ir1);  //Left Most Sensor
 /* int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor
  int near= digitalRead(near1); //opstical detection sensor
  }*/
  void forward()
  {
    //going forward with full speed 
    analogWrite(e1, 120); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 120); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  void right()
  {
     //going right with full speed 
    analogWrite(e1, 120); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 120); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  void right90()
  {
    //going right90 with full speed 
    analogWrite(e1, 120); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 120); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);

  }
  void left()
  {
    //going left with full speed 
    analogWrite(e1, 120); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 120); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);

  }
  void left90()
  {
    //going left90 with full speed 
    analogWrite(e1, 120); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 120); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);

  }
  