#include <GL/glut.h>	// GLUT
#include <GL/gl.h>		// OpenGL32
#include <GL/glu.h>		// GLu32
#include <unistd.h>		// Time and sleeping

#define ESCAPE 27

int window;

/* Functions and procedures declaration */
void InitGL(int width, int height);
void ResizeGLScene(int width, int height);
void DrawGLScene();
void keyPressed(unsigned char key, int x, int y);

/* Main program */
int main(int argc, char **argv) {
	// Initialise GLUT state
	glutInit(&argc, argv);

	// Select type of display mode
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

	// Get a 640 x 480 window
	glutInitWindowSize(640, 480);

	// Top left the window position
	glutInitWindowPosition(0, 0);

	// Open a window
	window = glutCreateWindow("Rubik's Cube");

	// Register the function to do all OpenGL drawing
	glutDisplayFunc(&DrawGLScene);

	// If there are no events, redraw GLScene
	glutIdleFunc(&DrawGLScene);

	// Register the function called when window is resized
	glutReshapeFunc(&ResizeGLScene);

	// Register the function called when keypressed
	glutKeyboardFunc(&keyPressed);

	// Initialise window
	InitGL(640, 480);

	// Start event processing engine
	glutMainLoop();
	
	return 0;
}

/* Realisation of functions and procedures */
void InitGL(int width, int height) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Clear the background with color specified
	glClearDepth(1.0);						// Enales clearing of the depth buffer
	glDepthFunc(GL_LESS);					// The type of depth test to do
	glEnable(GL_DEPTH_TEST);				// Enables depth testing
	glShadeModel(GL_SMOOTH);				// Enables smooth color shading

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();						// Reset projection matrix

	gluPerspective(45.0f, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f);	// Calculate the aspect ratio of the window
	glMatrixMode(GL_MODELVIEW);
}

void ResizeGLScene(int width, int height) {
	if (height == 0) {						// Prevent division by zero
		height = 1;
	}

	glViewport(0, 0, width, height);		// Reset current viewport and perspective transformation

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void DrawGLScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear the screen and the depth buffer

	// Row 1 Front
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.9f, 0.1f);
	glVertex3f(0.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.1f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.9f, 0.1f);
	glVertex3f(1.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.1f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.9f, 0.1f);
	glVertex3f(2.1f, 0.9f, 0.1f);
	glEnd();

	// Row 2 Front
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.9f, 0.1f);
	glVertex3f(0.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.1f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.9f, 0.1f);
	glVertex3f(1.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.1f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.9f, 0.1f);
	glVertex3f(2.1f, 1.9f, 0.1f);
	glEnd();

	// Row 3 Front
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.9f, 0.1f);
	glVertex3f(0.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.1f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.9f, 0.1f);
	glVertex3f(1.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.1f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.9f, 0.1f);
	glVertex3f(2.1f, 2.9f, 0.1f);
	glEnd();

	// Row 1 Back
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.9f, 0.1f);
	glVertex3f(0.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.1f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.9f, 0.1f);
	glVertex3f(1.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(2.1f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.9f, 0.1f);
	glVertex3f(2.1f, 0.9f, 0.1f);
	glEnd();

	// Row 2 Back
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.9f, 0.1f);
	glVertex3f(0.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.1f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.9f, 0.1f);
	glVertex3f(1.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(2.1f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.9f, 0.1f);
	glVertex3f(2.1f, 1.9f, 0.1f);
	glEnd();

	// Row 3 Back
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.9f, 0.1f);
	glVertex3f(0.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.1f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.9f, 0.1f);
	glVertex3f(1.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(2.1f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.9f, 0.1f);
	glVertex3f(2.1f, 2.9f, 0.1f);
	glEnd();

	// Row 1 Bottom
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.9f, 0.1f);
	glVertex3f(0.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.1f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.9f, 0.1f);
	glVertex3f(1.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(2.1f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.9f, 0.1f);
	glVertex3f(2.1f, 0.9f, 0.1f);
	glEnd();

	// Row 2 Bottom
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.1f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.9f, 0.1f);
	glVertex3f(0.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.1f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.9f, 0.1f);
	glVertex3f(1.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(2.1f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.9f, 0.1f);
	glVertex3f(2.1f, 1.9f, 0.1f);
	glEnd();

	// Row 3 Bottom
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.1f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.9f, 0.1f);
	glVertex3f(0.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.1f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.9f, 0.1f);
	glVertex3f(1.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(2.1f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.9f, 0.1f);
	glVertex3f(2.1f, 2.9f, 0.1f);
	glEnd();

	glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
	usleep(100);

	if (key == ESCAPE) {
		glutDestroyWindow(window);
		exit(0);
	}
}
