/** Includes *****************************/
#include <Servo.h>

/** Definitions **************************/
double varNum, distancia;
// Create an instance for servo motor
Servo servo_12;

/** Functions ****************************/
// Ultrasound distance function calculator
double fnc_ultrasonic_distance(int _t, int _e, String _u) {
  unsigned long dur=0;
  digitalWrite(_t, LOW);
  delayMicroseconds(5);
  digitalWrite(_t, HIGH);
  delayMicroseconds(10);
  digitalWrite(_t, LOW);
  dur = pulseIn(_e, HIGH, 18000);
  if (dur == 0)
    return 999.0;
  if (_u == "cm")
    return (dur/57);
  else if (_u == "in")
    return (dur/57) * (1 / 2.54);
}

/** Setup function ***********************/
void setup() {
  Serial.begin(9600);
// Attach the pin selected from blockly
servo_12.attach(12);

  pinMode(11, OUTPUT);
  pinMode(10, INPUT);

  pinMode(A0, INPUT);
  distancia = 0;
  // Servomotor write angle and delay code
  servo_12.write(0);
  delay(1000);
}

/** Loop function ************************/
void loop() {
  // Servomotor write angle and delay code
  servo_12.write(0);
  delay(1000);
  if (fnc_ultrasonic_distance(11, 10, "cm") >= 80 && map(analogRead(A0),0,1023,0,100) > 75) {
    // Servomotor write angle and delay code
    servo_12.write(180);
    delay(100);
  }
  if (fnc_ultrasonic_distance(11, 10, "cm") == 2 && map(analogRead(A0),0,1023,0,100) == 0) {
    // Servomotor write angle and delay code
    servo_12.write(0);
    delay(100);
  }
  if (fnc_ultrasonic_distance(11, 10, "cm") <= 30 && map(analogRead(A0),0,1023,0,100) < 50) {
    // Servomotor write angle and delay code
    servo_12.write(60);
    delay(100);
  }
  delay(1000);
}



