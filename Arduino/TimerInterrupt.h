volatile unsigned long int Tmilis = 0;
unsigned long int timePrevBlink = 0;
unsigned long int timePrevData = 0;
unsigned long int timeBlink = 1000;
unsigned long int timeData = 250;

ISR(TIMER0_COMPA_vect) {              
    Tmilis++;
  if (Tmilis - timePrevBlink >= timeBlink){
  	timePrevBlink = Tmilis;
  	digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
  if (Tmilis - timePrevData >= timeData){
  	timePrevData = Tmilis;
  	Serial.println(digitalRead(4));
  }
}


unsigned long int  getmillis(){
  cli();
  unsigned long int result = Tmilis;
  sei();
  return result;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

TCCR0A |= (1 << WGM01);
OCR0A = 0xF9;
TIMSK0 |= (1 << OCIE0A);
TCCR0B |= (0<<CS02)|(1<<CS01)| (0<<CS00);
sei();
}

void loop() {
  
  
}
