int trigPin1 = 4;
int echoPin1 = 3;
int trigPin2 = 5;
int echoPin2 = 6;
int red1 = 13;
int red2 = 8;
int gre2 = 10;
int gre1 = 9;

long duration1, duration2;  
int distance1, distance2; 


void setup() {
  // put your setup code here, to run once:
pinMode (trigPin1, OUTPUT);
pinMode (echoPin1, INPUT);
pinMode (trigPin2, OUTPUT);
pinMode (echoPin2, INPUT);
pinMode (red1, OUTPUT);
pinMode (red2, OUTPUT);
pinMode (gre2, OUTPUT);
pinMode (gre1, OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 /*==================================
   *    Ultrasonic Sensor#1
   ==================================*/
        

  //set TRIGGER_PIN1 to High for 10 microseconds
    digitalWrite(trigPin1, LOW);  
    delayMicroseconds(2);    
  
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  //read the duration of the sound wave with ECHO_PIN1
  duration1 = pulseIn(echoPin1, HIGH);

  //calculate distance based on duration of ultrasound from triggerPin to echoPin
  distance1 = duration1*0.034/2;
 /*  ===============================
   *    Ultrasonic Sensor#2
   ==================================*/
  //clear TRIGGER_PIN2 value, setting it to LOW for 2 microseconds
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2);          

  //set TRIGGER_PIN2 to High for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  //read the duration of the sound wave with ECHO_PIN1
  duration2 = pulseIn(echoPin2, HIGH);

  //calculate distance based on duration of ultrasound from triggerPin to echoPin
  distance2 = duration2*0.034/2;
   /*==================================
   *    Print to Serial Monitor
   ==================================*/
  
  Serial.print("distance from sensor1: ");
  Serial.print(distance1);
  Serial.println("cm");
  Serial.print("distance from sensor2: ");
  Serial.print(distance2);
  Serial.println("cm");
  delay(500);

  /*==================================
   *    Control LED
   ==================================*/  

  if (distance1 <=250)
 {
    digitalWrite(gre1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(gre2, LOW);
    digitalWrite(red1, LOW);
    Serial.println("Sensor1 Lane Priority");
    delay(1000);
  } 
  else if (distance2 <=250 )
 {
    digitalWrite(gre2, HIGH);
    digitalWrite(red1, HIGH);
    digitalWrite(gre1, LOW);
    digitalWrite(red2, LOW);
    Serial.println("Sensor2 Lane Priority");
    delay(1000);
 } 
   else 
 {
    digitalWrite(gre2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(gre1, LOW);
    digitalWrite(red2, LOW); 
} 
 if (distance1 >= 300 && distance2 >= 300)
 {
    digitalWrite(gre2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(gre1, LOW);
    digitalWrite(red2, LOW);
    Serial.println("No object detected");
    delay(1000);
 }
}
