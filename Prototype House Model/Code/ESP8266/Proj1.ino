int redLed = D4;
int buzzer = D5;
int smokeA0 = A0;
int sensorThres = 700;

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "887kuqewmItu5LAa_O2bSak1I0ra-f9B";
char ssid[] = "8115";
char pass[] = "gecm8115";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

   pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Blynk.run();

  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  }
  delay(100);
}
