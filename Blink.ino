 const int buttonPin1 = 2;    // the number of the pushbutton pin
 const int buttonPin2 = 3;    // the number of the pushbutton pin

 // Variables will change:
int buttonState1;             // the current reading1 from the input pin
int buttonState2;             // the current reading1 from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime1 = 0;  // the last time the output pin was toggled
long lastDebounceTime2 = 0;  // the last time the output pin was toggled

long debounceDelay = 1000;    // the debounce time; increase if the output flickers

 
void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  Keyboard.begin();
}


void loop() {
  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);

   if ((millis() - lastDebounceTime1) > debounceDelay) {
     lastDebounceTime1 = 0;
   }

   if ((millis() - lastDebounceTime2) > debounceDelay) {
     lastDebounceTime2 = 0;
   }

    if (reading1 != buttonState1 && !lastDebounceTime1) {
      buttonState1 = reading1;

      if (buttonState1 == LOW) {
        Keyboard.write(49);
        lastDebounceTime1 = millis();
      }
    }

    if (reading2 != buttonState2 && !lastDebounceTime2) {
      buttonState2 = reading2;

      if (buttonState2 == LOW) {
        Keyboard.write(50);
        lastDebounceTime2 = millis();
      }
    }

}
