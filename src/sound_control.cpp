#include "sound_control.h"
#include <Arduino.h>

#define BUZZER_LOST_PIN 13
#define BUZZER_WON_PIN 12
#define POT_PIN 34

void setupSoundControl();
void playLostSound(int duration);
void playWonSound(int duration);
int readPotentiometer();
void buzz(int Buzzer, long frequency, long length); // Prototipo de la función 'buzz'

void setupSoundControl() {
    pinMode(BUZZER_LOST_PIN, OUTPUT);
    pinMode(BUZZER_WON_PIN, OUTPUT);
    Serial.begin(115200);
}

// Sonido de "perdedor"
void playLostSound(int duration) {
    int melody[] = {
        523, 440, 349, 440, 523, 349, 440, 392  // Frecuencias (C5, A4, F4, A4, C5, F4, A4, G4)
    };

    int tempo[] = {
        4, 4, 4, 4, 4, 4, 4, 4
    };

    for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
        int noteDuration = 1000 / tempo[thisNote]; // Duración de la nota en milisegundos
        buzz(BUZZER_LOST_PIN, melody[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        buzz(BUZZER_LOST_PIN, 0, noteDuration); // Silenciar el buzzer entre notas
    }
}

// Sonido de "ganador" más largo
void playWonSound(int duration) {
    int melody[] = {
        784, 880, 784, 698, 784, 880, 784, 523, 
        523, 523, 523, 698, 784, 880, 784, 698,
        523, 523, 523, 523, 784, 880, 784, 698, 
        784, 880, 784, 698, 523, 523, 523, 523, 
        880, 784, 698, 523, 784, 880, 784, 698, 
        784, 523
    };

    int tempo[] = {
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4
    };

    for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
        int noteDuration = 1500 / tempo[thisNote]; // Duración de la nota en milisegundos
        buzz(BUZZER_WON_PIN, melody[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        buzz(BUZZER_WON_PIN, 0, noteDuration); // Silenciar el buzzer entre notas
    }
}

int readPotentiometer() {
    int potValue = analogRead(POT_PIN);
    Serial.print("Potentiometer Value: ");
    Serial.println(potValue);
    return potValue;
}

void buzz(int Buzzer, long frequency, long length) {
    long delayValue = 1000000 / frequency / 2; // Cálculo del valor de delay para la frecuencia
    long numCycles = frequency * length / 1000; // Número de ciclos para la duración de la nota
    for (long i = 0; i < numCycles; i++) {
        digitalWrite(Buzzer, HIGH); 
        delayMicroseconds(delayValue); // Tiempo de encendido
        digitalWrite(Buzzer, LOW); 
        delayMicroseconds(delayValue); // Tiempo de apagado
    }
}
