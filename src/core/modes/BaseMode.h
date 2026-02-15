#ifndef TIMER_BASEMODE_H
#define TIMER_BASEMODE_H

class BaseMode
{
protected:
    ~BaseMode() = default;

public:
    virtual void onActivated() = 0;
    virtual void onDeactivated() = 0;

    virtual void loop() = 0;

    virtual void modeButtonShortPress() = 0;
    virtual void downButtonShortPress() = 0;
    virtual void upButtonShortPress() = 0;
};

#endif //TIMER_BASEMODE_H