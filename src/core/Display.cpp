#include "display.h"
#include <Arduino.h>

void Display::setup() 
{
    this->display.clear();
    this->display.setBrightness(5);

    nextBlinkChange = millis() + 250;
}

void Display::set(short first, short second, short third, short fourth) 
{
    firstDigit = first;
    secondDigit = second;
    thirdDigit = third;
    fourthDigit= fourth;
}

void Display::setFirstNumberBlinking(bool isBlinking)
{
    isFirstNumberBlinking = isBlinking;
}

void Display::setSecondNumberBlinking(bool isBlinking)
{
    isSecondNumberBlinking = isBlinking;
}

void Display::update() 
{
    if ((isFirstNumberBlinking || isSecondNumberBlinking) && isFadedOut)
    {
        uint8_t data[] =
        {
            getCurrentEncodedDigitForFirstDigit(),
            getCurrentEncodedDigitForSecondDigit(),
            getCurrentEncodedDigitForThirdDigit(),
            getCurrentEncodedDigitForFourthDigit()
        };

        display.setSegments(data);
    }
    else
    {
        int number = firstDigit * 1000 + secondDigit * 100 + thirdDigit * 10 + fourthDigit;
        display.showNumberDecEx(number, 0b01000000, true, 4, 0);
    }

    if (millis() > nextBlinkChange)
    {
        isFadedOut = !isFadedOut;
        nextBlinkChange = millis() + 250;
    }
}

uint8_t Display::getCurrentEncodedDigitForFirstDigit() 
{
    if (isFirstNumberBlinking && isFadedOut)
        return 0x00;

    return display.encodeDigit(firstDigit);
}

uint8_t Display::getCurrentEncodedDigitForSecondDigit() 
{
    if (isFirstNumberBlinking && isFadedOut)
        return 0x00;

    return Display::display.encodeDigit(secondDigit);
}

uint8_t Display::getCurrentEncodedDigitForThirdDigit() 
{
    if (isSecondNumberBlinking && isFadedOut)
        return 0x00;

    return display.encodeDigit(thirdDigit);
}

uint8_t Display::getCurrentEncodedDigitForFourthDigit() 
{
    if (isSecondNumberBlinking && isFadedOut)
        return 0x00;

    return display.encodeDigit(fourthDigit);
}
