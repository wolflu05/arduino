#include "pitches.h"

#define TONE_PIN 11

#define A 8
#define V 4
#define H 2
#define G 1

int noten[][2] = {
    {NOTE_C4, A}, {NOTE_D4, A}, {NOTE_E4, A}, {NOTE_F4, A}, {NOTE_G4, V}, {NOTE_G4, V},
    {NOTE_A4, A}, {NOTE_A4, A}, {NOTE_A4, A}, {NOTE_A4, A}, {NOTE_G4, H},
    {NOTE_A4, A}, {NOTE_A4, A}, {NOTE_A4, A}, {NOTE_A4, A}, {NOTE_G4, H},
    {NOTE_F4, A}, {NOTE_F4, A}, {NOTE_F4, A}, {NOTE_F4, A}, {NOTE_E4, V}, {NOTE_E4, V},
    {NOTE_D4, A}, {NOTE_D4, A}, {NOTE_D4, A}, {NOTE_D4, A}, {NOTE_C4, H},
};

void setup()
{
}

void loop()
{
    for (int i = 0; i < (sizeof(noten) / sizeof(noten[0])); i++)
    {
        int zeit = 1000 / noten[i][1];
        tone(TONE_PIN, noten[i][0], zeit);
        delay(zeit * 1.30);
        noTone(TONE_PIN);
    }
}
