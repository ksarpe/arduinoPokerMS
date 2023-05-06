#pragma once

#include <Arduino.h>

#define PLAYERS 4
#define BUTTONS_PER_PLAYER 4
#define MUX_AMOUNT 2
#define MUX_BITS 4

const int analogPin = A0;
const int analogPin2 = A1;
const int selectPins[] = {2, 3, 4, 5};
const int selectPins2[] = {6, 7, 8, 9};

void checkButtonStates(int analogPin, const int* selectPins, int playerOffset);
String getActionString(int button);
