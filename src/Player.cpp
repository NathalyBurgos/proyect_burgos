#include "Player.h"
#include <Arduino.h>

#define LEFT_BUTTON 4
#define RIGHT_BUTTON 14
#define UP_BUTTON 15
#define DOWN_BUTTON 19

Player::Player(MD_MAX72XX* matrix) : mx(matrix), x(0), y(0) {}

void Player::begin() {
    pinMode(LEFT_BUTTON, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON, INPUT_PULLUP);
    pinMode(UP_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_BUTTON, INPUT_PULLUP);
}

void Player::update() {
    if (digitalRead(LEFT_BUTTON) == LOW) {
        x = max(0, x - 1);
        delay(150);
    }
    if (digitalRead(RIGHT_BUTTON) == LOW) {
        x = min(15, x + 1); // 16 columnas en total (0 a 15)
        delay(150);
    }
    if (digitalRead(UP_BUTTON) == LOW) {
        y = max(0, y - 1);
        delay(150);
    }
    if (digitalRead(DOWN_BUTTON) == LOW) {
        y = min(31, y + 1); // 32 filas en total (0 a 31)
        delay(150);
    }
}

void Player::draw() {
    mx->clear();
    mx->setPoint(x, y, true); // Nota: y es la fila, x es la columna
}

bool Player::checkCollision(Obstacles& obstacles) {
    for (int i = 0; i < Obstacles::NUM_OBSTACLES; i++) {
        if (x == obstacles.getObstacleX(i) && y == obstacles.getObstacleY(i)) {
            return true;  // Colisión detectada
        }
    }
    return false;  // No hay colisión
}

bool Player::checkWin() {
    if (y == 31) {  // Si el jugador ha llegado al final (y == 31)
        return true;
    }
    return false;
}
