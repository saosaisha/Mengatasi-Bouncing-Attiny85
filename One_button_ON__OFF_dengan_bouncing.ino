/* ini contoh pemasangan saklar paling sederhana
 *  pada microcontroler
 *  tanpa resistor pull up
 *  dan tanpa bouncing, bounce2
 *  Radal05
 *  https://www.youtube.com/c/Radal05
 *  25 Nopember 2021
 */
#include <Bounce2.h>

const int led = 1;
const int button = 0;
int led_state = LOW;

Bounce debouncer;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  debouncer.attach(button);
  debouncer.interval(5);
}

void loop() {
  debouncer.update();
  if (debouncer.fell())
    led_state = !led_state;

  digitalWrite(led, led_state);
}
