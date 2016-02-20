 const int buttonPin1 = 2;    // the number of the pushbutton pin
 const int buttonPin2 = 3;    // the number of the pushbutton pin

const int pushButtonPin = 4;     // the number of the pushbutton pin

 // Variables will change:
int buttonState1;             // the current reading1 from the input pin
int buttonState2;             // the current reading1 from the input pin
int pushButtonState = 0;         // variable for reading the pushbutton status

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime1 = 0;  // the last time the output pin was toggled
long lastDebounceTime2 = 0;  // the last time the output pin was toggled

long debounceDelay = 1000;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(pushButtonPin, INPUT);
  
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

  // read the state of the pushbutton value:
  pushButtonState = digitalRead(pushButtonPin);

  // check if the pushbutton is pressed.
  // if it is, the pushButtonState is HIGH:
  if (pushButtonState == HIGH) {
    // turn LED on:
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);

  } else {
    // turn LED off:
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);

  }

}
