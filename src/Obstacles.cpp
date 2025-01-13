#include "Obstacles.h"

Obstacles::Obstacles(MD_MAX72XX* matrix) : mx(matrix) {
    // Inicializar posiciones y direcciones de los obstáculos
    obstacleX[0] = 7;   obstacleY[0] = 5;   obstacleDirection[0] = -1;
    obstacleX[1] = 15;  obstacleY[1] = 10;  obstacleDirection[1] = -1;
    obstacleX[2] = 12;  obstacleY[2] = 20;  obstacleDirection[2] = -1;
    obstacleX[3] = 0;   obstacleY[3] = 8;   obstacleDirection[3] = 1;  // Nuevo obstáculo
    obstacleX[4] = 0;   obstacleY[4] = 15;  obstacleDirection[4] = 1;  // Nuevo obstáculo
}

void Obstacles::begin() {}

void Obstacles::update() {
    for (int i = 0; i < NUM_OBSTACLES; i++) {
        obstacleX[i] += obstacleDirection[i];
        
        // Ajustar las posiciones cuando salen de la pantalla
        if (obstacleDirection[i] == -1 && obstacleX[i] < 0) {
            obstacleX[i] = 15;  // Vuelve al final de la matriz desde la izquierda
        } else if (obstacleDirection[i] == 1 && obstacleX[i] > 15) {
            obstacleX[i] = 0;  // Vuelve al inicio de la matriz desde la derecha
        }
    }
}

void Obstacles::draw() {
    for (int i = 0; i < NUM_OBSTACLES; i++) {
        mx->setPoint(obstacleX[i], obstacleY[i], true);
    }
}

int Obstacles::getObstacleX(int index) {
    if (index >= 0 && index < NUM_OBSTACLES) {
        return obstacleX[index];
    }
    return -1;
}

int Obstacles::getObstacleY(int index) {
    if (index >= 0 && index < NUM_OBSTACLES) {
        return obstacleY[index];
    }
    return -1;
}

void Obstacles::reset() {
    obstacleX[0] = 7;   obstacleY[0] = 5;   obstacleDirection[0] = -1;
    obstacleX[1] = 15;  obstacleY[1] = 10;  obstacleDirection[1] = -1;
    obstacleX[2] = 12;  obstacleY[2] = 20;  obstacleDirection[2] = -1;
    obstacleX[3] = 0;   obstacleY[3] = 8;   obstacleDirection[3] = 1;
    obstacleX[4] = 0;   obstacleY[4] = 15;  obstacleDirection[4] = 1;
}
