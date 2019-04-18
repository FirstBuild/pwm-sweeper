# pwm-sweeper
Sweep a PWM output between two levels over a period.  The value will sweep 
between the LOW PWM value and the HIGH PWM value and then back to the LOW
value over one period.  The variation is linear.

### Instructions
- Download the repo and open it in the Arduino IDE.
- Change the macro definitions for your needs

| Macro | Use |
|-------|------|
| PWM_PIN | The output pin\* |
| PWM_LOW | The low value of the duty cycle\*\* |
| PWM_HIGH | The high value of the duty cycle |
| PERIOD_SECONDS | The period in seconds, e.g. 10 = 10 seconds |

\* The output pin chosen must be on a pin supported by your board. See the 
[Arduino analogWrite reference](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
for more info.
\*\* PWM Value Notes:
- The value must be between 0.0 and 1.0
- The value must not be negative
- PWM_LOW must be less than PWM_HIGH
- 0.0 =   0% duty cycle
- 1.0 = 100% duty cycle

