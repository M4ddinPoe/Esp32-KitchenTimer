#include "ClockMode.h"

void ClockMode::onActivated() 
{
    isActive = true;
    Serial.println("Clock Mode is activated");
}

void ClockMode::onDeactivated() 
{
    isActive = false;
    Serial.println("Timer Mode is deactivated");
}

void ClockMode::loop() 
{
    if (!isActive)
        return;

    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    display->set(
        timeinfo.tm_hour / 10,  // Zehnerstelle Stunde
        timeinfo.tm_hour % 10,  // Einerstelle Stunde
        timeinfo.tm_min / 10,   // Zehnerstelle Minute
        timeinfo.tm_min % 10);  // Einerstelle Minute
}

void ClockMode::modeButtonShortPress() 
{    
    setModeCallback(TIMER1);
}

void ClockMode::downButtonShortPress() 
{
}

void ClockMode::upButtonShortPress() 
{
}
