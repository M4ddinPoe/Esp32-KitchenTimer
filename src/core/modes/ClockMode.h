#ifndef TIMER_CLOCKMODE_H
#define TIMER_CLOCKMODE_H

#include <Arduino.h>
#include "BaseMode.h"
#include "../display.h"
#include "Mode.h"

class ClockMode : public BaseMode
{
public:
    using Callback = std::function<void(Mode)>;

    ClockMode(
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
};

#endif //TIMER_CLOCKMODE_H