#include "ButtonWrapper.h"
#include <Arduino.h>

void ButtonWrapper::setup() {

    button.setDebounceTime(50);
}

void ButtonWrapper::loop() {

    button.loop();

    if (button.isPressed()){
        pressedTime = millis();
    }

    if (button.isReleased()) {
        releasedTime = millis();

        long pressDuration = releasedTime - pressedTime;

        if ( pressDuration < SHORT_PRESS_TIME )
            shortPressCallback();
        else
            longPressCallback();
    }
}
