int trigPin = 11;
int echoPin = 12;
long duration, cm;
int led1 = 10;
int led2 = 9;
int led3 = 8;
int led4 = 7;
int led5 = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin  (9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  pinMode (led5, OUTPUT);
}

void loop() { // put your main code here, to run repeatedly:

  //ultrasonic sensor read
  digitalWrite (trigPin, LOW);
  delayMicroseconds (5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite(trigPin, LOW);

  //convert sensor value to distance in cm
  pinMode (echoPin, INPUT);
  duration = pulseIn (echoPin, HIGH);
  cm = (duration / 2) / 29.1;

  //print ultrasonic sensor value
  Serial.print(cm);
  Serial.print("cm");
  Serial.print(" . ");

  //fotoresistor sensor read and print its value
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);


//if there's no light and something is near lights turn on and off making a sequence. If this conditions continue, light will continue doing the sequence
  if (cm <= 10 && sensorValue < 800 ) {

    delay(100);
    digitalWrite( led1, HIGH);
    delay(200);
    digitalWrite( led2, HIGH);
    delay(200);
    digitalWrite( led3, HIGH);
    delay(200);
    digitalWrite( led4, HIGH);
    delay(200);
    digitalWrite( led5, HIGH);
    delay(200);
    digitalWrite( led1, LOW);
    digitalWrite( led2, LOW);
    digitalWrite( led3, LOW);
    digitalWrite( led4, LOW);
    digitalWrite( led5, LOW);

  }
  else {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);

  }
  delay(10);
}
