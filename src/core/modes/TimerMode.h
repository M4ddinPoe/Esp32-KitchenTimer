#ifndef TIMER_TIMERMODE_H
#define TIMER_TIMERMODE_H

#include <Arduino.h>
#include "BaseMode.h"
#include "../display.h"
#include "../alarm.h"
#include "Mode.h"

class TimerMode: public BaseMode
{
    public:
        virtual ~TimerMode() = default;

        using Callback = std::function<void(Mode)>;

        TimerMode(
            Display* display = nullptr,
            Alarm* alarm = nullptr,
            Callback setModeCallback = nullptr,
            Mode nextMode = CLOCK
        ) : display(display),
            alarm(alarm),
            setModeCallback(setModeCallback),
            nextMode(nextMode)
        {
        }

        void onActivated() override;
        void onDeactivated() override;
        void loop() override;
        void modeButtonShortPress() override;
        void downButtonShortPress() override;
        void upButtonShortPress() override;

    private:
        Display* display;
        Alarm* alarm;
        Callback setModeCallback;
        Mode nextMode;

        bool isActive = false;
        bool isCountdownActive = false;
        bool isSoundPlaying = false;
        unsigned long startTime = 0;
        //short countdownDurationMinutes = 0;
        unsigned int countdownDurationSeconds = 0;
        //short remainingMinutes = 0;
        unsigned int remainingSeconds = 0;
};

#endif //TIMER_TIMERMODE_H