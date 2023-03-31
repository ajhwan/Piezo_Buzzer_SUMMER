#include "pitches.h"

#define melodyPin 9

unsigned long prevPlayTime = 0;
unsigned long playDuration = 0;
int currentMelody = 0;

//Mario main theme melody
int melodySize = 75;
int melody[] = {
  NOTE_G5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_C6, 0,  0,
  NOTE_G5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_D6, 0, NOTE_E6, 0, NOTE_E6, 0,
  NOTE_G5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_C6, 0,  0,  
  NOTE_G5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_D6, 0, NOTE_G6, 0, NOTE_E6, 0,
  NOTE_E6, NOTE_F6, NOTE_G6, NOTE_G6, NOTE_G6, 0, NOTE_G6, NOTE_G6, NOTE_E6, NOTE_C6, 0,
  NOTE_E6, NOTE_F6, NOTE_G6, NOTE_G6, NOTE_G6, 0, NOTE_G6, NOTE_G6, NOTE_E6, NOTE_C6, 0,
  NOTE_C6, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_E6, 0, NOTE_E6, NOTE_E6, NOTE_A6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_D6, 0
};
//Mario main them tempo
int tempo[] = {
  8, 8, 8, 8, 4, 8, 8, 2, 2, 
  8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 4, 8, 8, 2, 2,
  8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4,
  4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4,
  4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4,
  8, 8, 4, 8, 8, 4, 4, 4, 4, 8, 8, 8, 4, 1, 4
};

void sing() {
    if(millis() < prevPlayTime + playDuration) {
        // music is playing. do nothing
        return;
    }
    // stop the tone playing:
    noTone(8);
    
    if(currentMelody >= melodySize)
        currentMelody = 0;
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/tempo[currentMelody];

    tone(melodyPin, melody[currentMelody], noteDuration);
    prevPlayTime = millis();
    playDuration = noteDuration * 1.30;
    
    currentMelody++;
}

void setup() {
	pinMode(melodyPin, OUTPUT);
}

void loop() {
	// Do what you want

	// play music
	sing();
}