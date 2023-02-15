#define PIN_L_1 10
#define PIN_L_2 8
#define PIN_R_1 9
#define PIN_R_2 7

bool is_forward = false;

void setup(){
  pinMode(PIN_L_1, OUTPUT);
  pinMode(PIN_L_2, OUTPUT);
  pinMode(PIN_R_1, OUTPUT);
  pinMode(PIN_R_2, OUTPUT);

  digitalWrite(PIN_R_2, HIGH);
  digitalWrite(PIN_L_2, LOW);
  is_forward = true;
}

void move(int value){
if((value > 0)!= is_forward ||value==0){
  digitalWrite(PIN_R_2, (value>0)?HIGH:LOW);
  digitalWrite(PIN_L_2, (value<0)?HIGH:LOW);
  is_forward = value > 0;
}
analogWrite(PIN_R_1,(value<0)?(-value):(0));
analogWrite(PIN_L_1,(value>0)?(value):(0));
}
void loop(){
move(-255);
delay(1000);
move(0);
delay(1000);
move(255);
delay(1000);


}
  
