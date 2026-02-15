#include "TimerMode.h"

#include <Arduino.h>

void TimerMode::onActivated()
{
    isActive = true;
    Serial.println("Timer Mode is activated");
}

void TimerMode::onDeactivated()
{
    isActive = false;
    Serial.println("Timer Mode is deactivated");
}

void TimerMode::loop()
{
    if (isCountdownActive){

        unsigned long currentTime = millis();
        unsigned long elapsedTimeSeconds = (currentTime - startTime) / 1000; // in Sekunden
        //unsigned long elapsedTimeMinutes = elapsedTimeSeconds / 60; // in Minuten

        remainingSeconds = countdownDurationSeconds - elapsedTimeSeconds;
        //remainingMinutes = remainingTimeSeconds / 60;

        if (elapsedTimeSeconds >= countdownDurationSeconds) {
            Serial.println("Timer is out");
            isCountdownActive = false;
            alarm->play();
        }
    }

    if (!isActive)
        return;

    if (remainingSeconds < 60) {

        display->set(
            0,
            0,
            remainingSeconds / 10,
            remainingSeconds % 10);
        return;
    }

    short minutes = remainingSeconds / 60;

    short hour = minutes / 60;
    short minute = minutes % 60;

    short minuteToDisplay = remainingSeconds % 60 == 0 ? minute : minute + 1;

    display->set(
        hour / 10,
        hour % 10,
        minuteToDisplay / 10,
        minuteToDisplay % 10);
}


void TimerMode::modeButtonShortPress()
{
    setModeCallback(CLOCK);
}

void TimerMode::downButtonShortPress()
{
    if (countdownDurationSeconds / 60 == 0)
        return;

    countdownDurationSeconds-= 60;
    remainingSeconds = countdownDurationSeconds;
}

void TimerMode::upButtonShortPress()
{
    countdownDurationSeconds += 60;
    remainingSeconds = countdownDurationSeconds;

    startTime = millis();
    isCountdownActive = true;
}
