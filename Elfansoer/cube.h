#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include "minicube.h"

class cube {
    // Members
    std::vector<minicube> cubes;

    // Positioning

public:
    float dirx, diry, dirz;
    // Methods
    // Constructor
    cube();

    void rotateCubesAnim(char code, float angle);
    void rotateCubesFace(char code);
    // Drawing
    void draw(GLuint texture);
};

#endif // CUBE_H
