#include "Config.h"
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"


String res;
char incomingByte;
void setup(void){
  res="";
  Serial.begin(9600);
  WIFI_init(false);
  MQTT_init();
  pinMode(led, OUTPUT);
  mqtt_cli.publish("esp8266/state", "hello");
}

void loop(void){  
  if(Serial.available()>0){
  char t = (Serial.read() & 0xFF);
  if (t=='\n'){
    res.trim();
    Serial.println(res);
    mqtt_cli.publish("esp8266/data",res.c_str());
    res="";  
  }else{
    res = res + t ;
  }
  }
                 
  mqtt_cli.loop();
     
     
     
     //delay(250);
}
