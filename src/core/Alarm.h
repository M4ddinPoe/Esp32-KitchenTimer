#ifndef TIMER_ALARM_H
#define TIMER_ALARM_H

#include <Arduino.h>

class Alarm
{
public:
    Alarm(uint8_t buzzerPin) {
        this->buzzerPin = buzzerPin;
    };

    bool isPlaying = false;

    void setup();
    void play();
    void stop();

private:
    uint8_t buzzerPin;
    TaskHandle_t melodyTaskHandle = nullptr;

    static void playSound(void *pvParameters);
};

#endif //TIMER_ALARM_H