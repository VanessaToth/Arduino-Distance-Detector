#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define trigPin 9
#define echoPin 8
#define buzzer 7
#define redLED 6
#define blueLED 5

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

int angle = 0;
bool increasing = true;
bool objectDetected = false;
unsigned long previousMillis = 0;
bool blinkState = false;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  myServo.attach(10);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();
}

void loop() 
{
  long duration, distance;

  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 40)
  {
    // Object detected
    if (!objectDetected) 
    {
      lcd.clear();
      objectDetected = true;
    }

    lcd.setCursor(0, 0);
    lcd.print("AREA NOT CLEAR ");
    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm   ");

    digitalWrite(blueLED, LOW);
    myServo.detach(); 

    // Buzzer and LED blink
    unsigned long currentMillis = millis(); //timer
    if (currentMillis - previousMillis >= 300) 
    {
      previousMillis = currentMillis;
      blinkState = !blinkState;
      digitalWrite(buzzer, blinkState);
      digitalWrite(redLED, blinkState); 
    }
  } 
  else 
  {
    // Area is clear
    if (objectDetected) 
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("AREA IS CLEAR ");
      objectDetected = false;
    }

    digitalWrite(buzzer, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
    blinkState = false;

    if (!myServo.attached())
    {
      myServo.attach(10);
    }

    // Move servo
    if (increasing)
    {    
      angle++;
      if (angle >= 180) increasing = false;
    } 
    else 
    {
      angle--;
      if (angle <= 0) increasing = true;
    }

    myServo.write(angle);
    delay(20);
  }
}
