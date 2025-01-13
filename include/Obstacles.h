#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <MD_MAX72XX.h>

class Obstacles {
public:
    Obstacles(MD_MAX72XX* matrix);
    void begin();
    void update();
    void draw();
    void reset(); 
    int getObstacleX(int index);  // Función para obtener la coordenada X del obstáculo
    int getObstacleY(int index);  // Función para obtener la coordenada Y del obstáculo

public:
    MD_MAX72XX* mx;
    static const int NUM_OBSTACLES = 5;
    int obstacleX[NUM_OBSTACLES];
    int obstacleY[NUM_OBSTACLES];
    int obstacleDirection[NUM_OBSTACLES];
};

#endif
