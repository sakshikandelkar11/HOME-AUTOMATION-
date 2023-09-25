#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_AUTH_TOKEN "AMvjtZBzkdBcz4WHKFmwUf-1R_W5tU0r"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "sakshi";//Enter your WIFI name
char pass[] = "sakshi11";//Enter your WIFI password

int trig=D6;
int echo=D7;
long duration;
int dist;

BLYNK_WRITE(V0){
  digitalWrite(D0,param.asInt());
}
BLYNK_WRITE(V2){
  digitalWrite(D1,param.asInt());
}
BLYNK_WRITE(V3){
  digitalWrite(D2,param.asInt());
}

void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);


  Blynk.begin(auth, ssid, pass,"blynk.cloud", 80);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  
}

void loop()
{
  Blynk.run();
digitalWrite(trig,0);
delayMicroseconds(5);
digitalWrite(trig,1);
delayMicroseconds(10);
digitalWrite(trig,0);
duration = pulseIn(echo,1);
dist = (duration/2) * 0.0343;
Serial.println(dist);
Serial.println("cm");
delay(100);
Blynk.virtualWrite(V1,dist);

}