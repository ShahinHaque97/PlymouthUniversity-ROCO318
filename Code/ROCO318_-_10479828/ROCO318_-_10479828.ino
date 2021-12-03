#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//first pwm controller
Adafruit_PWMServoDriver servo_controller_0 = Adafruit_PWMServoDriver(0x40, Wire);

//first pwm controller
Adafruit_PWMServoDriver servo_controller_1 = Adafruit_PWMServoDriver(0x41, Wire);

//servo characteristics
#define SERVOMIN  70 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  500 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// Servo Number
uint8_t servonum = 0;

// Servo Midpoint
unsigned int servo_midpoint =  215; 
//((SERVOMAX - SERVOMIN ) / 2);

void reset_servos() {

 for (int i = 0; i <= 15; i++) {
    servo_controller_0.setPWM(i, 0, servo_midpoint);
    delay(100);
 }

 for (int i = 0; i <= 15; i++) {
    servo_controller_1.setPWM(i, 0, servo_midpoint);
    delay(100);
 }
 delay(1000); 
// reset_servos() END
}


void setup() {
  Serial.begin(9600);
  servo_controller_0.begin();
  servo_controller_0.setOscillatorFrequency(27000000);
  servo_controller_0.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);

  servo_controller_1.begin();
  servo_controller_1.setOscillatorFrequency(27000000);
  servo_controller_1.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10); 

reset_servos();
//servo_controller_0.setPWM(10, 0, 215);
int a = 250;

}
//--------------------------------------------------------

void loop() {

  int i;
  i= 250;
  int delayy = 100;
  servo_controller_1.setPWM(1, 0, i);
      delay(delayy);
  servo_controller_1.setPWM(3, 0, i);
      delay(delayy);
  servo_controller_1.setPWM(4, 0, i);
      delay(delayy);
  servo_controller_1.setPWM(6, 0, i);
      delay(delayy);
  servo_controller_1.setPWM(2, 0, i);
      delay(delayy);
  servo_controller_1.setPWM(5, 0, i);
      delay(delayy);


//#########################################################
    delay(3000);
//#########################################################

// servo_controller_1.setPWM(8, 0, 215+100);
// servo_controller_1.setPWM(8, 0, 215+100);
  servo_controller_1.setPWM(9, 0, (215+100));
 //  servo_controller_1.setPWM(10, 0, 215+100);

// servo_controller_0.setPWM(11, 0, 215+100);
  servo_controller_0.setPWM(12, 0, (215-100));
//   servo_controller_0.setPWM(13, 0, 215+100);

servo_controller_1.setPWM(5, 0, 300);
servo_controller_1.setPWM(2, 0, 300);

   
 
while(1){}
}
