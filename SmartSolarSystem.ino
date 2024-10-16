#include <Servo.h>

Servo myServo;

const int ldrPin1 = A0; // Pin untuk LDR 1
const int ldrPin2 = A1; // Pin untuk LDR 2
const int servoPin = 9; // Pin untuk Servo

void setup() {
  myServo.attach(servoPin);
  myServo.write(90); // Posisi awal servo di tengah
  Serial.begin(9600);
}

void loop() {
  int ldrValue1 = analogRead(ldrPin1); // Baca nilai dari LDR 1
  int ldrValue2 = analogRead(ldrPin2); // Baca nilai dari LDR 2

  Serial.print("LDR 1: ");
  Serial.print(ldrValue1);
  Serial.print(" LDR 2: ");
  Serial.println(ldrValue2);

  if (ldrValue1 > ldrValue2 + 10) { // LDR 1 lebih terang
    myServo.write(0); // Gerakkan servo ke kiri
  } 
  else if (ldrValue2 > ldrValue1 + 10) { // LDR 2 lebih terang
    myServo.write(180); // Gerakkan servo ke kanan
  } 
  else {
    myServo.write(90); // Posisi tengah jika kedua LDR hampir sama
  }

  delay(100); // Tunggu sejenak sebelum membaca lagi
}
