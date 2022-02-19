const int echopin = 3;
const int trigpin = 5; 
long duration;
int distance;
const int pin = 12; 
const int pin2 = 15;
const int pin3 = 14;
const int ledPin = 2;
const int ledPin1 = 0;
const int ldrPin = A0;
 
void setup() {
 pinMode(trigpin, OUTPUT);
 pinMode(echopin, INPUT);
 pinMode(pin, OUTPUT);
 pinMode(pin2, OUTPUT);
 pinMode(pin3, OUTPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(ledPin1, OUTPUT);
 pinMode(ldrPin, INPUT);
Serial.begin(9600);
}
void loop() {
digitalWrite(trigpin, LOW);
delay(5);
digitalWrite(trigpin, HIGH);
delay(10);
digitalWrite(trigpin, LOW);
duration = pulseIn(echopin, HIGH);
distance = duration *0.034/2;
Serial.print("Distance is :"); 
Serial.println(distance);
if( distance  < 16&&distance>=11){
digitalWrite (pin, HIGH);
 delay(1);
  }
  else if( distance  < 11&&distance>=5 )
  {
  digitalWrite (pin2, HIGH);
  delay(1);
  }
  else if( distance  < 5 )
   {
    digitalWrite (pin3, HIGH);
  delay(1);
  }
  else{
     digitalWrite (pin, LOW );
     digitalWrite (pin2, LOW );
     digitalWrite (pin3, LOW );
    } 
    int ldrStatus = analogRead(ldrPin);
if (ldrStatus <=700) {
digitalWrite(ledPin, HIGH);
digitalWrite(ledPin1, HIGH);
Serial.println("LDR is DARK, LED is ON");
}
else {
digitalWrite(ledPin, LOW);
digitalWrite(ledPin1, LOW);
Serial.println("---------------");
}
}
 
