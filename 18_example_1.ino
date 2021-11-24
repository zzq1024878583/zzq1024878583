#include <Servo.h>
/////////////////////////////
// Configurable parameters //
/////////////////////////////
// Arduino pin assignment
#define PIN_LED 9
#define PIN_SERVO 10
#define PIN_IR A0
// Framework setting
#define _DIST_TARGET 255
#define _DIST_MIN 100
#define _DIST_MAX 410
// Distance sensor
#define _DIST_ALPHA 0.0 // EMA filter is disabled
// Servo range
#define _DUTY_MIN 1000
#define _DUTY_NEU 1450
#define _DUTY_MAX 2000
// Servo speed control
#define _SERVO_ANGLE 30
// angle b/w DUTY_MAX and DUTY_MIN
#define _SERVO_SPEED 30
// servo speed limit (deg/sec)
// Event periods
#define _INTERVAL_DIST 20
// distance sensor interval (ms)
#define _INTERVAL_SERVO 20 // servo interval (ms)
#define _INTERVAL_SERIAL 100 // serial interval (ms)
// PID parameters
#define _KP 0.0 // proportional gain *****
//////////////////////
// global variables //
//////////////////////
// Servo instance
Servo myservo;
// Distance sensor
float dist_target; // location to send the ball
float dist_raw, dist_ema;
// Event periods
unsigned long last_sampling_time_dist, last_sampling_time_servo,
last_sampling_time_serial;
bool event_dist, event_servo, event_serial;
// Servo speed control
int duty_chg_per_interval;
// maximum duty difference per interval
int duty_target, duty_curr;
// PID variables
float error_curr, error_prev, control, pterm, dterm, iterm;
