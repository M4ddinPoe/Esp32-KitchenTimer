#ifndef TIMER_KITCHENTIMER_H
#define TIMER_KITCHENTIMER_H

#include "core/display.h"
#include "core/alarm.h"
#include "core/modes/Mode.h"
#include "core/modes/BaseMode.h"
#include "core/modes/ClockMode.h"
#include "core/modes/SetClockMode.h"
#include "core/modes/TimerMode.h"
#include "core/ButtonWrapper.h"

class KitchenTimer {

public:
    KitchenTimer(int modeButtonPin, int upButtonPin, int downButtonPin, int buzzerPin, int clkPin, int dioPin)
        : display(clkPin, dioPin),
          alarm(buzzerPin),
          modeButton(
              modeButtonPin,
              [this]() { this->onModeButtonShortPressed(); },
              [this]() { this->setMode(SET_CLOCK); }
          ),
          upButton(
              upButtonPin,
              [this]() { this->onUpButtonShortPressed(); },
              []() {
              }
          ),
          downButton(
              downButtonPin,
              [this]() { this->onDownButtonShortPressed(); },
              []() {
              }
          ),
          clockMode(
              &display,
              [this](Mode mode) { this->setMode(mode); }
          ),
          setClockMode(
              &display,
              [this](Mode mode) { this->setMode(mode); }
          ),
          timerMode(
              &display,
              &alarm,
              [this](Mode mode) { this->setMode(mode); },
              CLOCK
          ),
          currentMode(
              &clockMode
          ) {
    }

    void setup();
    void loop();

private:
    Display display;
    Alarm alarm;

    ButtonWrapper modeButton;
    ButtonWrapper upButton;
    ButtonWrapper downButton;

    ClockMode clockMode;
    SetClockMode setClockMode;
    TimerMode timerMode;
    Mode mode = CLOCK;

    BaseMode* currentMode;

    void onModeButtonShortPressed();
    void onModeButtonLongPressed();
    void onUpButtonShortPressed();
    void onDownButtonShortPressed();
    void setMode(Mode requestedMode);
};

#endif //TIMER_KITCHENTIMER_H