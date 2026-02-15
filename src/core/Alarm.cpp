#include "alarm.h"
#include <Arduino.h>
#include "melody.h"

void Alarm::setup()
{
    xTaskCreate(
        this->playSound,
        "PlayMelody",
        2048,
        (void*)&buzzerPin,
        1,
        &melodyTaskHandle // Task-Handle speichern, um den Task später zu steuern
    );

    vTaskSuspend(melodyTaskHandle);
}

void Alarm::play()
{
    isPlaying = true;
    vTaskResume(melodyTaskHandle);
    Serial.println("Alarm sound started");
}

void Alarm::stop()
{
    vTaskSuspend(melodyTaskHandle);
    noTone(buzzerPin);
    isPlaying = false;
    Serial.println("Alarm sound stopped");
}

void Alarm::playSound(void *pvParameters)
{
    uint8_t buzzerPin = *(uint8_t*)pvParameters;

    while (true) {
        for (int thisNote = 0; thisNote < 23; thisNote++) {
            int noteDuration = 1000 / noteDurations[thisNote];
            tone(buzzerPin,melody[thisNote], noteDuration);

            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            noTone(buzzerPin);
        }

        delay(500);
    }
}
