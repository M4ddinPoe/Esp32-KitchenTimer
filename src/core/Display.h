#ifndef TIMER_DISPLAY_H
#define TIMER_DISPLAY_H

#include <TM1637Display.h>

class Display
{
public:
    Display(int clkPin, int dioPin)
        : display(clkPin, dioPin)
    {
    }

    void setup();
    void set(short first = 0, short second = 0, short third = 0, short fourth = 0);

    void setFirstNumberBlinking(bool isBlinking);
    void setSecondNumberBlinking(bool isBlinking);

    void update();

private:
    TM1637Display display;
    short firstDigit = 0;
    short secondDigit = 0;
    short thirdDigit = 0;
    short fourthDigit = 0;

    bool isFirstNumberBlinking = false;
    bool isSecondNumberBlinking = false;

    bool isFadedOut = false;
    unsigned long nextBlinkChange = 0;

    uint8_t getCurrentEncodedDigitForFirstDigit();

    uint8_t getCurrentEncodedDigitForSecondDigit();

    uint8_t getCurrentEncodedDigitForThirdDigit();

    uint8_t getCurrentEncodedDigitForFourthDigit();
};

#endif //TIMER_DISPLAY_H