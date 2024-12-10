#define BLYNK_TEMPLATE_ID "TMPL6Mok76KnZ"         
#define BLYNK_TEMPLATE_NAME "Smart Light"          
#define BLYNK_AUTH_TOKEN "ZWliXEOCJVnY7kaT1kJ_JQm0cswI_0Vi"  

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Hai Anh";  
char pass[] = "31121977"; 

#define analogPin A0
#define led D2
int sensorValue;
int percentage;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(led, OUTPUT);  
}

void loop()
{
  Blynk.run();  
  sensorValue = analogRead(analogPin);  
  percentage = map(sensorValue, 0, 1023, 100, 0);  
  Blynk.virtualWrite(V2, percentage);  

  if (percentage <= 20) {  
    digitalWrite(led, HIGH);
  }
  else {  
    digitalWrite(led, LOW);
  }
}
