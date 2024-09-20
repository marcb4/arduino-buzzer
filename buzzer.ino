#include "Keyboard.h"

//declaring button pins
const int buttonPin = 2;          

int previousButtonState = HIGH; 

void setup() {
  // declare the buttons as input_pullup
  pinMode(buttonPin, INPUT_PULLUP);  
  Keyboard.begin();
}

void loop() {
  // checking the state of the button
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW && previousButtonState == HIGH) {
    Keyboard.press(KEY_PRINT_SCREEN);
    delay(50);
  }

  if (buttonState == HIGH && previousButtonState == LOW) {
      // release all keys:
    Keyboard.releaseAll();
    delay(50);
  }
 
  previousButtonState = buttonState;

}