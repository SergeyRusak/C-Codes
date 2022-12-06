#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(2, 3); // RX, TX
 
void setup()  
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  
  
  
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Goodnight moon!");
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
}


void ledswitch(int bites){
  digitalWrite(5, LOW); // начинаем передачу данных
	shiftOut(4, 6, LSBFIRST, bites);
	digitalWrite(5, HIGH); // прекращаем передачу данных

}


void led(int i){
switch (i){
  	case 0:
    	ledswitch(0b01110111);
    	break;
    case 1:
    	ledswitch(0b01000001);
    	break;
    case 2:
    	ledswitch(0b00111011);
    	break;
    case 3:
    	ledswitch(0b01101011);
    	break;
    case 4:
    	ledswitch(0b01001101);
    	break;
    case 5:
    	ledswitch(0b01101110);
    	break;
    case 6:
    	ledswitch(0b01111110);
    	break;
    case 7:
    	ledswitch(0b01000011);
    	break;
    case 8:
    	ledswitch(0b01111111);
    	break;
    case 9:
    	ledswitch(0b01101111);
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
