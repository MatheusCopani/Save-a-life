const int trigPin = 14;
const int echoPin = 12;
#define SOUND_SPEED 0.034

#define led 2
#define ledI 13
#define buzzer 5


const int ADC_pin = A0;  
int sensor_reading = 0;  
long duration;
float distanceCm;


void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(ledI, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  sensor_reading = analogRead(ADC_pin);
  Serial.println("ADC reading = ");
  Serial.println(sensor_reading);
  digitalWrite(ledI, HIGH);

   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);

   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);

   duration = pulseIn(echoPin, HIGH);
   distanceCm = duration * SOUND_SPEED/2;
   Serial.print("Distance (cm): ");
   Serial.println(distanceCm);
  

  if((sensor_reading > 600) && (distanceCm > 80))
  {
    digitalWrite(buzzer, HIGH);
    delay(5000);
  }
  else
  {
    digitalWrite(buzzer,LOW);

  }
  
 delay(1000);
}

