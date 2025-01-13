#include <Arduino.h>
#include <MD_MAX72XX.h>
#include "Player.h"
#include "Obstacles.h"
#include "sound_control.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // Biblioteca para la pantalla LCD

// Configuración de la matriz
#define DATA_PIN 23
#define CLK_PIN 18
#define CS_PIN 5
#define MAX_DEVICES 8  // 8 módulos de 8x8 (dos matrices de 8x32)

#include "apwifieeprommode.h"
#include <EEPROM.h>

// Configuración de la pantalla LCD
LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01 , 16, 2);  // Dirección I2C y tamaño de LCD 1602

MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
Player player(&mx);
Obstacles obstacles(&mx);

// Variable para indicar si el juego está en estado inicial
bool juegoActivo = true;
unsigned long previousMillis = 0;  // Variable para controlar el temporizador
const long interval = 2000;  // Intervalo de 2 segundos para mostrar el mensaje

void setup() {
    Serial.begin(115200);
    intentoconexion("Wifi_GalvezBurgos", "12341243");
    mx.begin();
    mx.clear();
    setupSoundControl();  // Configurar los sonidos

    player.begin();
    obstacles.begin();

    // Configuración de la pantalla LCD y mensaje de bienvenida
    Wire.begin(21, 22);  // Pines SDA=21, SCL=22
    lcd.init();          // Inicializar la pantalla LCD
    lcd.backlight();     // Asegurarse de que la retroiluminación esté encendida
    lcd.setCursor(0, 0);
    lcd.print("Bienvenido al");
    lcd.setCursor(0, 1);
    lcd.print("juego!");
}

void mostrarMensajeLCD(const String& mensaje1, const String& mensaje2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(mensaje1);
    lcd.setCursor(0, 1);
    lcd.print(mensaje2);
}

void loop() {
    player.update();
    player.draw();
    obstacles.update();
    obstacles.draw();

    // Leer el valor del potenciómetro para ajustar la duración del sonido
    int potValue = readPotentiometer();
    int toneDuration = map(potValue, 0, 4095, 150, 1000);  // Mapeo de duración

    // Verificar si el jugador colisiona con un obstáculo (perdedor)
    if (player.checkCollision(obstacles) ) {
        playLostSound(toneDuration);  // Sonido de "perdedor"
        mostrarMensajeLCD("Perdiste", "la partida");  // Mensaje de "perdedor"
        previousMillis = millis();  // Iniciar el temporizador
        juegoActivo = false;  // Cambiar el estado del juego
    }
    

    // Verificar si el jugador ha ganado
    if (player.checkWin() && juegoActivo) {
        playWonSound(toneDuration);  // Sonido de "ganador"
        mostrarMensajeLCD("Ganaste", "la partida");  // Mensaje de "ganador"
        previousMillis = millis();  // Iniciar el temporizador
        juegoActivo = false;  // Cambiar el estado del juego
    }

    // Si el juego está en estado inactivo, esperar hasta el temporizador para reiniciar
    if (!juegoActivo) {
        if (millis() - previousMillis >= interval) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Bienvenido al");
            lcd.setCursor(0, 1);
            lcd.print("juego!");
            player = Player(&mx);  // Reiniciar la posición del jugador
            obstacles.reset();  // Restablecer los obstáculos
            juegoActivo = true;  // Reiniciar el estado del juego
        }
    }

    delay(100);  // Pausa pequeña para controlar la velocidad del juego
}
void resetGame() {
    player.begin();  // Reiniciar la posición del jugador
    obstacles.reset();  // Restablecer los obstáculos
    juegoActivo = true;  // Cambiar el estado del juego para comenzar un nuevo juego
}