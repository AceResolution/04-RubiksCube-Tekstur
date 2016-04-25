#ifndef MINICUBE_H
#define MINICUBE_H
#include <GL/glut.h>

#define FRONT 0
#define RIGHT 1
#define BACK 2
#define LEFT 3
#define TOP 4
#define DOWN 5

class minicube {
    // Positioning
    float size;
    float rx, ry, rz;
    float cx, cy, cz;

    // Coloring
    int face[6];

    // OpenGL related
    GLuint _textureId;

// Methods
public:
    // Constructor
    minicube(float _cx, float _cy, float _cz, float _size);

    // Getter
    float getCX() {return cx;};
    float getCY() {return cy;};
    float getCZ() {return cz;};

    // Rotate animation
    void rotateAnim(float angle, char dir);

    // Rotate by change face
    void rotateFace(char dir);

    // Drawing
    void setFaceColor(int fc, int color);
    void draw(GLuint tex);

private:
    // Helper
    void swapFace(int a, int b, int c, int d);
    void setColor(int color);
};

#endif // MINICUBE_H
