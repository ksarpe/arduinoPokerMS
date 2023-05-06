#include "buttons.h"

void setup() {
  Serial.begin(9600);

  pinMode(analogPin, INPUT);
  pinMode(analogPin2, INPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(selectPins[i], OUTPUT);
    pinMode(selectPins2[i], OUTPUT);
  }
}

void loop() {
    checkButtonStates(analogPin, selectPins, 0);
    checkButtonStates(analogPin2, selectPins2, 4);
}
