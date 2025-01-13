#ifndef PLAYER_H
#define PLAYER_H

#include <MD_MAX72XX.h>
#include "Obstacles.h"

class Player {
public:
    Player(MD_MAX72XX* matrix);
    void begin();
    void update();
    void draw();
    bool checkCollision(Obstacles& obstacles);
    bool checkWin(); // Función para verificar si el jugador ha ganado

private:
    MD_MAX72XX* mx;
    int x;
    int y;
};

#endif
