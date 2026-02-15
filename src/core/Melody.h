#ifndef TIMER_MELODY_H
#define TIMER_MELODY_H

#include "pitches.h"

int melody[] = {
        NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4,
        0,
        NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5,
        0,
        NOTE_F5, NOTE_E5, NOTE_F5, NOTE_A4,
        0,
        NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_D5, NOTE_C5
      };

int noteDurations[] = {
        8, 8, 2, 2,
        4,
        8, 8, 4, 4, 2,
        4,
        8, 8, 2, 2,
        4,
        8, 8, 4, 4, 4, 4, 2
      };

#endif //TIMER_MELODY_H