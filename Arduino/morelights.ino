#define d3 3
#define d4 4
#define d5 5
#define d6 6
void setup()
{
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(d5, OUTPUT);
  pinMode(d6, OUTPUT);
  Serial.begin(19200);
}
void l1(int time)
{
  Serial.println("l1-");
  digitalWrite(d6,LOW);
  digitalWrite(d3,LOW);
    digitalWrite(d4,HIGH);
    digitalWrite(d5,HIGH);
    delay(time);
}
void l2(int time)
{
  Serial.println("l2-");
  digitalWrite(d6,LOW);
    digitalWrite(d4,LOW);
    digitalWrite(d3,HIGH);
    digitalWrite(d5,HIGH);
    
    delay(time);
}
void l3(int time)
{
  Serial.println("l3-");
    digitalWrite(d5,LOW);
    digitalWrite(d3,LOW);
    digitalWrite(d4,HIGH);
    digitalWrite(d6,HIGH);
    delay(time);
}
void l4(int time)
{
  Serial.println("l4-");
  digitalWrite(d5,LOW);
  digitalWrite(d4,LOW);
  digitalWrite(d3,HIGH);
  digitalWrite(d6,HIGH);
    delay(time);
}
void l12(int time)
{
  Serial.println("l12-");
    digitalWrite(d6,LOW);
    digitalWrite(d3,LOW);
    digitalWrite(d4,LOW);
    digitalWrite(d5,HIGH);
    delay(time);
}
void l34(int time)
{
  Serial.println("l13-");
    digitalWrite(d5,LOW);
    digitalWrite(d3,LOW);
    digitalWrite(d4,LOW);
    digitalWrite(d6,HIGH);
    delay(time);
}
void l13(int time)
{
  Serial.println("l13-");
  digitalWrite(d3,LOW);
    digitalWrite(d4,HIGH);
    digitalWrite(d5,HIGH);
    digitalWrite(d6,HIGH);
    delay(time);
}
void l24(int time)
{
  Serial.println("l24-");
  
    digitalWrite(d4,LOW);
    digitalWrite(d3,HIGH);
    digitalWrite(d5,HIGH);
    digitalWrite(d6,HIGH);
    delay(time);
}

void l14(int time){
  Serial.println("l14-");
  for (int i=0; i<=time; i+=2){   
  l1(0);
  l4(0);
 }
}
void l23(int time){
  Serial.println("l23-");
 for (int i=0; i<=time; i+=2){ 
  l2(0);
  l3(0);
 }
}
void l124(int time){
  Serial.println("l124-");
  for (int i=0; i<=time; i+=2){ 
    l12(0);
    l4(0);
  }
}
void l123(int time){
  Serial.println("l123-");
  for (int i=0; i<=time; i+=3){
    l12(2);
    l3(1);
    }
}
void l134(int time){
  Serial.println("l134-");
  for (int i=0; i<=time; i+=3){
    l34(2);
    l1(1);
    }
}
void l234(int time){
  Serial.println("l234-");
  for (int i=0; i<=time; i+=3){
    l34(2);
    l2(1);
    }
}
void l1234(int time){
  Serial.println("l1234-");
  digitalWrite(d3,LOW);
  digitalWrite(d4,LOW);
  digitalWrite(d5,HIGH);
  digitalWrite(d6,HIGH);
  delay(time);
}
void l0(int time){
  Serial.println("l0-");
  digitalWrite(d3,LOW);
  digitalWrite(d4,LOW);
  digitalWrite(d5,LOW);
  digitalWrite(d6,LOW);
  delay(time);
}

void loop()
{
  
  l1(1000);
  l2(1000);
  l3(1000);
  l4(1000);
  l12(1000);
  l13(1000);
  l14(1000);  
  l23(1000);
  l24(1000);
  l34(1000);
  l123(1000);
  l234(1000);
  l134(1000);
  l124(1000);
  l1234(1000);
  l0(1000);  
}
