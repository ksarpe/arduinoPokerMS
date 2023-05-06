#include "buttons.h"

void checkButtonStates(int analogPin, const int* selectPins, int playerOffset) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < MUX_BITS; j++) {
            digitalWrite(selectPins[j], bitRead(i, j));
        }

        int buttonState = analogRead(analogPin);

        if (buttonState > 512) {
            int player = i / BUTTONS_PER_PLAYER + 1 + playerOffset;
            int button = i % BUTTONS_PER_PLAYER;
            Serial.print("Player ");
            Serial.print(player);
            Serial.print(" called ");
            Serial.print(getActionString(button));
            Serial.print(buttonState);
            delay(300);
            Serial.println();
        }
    }
}

String getActionString(int button) {
    switch (button) {
        case 0:
            return "Call/Check";
        case 1:
            return "Fold";
        case 2:
            return "Raise";
        case 3:
            return "All In";
    }
}
