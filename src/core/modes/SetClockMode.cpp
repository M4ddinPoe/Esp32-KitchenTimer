#include "SetClockMode.h"
#include <Arduino.h>

void SetClockMode::onActivated() 
{
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    hour = timeinfo.tm_hour;
    minute = timeinfo.tm_min;

    //display->setFirstBlinking(true);
    //display->setSecondBlinking(true);

    display->setFirstNumberBlinking(true);

    isActive = true;
    Serial.println("Set Clock Mode is activated");
}

void SetClockMode::onDeactivated() 
{
    isActive = false;
    Serial.println("Set Clock Mode is deactivated");
}

void SetClockMode::loop() 
{
    if (!isActive)
        return;

    if (display == nullptr) 
    {
        Serial.println("ERROR: display is null in SetClockMode");
        return;
    }

    display->set(
        hour / 10,
        hour % 10,
        minute / 10,
        minute % 10);
}

void SetClockMode::modeButtonShortPress() 
{
    if (setMinute) 
    {
        struct tm timeinfo;
        timeinfo.tm_year = 70;    // Platzhalter (1970, beliebiges Jahr)
        timeinfo.tm_mon  = 0;     // Platzhalter (Januar)
        timeinfo.tm_mday = 1;     // Platzhlater (1. Tag) 
        timeinfo.tm_hour = hour;
        timeinfo.tm_min  = minute;
        timeinfo.tm_sec  = 0;
        timeinfo.tm_isdst = -1;   // DST automatisch bestimmen

        time_t now = mktime(&timeinfo);
        struct timeval tv = { .tv_sec = now };
        settimeofday(&tv, NULL);
        
        display->setSecondNumberBlinking(false);

        setMinute = false;
        setModeCallback(CLOCK);
        return;
    }

    display->setFirstNumberBlinking(false);
    display->setSecondNumberBlinking(true);

    setMinute = true;
}

void SetClockMode::downButtonShortPress() 
{
    if (setMinute) 
        decrementMinute();
    else
        decrementHour();

    Serial.println("Time ist set to: " + String(hour) + " : " + String(minute));
}

void SetClockMode::upButtonShortPress() 
{
    if (setMinute) 
        incrementMinute();
    else
        incrementHour();

    Serial.println("Time ist set to: " + String(hour) + " : " + String(minute));
}

void SetClockMode::incrementMinute() 
{
    if (minute == 59)
        minute = 0;
    else
        minute++;
}

void SetClockMode::decrementMinute() 
{
    if (minute == 0)
        minute = 59;
    else
        minute--;
}

void SetClockMode::incrementHour() 
{
    if (hour == 23)
        hour = 0;
    else
        hour++;
}

void SetClockMode::decrementHour() 
{
    if (hour == 0)
        hour = 23;
    else
        hour--;
}
