#include <vector>
#include <GL/glut.h>
#include "minicube.h"
#include "cube.h"

cube::cube() {
    dirx = 0;
    diry = 0;
    dirz = 0;
    // Create the minicubes
    int i,j,k;
    for(i=-1;i<2;i++) {
        for(j=-1;j<2;j++) {
            for(k=-1;k<2;k++) {
                minicube mc = minicube(i,j,k,0.9);
                if(i==1) {
                    mc.setFaceColor(RIGHT,0);
                } else if(i==-1) {
                    mc.setFaceColor(LEFT,1);
                }
                if(j==1) {
                    mc.setFaceColor(TOP,2);
                } else if(j==-1) {
                    mc.setFaceColor(DOWN,3);
                }
                if(k==1) {
                    mc.setFaceColor(FRONT,4);
                } else if(k==-1) {
                    mc.setFaceColor(BACK,5);
                }
                cubes.push_back(mc);
            }
        }
    }
}
void cube::rotateCubesAnim(char code, float angle) {
    int i;

    char rt;
    int ot = 2;
    switch(code) {
        case 'r': rt = 'X'; ot = 1; break;
        case 'R': rt = 'x'; ot = 1; break;
        case 'l': rt = 'x'; ot = -1; break;
        case 'L': rt = 'X'; ot = -1; break;
        case 't': rt = 'Y'; ot = 1; break;
        case 'T': rt = 'y'; ot = 1; break;
        case 'd': rt = 'y'; ot = -1; break;
        case 'D': rt = 'Y'; ot = -1; break;
        case 'f': rt = 'Z'; ot = 1; break;
        case 'F': rt = 'z'; ot = 1; break;
        case 'b': rt = 'z'; ot = -1; break;
        case 'B': rt = 'Z'; ot = -1; break;
    }
    if (rt=='x'||rt=='X') {
        for(i=0;i<cubes.size();i++) {
            if (cubes[i].getCX()==ot) cubes[i].rotateAnim(angle,rt);
        }
    } else
    if (rt=='y'||rt=='Y') {
        for(i=0;i<cubes.size();i++) {
            if (cubes[i].getCY()==ot) cubes[i].rotateAnim(angle,rt);
        }
    } else
    if (rt=='z'||rt=='Z') {
        for(i=0;i<cubes.size();i++) {
            if (cubes[i].getCZ()==ot) cubes[i].rotateAnim(angle,rt);
        }
    }
}

void cube::rotateCubesFace(char code) {
    int i;

    char rt;
    int ot;
    switch(code) {
        case 'r': rt = 'X'; ot = 1; break;
        case 'R': rt = 'x'; ot = 1; break;
        case 'l': rt = 'x'; ot = -1; break;
        case 'L': rt = 'X'; ot = -1; break;
        case 't': rt = 'Y'; ot = 1; break;
        case 'T': rt = 'y'; ot = 1; break;
        case 'd': rt = 'y'; ot = -1; break;
        case 'D': rt = 'Y'; ot = -1; break;
        case 'f': rt = 'Z'; ot = 1; break;
        case 'F': rt = 'z'; ot = 1; break;
        case 'b': rt = 'z'; ot = -1; break;
        case 'B': rt = 'Z'; ot = -1; break;
    }

    if (rt=='x'||rt=='X') {
        for(i=0;i<cubes.size();i++) {
            if (cubes[i].getCX()==ot) cubes[i].rotateFace(rt);
        }
    } else
    if (rt=='y'||rt=='Y') {
        for(i=0;i<cubes.size();i++) {
            if (cubes[i].getCY()==ot) cubes[i].rotateFace(rt);
        }
    } else
    if (rt=='z'||rt=='Z') {
        for(i=0;i<cubes.size();i++) {
            if (cubes[i].getCZ()==ot) cubes[i].rotateFace(rt);
        }
    }
}

void cube::draw(GLuint texture) {
    glPushMatrix();
    glRotatef(dirx,1.0f,0.0f,0.0f);
    glRotatef(dirz,0.0f,0.0f,1.0f);
    glRotatef(diry,0.0f,1.0f,0.0f);
    int i;
    for (i=0;i<cubes.size();i++) {
        cubes[i].draw(texture);
    }
    glPopMatrix();
}
