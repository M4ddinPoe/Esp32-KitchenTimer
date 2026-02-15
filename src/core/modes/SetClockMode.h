#ifndef TIMER_SETCLOCKMODE_H
#define TIMER_SETCLOCKMODE_H

#include <Arduino.h>
#include "BaseMode.h"
#include "Mode.h"
#include "../display.h"

class SetClockMode: public BaseMode
{
public:
    using Callback = std::function<void(Mode)>;

    SetClockMode(
        Display* display = nullptr,
        Callback setModeCallback = nullptr
    ) : display(display),
        setModeCallback(setModeCallback)
    {
    }

    void onActivated();
    void onDeactivated();
    void loop();
    void modeButtonShortPress();
    void downButtonShortPress();

    void upButtonShortPress();
private:
    Display* display;
    Callback setModeCallback;

    bool isActive = false;
    bool setMinute = false;
    short hour = 0;
    short minute = 0;

    void incrementMinute();
    void decrementMinute();
    void incrementHour();
    void decrementHour();
};

#endif //TIMER_SETCLOCKMODE_H