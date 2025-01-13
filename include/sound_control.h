#ifndef SOUND_CONTROL_H
#define SOUND_CONTROL_H

// Definición de pines para los zumbadores
#define BUZZER_LOST_PIN  13  // Cambia al pin que estés usando para el zumbador de "perdedor"
#define BUZZER_WON_PIN   12  // Cambia al pin que estés usando para el zumbador de "ganador"
#define POT_PIN          34  // Cambia al pin del potenciómetro

// Declaración de las funciones
void setupSoundControl();
void playLostSound(int duration);
void playWonSound(int duration);
int readPotentiometer();

#endif // SOUND_CONTROL_H
