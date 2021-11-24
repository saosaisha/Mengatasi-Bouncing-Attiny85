/* ini contoh pemasangan saklar paling sederhana
 *  pada microcontroler
 *  tanpa resistor pull up
 *  dan tanpa bouncing
 *  Radal05
 *  https://www.youtube.com/c/Radal05
 *  25 Nopember 2021
 */
const int led = 1;
const int button = 0;
int button_state = LOW;
int led_state = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  button_state = digitalRead(button);
  if(button_state == LOW)
    led_state = !led_state;
  digitalWrite(led, led_state);
}
