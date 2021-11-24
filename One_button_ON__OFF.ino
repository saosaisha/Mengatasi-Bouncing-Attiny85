/* ini contoh pemasangan saklar ON OFF
 *  pada microcontroler
 *  tanpa resistor pull up
 *  dan dengan bouncing
 *  Radal05
 *  https://www.youtube.com/c/Radal05
 *  25 Nopember 2021
 */
const int led = 1;
const int button = 0;
int led_state = LOW;

int buttonState = 0;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(button);
  if (reading != lastButtonState)
    lastDebounceTime = millis();

  if ((millis() - lastDebounceTime) > 50) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        led_state = !led_state;
      }
    }
  }

  lastButtonState = reading;

  digitalWrite(led, led_state);
}
