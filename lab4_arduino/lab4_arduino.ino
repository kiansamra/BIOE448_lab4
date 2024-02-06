const int trigPin = 11;
const int echoPin = 12;
const int ledPin1 = 3; 
const int ledPin2 = 4; 
long duration;
float distanceCm, distanceInch;
// const float R1 = 1/58;
// const float R2 = 1/148;
const int C = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(C);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 1/58;
  distanceInch = duration * 1/148;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");

  if (distanceCm < 5) {
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, LOW);  
  } else {
    digitalWrite(ledPin1, LOW);   
    digitalWrite(ledPin2, HIGH);  
  }

  delay(500);
}


