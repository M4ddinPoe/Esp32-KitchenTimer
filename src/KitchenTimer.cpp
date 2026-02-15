#include "KitchenTimer.h"

void KitchenTimer::setup() {

    display.setup();
    alarm.setup();
    modeButton.setup();
    upButton.setup();
    downButton.setup();
}

void KitchenTimer::loop() {

    modeButton.loop();
    upButton.loop();
    downButton.loop();

    clockMode.loop();
    setClockMode.loop();
    timerMode.loop();

    display.update();
}

void KitchenTimer::onModeButtonShortPressed() {

    if (alarm.isPlaying)
        alarm.stop();

    currentMode->modeButtonShortPress();
}

void KitchenTimer::onModeButtonLongPressed() {

    if (alarm.isPlaying)
        alarm.stop();

    setMode(SET_CLOCK);
}

void KitchenTimer::onUpButtonShortPressed(){

    if (alarm.isPlaying)
        alarm.stop();

    currentMode->upButtonShortPress();
}

void KitchenTimer::onDownButtonShortPressed() {

    if (alarm.isPlaying)
        alarm.stop();

    currentMode->downButtonShortPress();
}

void KitchenTimer::setMode(Mode requestedMode) {

    Serial.println("requested mode change to: " + String(requestedMode));

    currentMode->onDeactivated();

    if (requestedMode == CLOCK){

        mode = CLOCK;
        currentMode = &clockMode;
    }
    else if (requestedMode == SET_CLOCK) {

        mode = SET_CLOCK;
        currentMode = &setClockMode;
    }
    else if (requestedMode == TIMER1) {

        mode = TIMER1;
        currentMode = &timerMode;
    }

    if (currentMode == nullptr) {
        Serial.println("ERROR: current mode is null");
        return;
    }

    currentMode->onActivated();
    Serial.println("mode is changed to: " + String(mode));
}
