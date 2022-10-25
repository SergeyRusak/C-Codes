//master code_______________________

#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(2, 3); // RX, TX
 
void setup()  
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Goodnight moon!");
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
}

void ledswitch(int bytes){
  for (int i=4;i<12;i++){
  digitalWrite(i,(bytes & 1)?(HIGH):(LOW));
    bytes = bytes >> 1;
  }
}


void led(int i){
switch (i){
  	case 0:
    	ledswitch(0b11101110);
    	break;
    case 1:
    	ledswitch(0b10000010);
    	break;
    case 2:
    	ledswitch(0b11011100);
    	break;
    case 3:
    	ledswitch(0b11010110);
    	break;
    case 4:
    	ledswitch(0b10110010);
    	break;
    case 5:
    	ledswitch(0b01110110);
    	break;
    case 6:
    	ledswitch(0b01111110);
    	break;
    case 7:
    	ledswitch(0b11000010);
    	break;
    case 8:
    	ledswitch(0b11111110);
    	break;
    case 9:
    	ledswitch(0b11110110);
    	break;
  }


}

void ser(){
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.print(Serial.read()); 
}

void loop()
{
  while (Serial.available()) {
    int i = Serial.parseInt();
    mySerial.print(i%10);
    led(i/10);
  }
}



// slave code________________________________________


void setup()  
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  
  
  
  Serial.begin(4800);
  while (!Serial) {}
}


void ledswitch(int bytes){
  for (int i=4;i<12;i++){
  digitalWrite(i,(bytes & 1)?(HIGH):(LOW));
    bytes = bytes >> 1;
  }
}


void led(int i){
switch (i){
  	case 0:
    	ledswitch(0b11101110);
    	break;
    case 1:
    	ledswitch(0b10000010);
    	break;
    case 2:
    	ledswitch(0b11011100);
    	break;
    case 3:
    	ledswitch(0b11010110);
    	break;
    case 4:
    	ledswitch(0b10110010);
    	break;
    case 5:
    	ledswitch(0b01110110);
    	break;
    case 6:
    	ledswitch(0b01111110);
    	break;
    case 7:
    	ledswitch(0b11000010);
    	break;
    case 8:
    	ledswitch(0b11111110);
    	break;
    case 9:
    	ledswitch(0b11110110);
    	break;
  }


} 
  
void loop()
{
  while (Serial.available()) {
  	int i = Serial.parseInt();
  	Serial.println(i);
    led(i);
  }
  
}
