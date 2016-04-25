#include <iostream>
#include <GL/glut.h>
#include "imageloader.h"
#include "minicube.h"
#include "cube.h"

using namespace std;

// GLOBAL VARIABLES AND FUNCTIONS
cube Cube;
float rotx = 0.0f, roty = 0.0f, rotz = 0.0f;
char direction;
bool animating;
void rotationMain(int x);
GLuint _textureId;

// OPENGL-RELATED FUNCTIONS
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void initialize(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Initialize Window
    glutInitWindowSize(500,500);
    glutCreateWindow("Opengl");

    // Enables
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);

	Image* image = loadBMP("gbr.bmp");
	_textureId = loadTexture(image);
	delete image;
}
void drawWindow(int w, int h) {
    // Set perspective
	glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0,
        (double)w/(double)h,
        1.0f,
        100.0f
    );
}
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'r':
        case 'R':
        case 'l':
        case 'L':
        case 't':
        case 'T':
        case 'd':
        case 'D':
        case 'f':
        case 'F':
        case 'b':
        case 'B': if(!animating) {direction = key; rotationMain(0); glutPostRedisplay(); } break;

        case 'z': Cube.dirx = Cube.dirx + 1; glutPostRedisplay(); break;
        case 'Z': Cube.dirx = Cube.dirx - 1; glutPostRedisplay(); break;
        case 'x': Cube.diry = Cube.diry + 1; glutPostRedisplay(); break;
        case 'X': Cube.diry = Cube.diry - 1; glutPostRedisplay(); break;
        case 'c': Cube.dirz = Cube.dirz + 1; glutPostRedisplay(); break;
        case 'C': Cube.dirz = Cube.dirz - 1; glutPostRedisplay(); break;

        case 'q': exit(0); return;
    }
}
void initScene() {
    // Clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set drawing mode
    glMatrixMode(GL_MODELVIEW);

    // Draw scene
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-7.0f);

    // Draw lighting
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    //Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightColor1[] = {0.7f, 0.7f, 0.7f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    // Draw the cube
    Cube.draw(_textureId);

    glutSwapBuffers();
}

// MAIN PROGRAM
int main(int argc, char** argv) {
    initialize(argc,argv);
    glutDisplayFunc(initScene);
    glutReshapeFunc(drawWindow);
    //glutIdleFunc(idle);
    glutKeyboardFunc(handleKeypress);

    glutMainLoop();
    return 0;
}

// REALIZATION OF FUNCTIONS
void rotationMain(int x) {
    if (x<=90) {
        glutTimerFunc(5,rotationMain,x+1);
        animating = true;
        Cube.rotateCubesAnim(direction,x);
        glutPostRedisplay();
    } else {
        Cube.rotateCubesAnim(direction,0);
        Cube.rotateCubesFace(direction);
        animating = false;
        glutPostRedisplay();
    }
}
