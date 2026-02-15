#ifndef TIMER_BUTTONWRAPPER_H
#define TIMER_BUTTONWRAPPER_H

#include <Arduino.h>
#include <ezButton.h>

#define SHORT_PRESS_TIME 500

class ButtonWrapper {

public:
    using Callback = std::function<void()>;

    ButtonWrapper(
        int pin,
        Callback shortPressCallback = nullptr,
        Callback longPressCallback = nullptr)
    : button(pin),
      shortPressCallback(shortPressCallback),
      longPressCallback(longPressCallback)
    {
    }

    void setup();
    void loop();

private:
    ezButton button;
    unsigned long pressedTime  = 0;
    unsigned long releasedTime = 0;

    Callback shortPressCallback;
    Callback longPressCallback;
};

#endif //TIMER_BUTTONWRAPPER_H