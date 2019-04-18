/*
 * Author: Rob Bultman
 * Date:   April 18, 2019
 * 
 * License: MIT
 * 
 * Sweep a PWM pin between two different levels over a period.
 */

// Define the output pin
#define PWM_PIN 3

/* 
 * PWM levels.  
 * This mus be between 0.0 and 1.0. 
 * The number cannot be negative.
 * 0.0 =   0% duty cycle
 * 1.0 = 100% duty cycle
 */
#define PWM_LOW 0.7
#define PWM_HIGH 1.0

// Define the period in seconds.
// The PWM will vary from LOW to HIGH and back to LOW in this time
#define PERIOD_SECONDS 10

/**************************************************
 * DO NOT MAKE CHANGES BELOW THIS LINE!!!
 **************************************************/

float range = PWM_HIGH - PWM_LOW;
float pwmValue;
float stepValue = range / 127;
float timeStep = 1000.0*PERIOD_SECONDS/255.0;

void setup() {
  Serial.begin(115200);
  
  // check that the numbers are within range
  if ((PWM_LOW < 0.0) || (PWM_LOW > 1.0) || (PWM_HIGH < 0.0) || (PWM_HIGH > 1.0) || (PWM_LOW > PWM_HIGH)) {
    while(0) {
      Serial.println("Values are out of range.");
      delay(1000);    
    }
  }

  pwmValue = PWM_LOW;
}

unsigned int i=0;

void loop() {
//  Serial.print("i = ");
//  Serial.print(i);
//  Serial.print(", pwm = ");
//  Serial.println(pwmValue);
  
  analogWrite(PWM_PIN, (int)(255.0*pwmValue));
  
  if (i++<128) {
    pwmValue = pwmValue + stepValue;
  } else {
    pwmValue = pwmValue - stepValue;
  }

  if (i==256) {
//    Serial.println("Resetting values after one cycle complete.");
    i = 0;
    pwmValue = PWM_LOW;
  }

  delay(timeStep);
}

