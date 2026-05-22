

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, 0, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5,0,
  NOTE_E5,NOTE_F5,NOTE_G5, 0 , NOTE_E5,NOTE_F5,NOTE_G5,0,
  NOTE_G5,NOTE_A5,NOTE_G5,NOTE_F5,NOTE_E5,NOTE_C5,0,NOTE_G5,NOTE_A5,NOTE_G5,NOTE_F5,NOTE_E5,NOTE_C5,0,
  NOTE_C5,NOTE_G4,NOTE_C5,0,NOTE_C5,NOTE_G4,NOTE_C5,0

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 8,4, 4, 4, 4,8,
  4,4,2,8,4,4,2,8,
  8,8,8,8,4,4,16,8,8,8,8,4,4,8,
  4, 4 ,2,8,4,4,2,8
};
int ledcon[]={
  2,3,4,2,10,2,3,4,2,10,
  4,5,6,10,4,5,6,10,
  6,7,6,5,4,2,10,6,7,6,5,4,2,10,
  2,9,2,10,2,9,2,10

};


const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};


void setup() {
  // iterate over the notes of the melody:
   for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // no need to repeat the melody.

  for (int thisNote = 0; thisNote < 40; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(12, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    digitalWrite(ledcon[thisNote],HIGH);

    delay(pauseBetweenNotes);
    digitalWrite(ledcon[thisNote],LOW);
    // stop the tone playing:
    noTone(12);
  }
}
