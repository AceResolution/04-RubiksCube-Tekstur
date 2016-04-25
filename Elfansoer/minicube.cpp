#include "minicube.h"
#include <GL/glut.h>

minicube::minicube(float _cx, float _cy, float _cz, float _size) {
    cx = _cx;
    cy = _cy;
    cz = _cz;
    rx = 0;
    ry = 0;
    rz = 0;
    size = _size;
    for (int i=0;i<6;i++) {
        face[i] = 6;
    }

}

void minicube::rotateAnim(float angle, char dir) {
    if(angle>360) {
        angle=angle-360;
    } else if(angle<0) {
        angle+360;
    }

    switch(dir) {
        case 'x': rx = angle; break;
        case 'X': rx = -angle; break;
        case 'y': ry = angle; break;
        case 'Y': ry = -angle; break;
        case 'z': rz = angle; break;
        case 'Z': rz = -angle; break;
    }
}

void minicube::rotateFace(char dir) {
    // Change faces' color according to rotation direction.
    // Rotation follows thumbs rule, with capital means its inverse
    float temp;
    switch(dir) {
    case 'x': temp = cy; cy = -cz; cz = temp; swapFace(TOP,FRONT,DOWN,BACK); break;
    case 'X': temp = cz; cz = -cy; cy = temp; swapFace(TOP,BACK,DOWN,FRONT); break;
    case 'y': temp = cz; cz = -cx; cx = temp; swapFace(FRONT,RIGHT,BACK,LEFT); break;
    case 'Y': temp = cx; cx = -cz; cz = temp; swapFace(FRONT,LEFT,BACK,RIGHT); break;
    case 'z': temp = cx; cx = -cy; cy = temp; swapFace(RIGHT,TOP,LEFT,DOWN); break;
    case 'Z': temp = cy; cy = -cx; cx = temp; swapFace(RIGHT,DOWN,LEFT,TOP); break;
    }
}

void minicube::setFaceColor(int fc, int color) {
    face[fc] = color;
}

void minicube::draw(GLuint tex) {
    glPushMatrix();
        // Rotate about axis when animated
        glRotatef(rx,1.0f,0.0f,0.0f);
        glRotatef(ry,0.0f,1.0f,0.0f);
        glRotatef(rz,0.0f,0.0f,1.0f);

        glPushMatrix();
            // Translate position
            glTranslatef(cx,cy,cz);

//            glEnable(GL_TEXTURE_2D);
//            glBindTexture(GL_TEXTURE_2D, tex);
//
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glBegin(GL_QUADS);
                //Top face

                setColor(face[TOP]);
                glNormal3f(0.0f, 1.0f, 0.0f);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-size / 2, size / 2, -size / 2);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(-size / 2, size / 2, size / 2);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(size / 2, size / 2, size / 2);
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(size / 2, size / 2, -size / 2);
            glEnd();
//            glDisable(GL_TEXTURE_2D);

                //Bottom face
            glBegin(GL_QUADS);
                setColor(face[DOWN]);
                glNormal3f(0.0f, -1.0f, 0.0f);
                glVertex3f(-size / 2, -size / 2, -size / 2);
                glVertex3f(size / 2, -size / 2, -size / 2);
                glVertex3f(size / 2, -size / 2, size / 2);
                glVertex3f(-size / 2, -size / 2, size / 2);

                //Left face
                setColor(face[LEFT]);
                glNormal3f(-1.0f, 0.0f, 0.0f);
                glVertex3f(-size / 2, -size / 2, -size / 2);
                glVertex3f(-size / 2, -size / 2, size / 2);
                glVertex3f(-size / 2, size / 2, size / 2);
                glVertex3f(-size / 2, size / 2, -size / 2);

                //Right face
                setColor(face[RIGHT]);
                glNormal3f(1.0f, 0.0f, 0.0f);
                glVertex3f(size / 2, -size / 2, -size / 2);
                glVertex3f(size / 2, size / 2, -size / 2);
                glVertex3f(size / 2, size / 2, size / 2);
                glVertex3f(size / 2, -size / 2, size / 2);

                //Front face
                setColor(face[FRONT]);
                glNormal3f(0.0f, 0.0f, 1.0f);
                glVertex3f(-size / 2, -size / 2, size / 2);
                glVertex3f(size / 2, -size / 2, size / 2);
                glVertex3f(size / 2, size / 2, size / 2);
                glVertex3f(-size / 2, size / 2, size / 2);

                //Back face
                setColor(face[BACK]);
                glNormal3f(0.0f, 0.0f, -1.0f);
                glVertex3f(-size / 2, -size / 2, -size / 2);
                glVertex3f(-size / 2, size / 2, -size / 2);
                glVertex3f(size / 2, size / 2, -size / 2);
                glVertex3f(size / 2, -size / 2, -size / 2);
            glEnd();
        glPopMatrix();
    glPopMatrix();

}

void minicube::swapFace(int a, int b, int c, int d) {
    // Rotate face for rotFace function.
    // a->b->c->d->a
    int temp;
    temp = face[a];
    face[a] = face[d];
    face[d] = face[c];
    face[c] = face[b];
    face[b] = temp;
}

void minicube::setColor(int color) {
    switch (color) {
        case 0: glColor3f(1.0f,0.0f,0.0f); break;
        case 1: glColor3f(0.0f,1.0f,0.0f); break;
        case 2: glColor3f(0.0f,0.0f,1.0f); break;
        case 3: glColor3f(0.0f,1.0f,1.0f); break;
        case 4: glColor3f(1.0f,0.0f,1.0f); break;
        case 5: glColor3f(1.0f,1.0f,0.0f); break;
        case 6: glColor3f(0.0f,0.0f,0.0f); break;
    }
}
