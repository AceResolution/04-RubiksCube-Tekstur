/* display.c : Fonctions d'affichage du cube
 *             displaying functions (using OpenGL)
	modif oleh AceOneWorks (Nizam, EC, Elfansoer)
 *
 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * Rubik's Cube Simulator !                 Copyright (C) 2002, AnTiKoNs *
 *------------------------/                                              *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * The author of this program may be contacted at antikons@ifrance.com   *
 *                                                                       *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <GL/glut.h>
#include "_cube.h"

#include "rotate_animation_threads.h"


CUBE *pcube;
int Window;
double rx=0,ry=0,rz=0;	//Angles
double zoom=-12; //zoom

void display( CUBE *cube )
{
  pcube = cube;
}


void setColor( COLOR color )
{
  switch(color) {
  case W:	//I,blanc,white
    glColor3d(1,1,1);
    break;
  case R:	//R,rouge,red
    glColor3d(1,0,0);
    break;
  case B:	//B,bleu,blue
    glColor3d(0,0,1);
    break;
  case G:	//V,vert,green
    glColor3d(0,1,0);
    break;
  case Y:	//J,jaune,yellow
    glColor3d(1,1,0);
    break;
  case O:	//O,orange
    glColor3d(1,0.5,0);
    break;
  case N:	//no color (black)
    glColor3d(0.2,0.2,0.2);
  }
}

void drawcubelet( CUBELET *cubelet )
{
  glBegin(GL_QUADS);
  //face 0
  setColor(cubelet->face[0]);
  glVertex3i(1,1,1);
  glVertex3i(1,-1,1);
  glVertex3i(-1,-1,1);
  glVertex3i(-1,1,1);
  //face 1
  setColor(cubelet->face[1]);
  glVertex3i(-1,1,-1);
  glVertex3i(-1,1,1);
  glVertex3i(1,1,1);
  glVertex3i(1,1,-1);
  //face 2
  setColor(cubelet->face[2]);
  glVertex3i(1,1,1);
  glVertex3i(1,-1,1);
  glVertex3i(1,-1,-1);
  glVertex3i(1,1,-1);
  //face 3
  setColor(cubelet->face[3]);
  glVertex3i(-1,-1,-1);
  glVertex3i(-1,-1,1);
  glVertex3i(1,-1,1);
  glVertex3i(1,-1,-1);
  //face 4
  setColor(cubelet->face[4]);
  glVertex3i(-1,1,1);
  glVertex3i(-1,-1,1);
  glVertex3i(-1,-1,-1);
  glVertex3i(-1,1,-1);
  //face 5
  setColor(cubelet->face[5]);
  glVertex3i(1,1,-1);
  glVertex3i(1,-1,-1);
  glVertex3i(-1,-1,-1);
  glVertex3i(-1,1,-1);
  glEnd();
}

void rotateAroundAxisd(double axisx, double axisy, double axisz,
			double angle, int x, int y, int z){
  glTranslated(axisx,axisy,axisz);
  glRotated(angle,x,y,z);
  glTranslated(-axisx,-axisy,-axisz);
}

void draw(void)
{
  //	a+=2;
  //	b+=1.6;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslated(0,0,zoom);// Equivaut exactement à gluLookAt(0,0,5,0,0,0,0,1,0);
  glRotated(rx,1,0,0);
  glRotated(ry,0,1,0);
  glRotated(rz,0,0,1);

  glColorMaterial(GL_FRONT_AND_BACK,GL_SPECULAR);
  //Ca marche aussi avec specular !

  glTranslated(-2.5,-2.5,-2.5);

  rotateAroundAxisd(2.5,2.5,0,
		-pcube->p_angle,0,0,1);
  rotateAroundAxisd(2.5,0,2.5,
		-pcube->b_angle,0,1,0);
  rotateAroundAxisd(0,2.5,2.5,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][0][2]));
  rotateAroundAxisd(0,2.5,2.5,
		pcube->g_angle,1,0,0);
  rotateAroundAxisd(2.5,0,2.5,
		pcube->b_angle,0,1,0);
  rotateAroundAxisd(2.5,2.5,0,
		pcube->p_angle,0,0,1);
  glTranslated(2.5,0,0);
  rotateAroundAxisd(0,2.5,0,
		-pcube->p_angle,0,0,1);
  rotateAroundAxisd(0,0,2.5,
		-pcube->b_angle,0,1,0);
  drawcubelet(&(pcube->cubelet[1][0][2]));
  rotateAroundAxisd(0,0,2.5,
		pcube->b_angle,0,1,0);
  rotateAroundAxisd(0,2.5,0,
		pcube->p_angle,0,0,1);
  glTranslated(2.5,0,0);

  rotateAroundAxisd(-2.5,2.5,0,
		-pcube->p_angle,0,0,1);
  rotateAroundAxisd(-2.5,0,2.5,
		-pcube->b_angle,0,1,0);
  rotateAroundAxisd(0,2.5,2.5,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][0][2]));
  rotateAroundAxisd(0,2.5,2.5,
		pcube->d_angle,1,0,0);
  rotateAroundAxisd(-2.5,0,2.5,
		pcube->b_angle,0,1,0);
  rotateAroundAxisd(-2.5,2.5,0,
		pcube->p_angle,0,0,1);

  glTranslated(0,2.5,0);

  rotateAroundAxisd(-2.5,0,0,
		-pcube->p_angle,0,0,1);
  rotateAroundAxisd(0,0,2.5,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][1][2]));
  rotateAroundAxisd(0,0,2.5,
		pcube->d_angle,1,0,0);
  rotateAroundAxisd(-2.5,0,0,
		pcube->p_angle,0,0,1);

  glTranslated(-2.5,0,0);

  rotateAroundAxisd(0,0,0,
		-pcube->p_angle,0,0,1);
  drawcubelet(&(pcube->cubelet[1][1][2]));
  rotateAroundAxisd(0,0,0,
		pcube->p_angle,0,0,1);
  glTranslated(-2.5,0,0);

  rotateAroundAxisd(2.5,0,0,
		-pcube->p_angle,0,0,1);
  rotateAroundAxisd(0,0,2.5,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][1][2]));
  rotateAroundAxisd(0,0,2.5,
		pcube->g_angle,1,0,0);
  rotateAroundAxisd(2.5,0,0,
		pcube->p_angle,0,0,1);

  glTranslated(0,2.5,0);

  rotateAroundAxisd(2.5,2.5,0,
		-pcube->p_angle,0,0,1);
  rotateAroundAxisd(2.5,0,2.5,
		-pcube->h_angle,0,1,0);
  rotateAroundAxisd(0,-2.5,2.5,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][2][2]));
  rotateAroundAxisd(0,-2.5,2.5,
		pcube->g_angle,1,0,0);
  rotateAroundAxisd(2.5,0,2.5,
		pcube->h_angle,0,1,0);
  rotateAroundAxisd(2.5,2.5,0,
		pcube->p_angle,0,0,1);

  glTranslated(2.5,0,0);

  rotateAroundAxisd(0,-2.5,0,
		-pcube->p_angle,0,0,1);
  rotateAroundAxisd(0,0,2.5,
		-pcube->h_angle,0,1,0);
  drawcubelet(&(pcube->cubelet[1][2][2]));
  rotateAroundAxisd(0,0,2.5,
		pcube->h_angle,0,1,0);
  rotateAroundAxisd(0,-2.5,0,
		pcube->p_angle,0,0,1);

  glTranslated(2.5,0,0);

  rotateAroundAxisd(-2.5,-2.5,0,
		-pcube->p_angle,0,0,1);
  rotateAroundAxisd(-2.5,0,2.5,
		-pcube->h_angle,0,1,0);
  rotateAroundAxisd(0,-2.5,2.5,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][2][2]));
  rotateAroundAxisd(0,-2.5,2.5,
		pcube->d_angle,1,0,0);
  rotateAroundAxisd(-2.5,0,2.5,
		pcube->h_angle,0,1,0);
  rotateAroundAxisd(-2.5,-2.5,0,
		pcube->p_angle,0,0,1);

  glTranslated(0,0,2.5);
  rotateAroundAxisd(-2.5,0,0,
		-pcube->h_angle,0,1,0);
  rotateAroundAxisd(0,-2.5,0,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][2][1]));
  rotateAroundAxisd(0,-2.5,0,
		pcube->d_angle,1,0,0);
  rotateAroundAxisd(-2.5,0,0,
		pcube->h_angle,0,1,0);
  glTranslated(-2.5,0,0);
  rotateAroundAxisd(0,0,0,
		-pcube->h_angle,0,1,0);
  drawcubelet(&(pcube->cubelet[1][2][1]));
  rotateAroundAxisd(0,0,0,
		pcube->h_angle,0,1,0);
  glTranslated(-2.5,0,0);
  rotateAroundAxisd(2.5,0,0,
		-pcube->h_angle,0,1,0);
  rotateAroundAxisd(0,-2.5,0,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][2][1]));
  rotateAroundAxisd(0,-2.5,0,
		pcube->g_angle,1,0,0);
  rotateAroundAxisd(2.5,0,0,
		pcube->h_angle,0,1,0);
  glTranslated(0,-2.5,0);
  rotateAroundAxisd(0,0,0,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][1][1]));
  rotateAroundAxisd(0,0,0,
		pcube->g_angle,1,0,0);
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][1][1]));
  glTranslated(2.5,0,0);
  rotateAroundAxisd(0,0,0,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][1][1]));
  rotateAroundAxisd(0,0,0,
		pcube->d_angle,1,0,0);
  glTranslated(0,-2.5,0);

  rotateAroundAxisd(-2.5,0,0,
		-pcube->b_angle,0,1,0);
  rotateAroundAxisd(0,2.5,0,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][0][1]));
  rotateAroundAxisd(0,2.5,0,
		pcube->d_angle,1,0,0);
  rotateAroundAxisd(-2.5,0,0,
		pcube->b_angle,0,1,0);
  glTranslated(-2.5,0,0);
  rotateAroundAxisd(0,0,0,
		-pcube->b_angle,0,1,0);
  drawcubelet(&(pcube->cubelet[1][0][1]));
  rotateAroundAxisd(0,0,0,
		pcube->b_angle,0,1,0);
  glTranslated(-2.5,0,0);
  rotateAroundAxisd(2.5,0,0,
		-pcube->b_angle,0,1,0);
  rotateAroundAxisd(0,2.5,0,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][0][1]));
  rotateAroundAxisd(0,2.5,0,
		pcube->g_angle,1,0,0);
  rotateAroundAxisd(2.5,0,0,
		pcube->b_angle,0,1,0);
  glTranslated(0,0,2.5);

  rotateAroundAxisd(2.5,2.5,0,
		-pcube->a_angle,0,0,1);
  rotateAroundAxisd(2.5,0,-2.5,
		-pcube->b_angle,0,1,0);
  rotateAroundAxisd(0,2.5,-2.5,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][0][0]));
  rotateAroundAxisd(0,2.5,-2.5,
		pcube->g_angle,1,0,0);
  rotateAroundAxisd(2.5,0,-2.5,
		pcube->b_angle,0,1,0);
  rotateAroundAxisd(2.5,2.5,0,
		pcube->a_angle,0,0,1);

  glTranslated(2.5,0,0);

  rotateAroundAxisd(0,2.5,0,
		-pcube->a_angle,0,0,1);
  rotateAroundAxisd(0,0,-2.5,
		-pcube->b_angle,0,1,0);
  drawcubelet(&(pcube->cubelet[1][0][0]));
  rotateAroundAxisd(0,0,-2.5,
		pcube->b_angle,0,1,0);
  rotateAroundAxisd(0,2.5,0,
		pcube->a_angle,0,0,1);

  glTranslated(2.5,0,0);
  rotateAroundAxisd(-2.5,2.5,0,
		-pcube->a_angle,0,0,1);
  rotateAroundAxisd(-2.5,0,-2.5,
		-pcube->b_angle,0,1,0);
  rotateAroundAxisd(0,2.5,-2.5,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][0][0]));
  rotateAroundAxisd(0,2.5,-2.5,
		pcube->d_angle,1,0,0);
  rotateAroundAxisd(-2.5,0,-2.5,
		pcube->b_angle,0,1,0);
  rotateAroundAxisd(-2.5,2.5,0,
		pcube->a_angle,0,0,1);
  glTranslated(0,2.5,0);
  rotateAroundAxisd(-2.5,0,0,
		-pcube->a_angle,0,0,1);
  rotateAroundAxisd(0,0,-2.5,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][1][0]));
  rotateAroundAxisd(0,0,-2.5,
		pcube->d_angle,1,0,0);
  rotateAroundAxisd(-2.5,0,0,
		pcube->a_angle,0,0,1);

  glTranslated(-2.5,0,0);

  rotateAroundAxisd(0,0,0,
		-pcube->a_angle,0,0,1);
  drawcubelet(&(pcube->cubelet[1][1][0]));
  rotateAroundAxisd(0,0,0,
		pcube->a_angle,0,0,1);

  glTranslated(-2.5,0,0);
  rotateAroundAxisd(2.5,0,0,
		-pcube->a_angle,0,0,1);
  rotateAroundAxisd(0,0,-2.5,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][1][0]));
  rotateAroundAxisd(0,0,-2.5,
		pcube->g_angle,1,0,0);
  rotateAroundAxisd(2.5,0,0,
		pcube->a_angle,0,0,1);
  glTranslated(0,2.5,0);
  rotateAroundAxisd(2.5,-2.5,0,
		-pcube->a_angle,0,0,1);
  rotateAroundAxisd(2.5,0,-2.5,
		-pcube->h_angle,0,1,0);
  rotateAroundAxisd(0,-2.5,-2.5,
		-pcube->g_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[0][2][0]));
  rotateAroundAxisd(0,-2.5,-2.5,
		pcube->g_angle,1,0,0);
  rotateAroundAxisd(2.5,0,-2.5,
		pcube->h_angle,0,1,0);
  rotateAroundAxisd(2.5,-2.5,0,
		pcube->a_angle,0,0,1);
  glTranslated(2.5,0,0);

  rotateAroundAxisd(0,-2.5,0,
		-pcube->a_angle,0,0,1);
  rotateAroundAxisd(0,0,-2.5,
		-pcube->h_angle,0,1,0);
  drawcubelet(&(pcube->cubelet[1][2][0]));
  rotateAroundAxisd(0,0,-2.5,
		pcube->h_angle,0,1,0);
  rotateAroundAxisd(0,-2.5,0,
		pcube->a_angle,0,0,1);
  glTranslated(2.5,0,0);

  rotateAroundAxisd(-2.5,-2.5,0,
		-pcube->a_angle,0,0,1);
  rotateAroundAxisd(-2.5,0,-2.5,
		-pcube->h_angle,0,1,0);
  rotateAroundAxisd(0,-2.5,-2.5,
		-pcube->d_angle,1,0,0);
  drawcubelet(&(pcube->cubelet[2][2][0]));
  rotateAroundAxisd(0,-2.5,-2.5,
		-pcube->d_angle,1,0,0);
  rotateAroundAxisd(-2.5,0,-2.5,
		pcube->h_angle,0,1,0);
  rotateAroundAxisd(-2.5,-2.5,0,
		pcube->a_angle,0,0,1);
  glutSwapBuffers();
  glutPostRedisplay();
}


void InitGL()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR);
}


void reshape(int width, int height)
{
  glViewport(0,0,width,height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.,(float)width/(float)height,0.01,100);
  glMatrixMode(GL_MODELVIEW);
}


void GestionClavier(unsigned char key, int x, int y)
{
  switch(key) {
  case 'a': run_anim_thread(a_anim,pcube); return;
  case 'A': run_anim_thread(a_inv_anim,pcube); return;
  case 'p': run_anim_thread(p_anim,pcube); return;
  case 'P': run_anim_thread(p_inv_anim,pcube); return;
  case 'h': run_anim_thread(h_anim,pcube); return;
  case 'H': run_anim_thread(h_inv_anim,pcube); return;
  case 'b': run_anim_thread(b_anim,pcube); return;
  case 'B': run_anim_thread(b_inv_anim,pcube); return;
  case 'd': run_anim_thread(d_anim,pcube); return;
  case 'D': run_anim_thread(d_inv_anim,pcube); return;
  case 'g': run_anim_thread(g_anim,pcube); return;
  case 'G': run_anim_thread(g_inv_anim,pcube); return;
  case 'z': r_xy(pcube); return;
  case 'Z': r_xy_inv(pcube); return;
  case 'x': r_xz(pcube); return;
  case 'X': r_xz_inv(pcube); return;
  case 'c': r_yz(pcube); return;
  case 'C': r_yz_inv(pcube); return;
  case '2':
    rx--;
    return;
  case '8':
    rx++;
    return;
  case '4':
    ry--;
    return;
  case '6':
    ry++;
    return;
  case '9':
    rz--;
    return;
  case '7':
    rz++;
    return;
  case ' ':
    rx=0;
    ry=0;
    rz=0;
    return;
  case '+':
    zoom += 1.0;
    return;
  case '-':
    zoom -=1.0;
    return;
  case 27:
    exit(0);
  }
}


void initdisplay( int argc, char *argv[] )
{
  glutInit(&argc,argv);
  glutInitWindowSize(320,240);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

  Window = glutCreateWindow("Rubik's Cube");

  InitGL();
  glutReshapeFunc(reshape);
  glutDisplayFunc(draw);
  glutKeyboardFunc(GestionClavier);

  glutMainLoop();
}


void rundisplay( CUBE *cube, int argc, char *argv[] )
{
  display( cube );
  initdisplay( argc, argv );
}


/* END OF display.c */
