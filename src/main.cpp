#include <Arduino.h>
#include "KitchenTimer.h"

#define MODE_BUTTON_PIN  18
#define DOWN_BUTTON_PIN  17
#define UP_BUTTON_PIN  16

#define BUZZER_PIN  21

#define CLK_PIN 4
#define DIO_PIN 5

KitchenTimer kitchenTimer(
    MODE_BUTTON_PIN,
    UP_BUTTON_PIN,
    DOWN_BUTTON_PIN,
    BUZZER_PIN,
    CLK_PIN,
    DIO_PIN);

void setup() {
    Serial.begin(9600);

    kitchenTimer.setup();
}

void loop() {

    kitchenTimer.loop();
}
