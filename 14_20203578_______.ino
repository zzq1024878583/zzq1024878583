void setup() {
  // put your setup code here, to run once:
if(event_dist) {
…
pterm = _KP * error_curr;
dterm = _KD * (error_curr - error_prev);
control = pterm + dterm;
duty_target = _DUTY_NEU + control;
// Limit duty_target within the range of [_DUTY_MIN, _DUTY_MAX]
if(duty_target < _DUTY_MIN) duty_target = _DUTY_MIN; // lower limit
if(duty_target > _DUTY_MAX) duty_target = _DUTY_MAX; // upper limit
// update error_prev
error_prev = error_curr;

}

void loop() {
  // put your main code here, to run repeatedly:
if(event_serial) {
event_serial = false;
Serial.print("dist_ir:");
Serial.print(dist_raw);
Serial.print(",pterm:");
Serial.print(map(pterm,-1000,1000,510,610));
Serial.print(",dterm:");
Serial.print(map(dterm,-1000,1000,510,610));
Serial.print(",duty_target:");
Serial.print(map(duty_target,1000,2000,410,510));
Serial.print(",duty_curr:");
Serial.print(map(duty_curr,1000,2000,410,510));
Serial.println(",Min:100,Low:200,dist_target:255,High:310,Max:410");

}
