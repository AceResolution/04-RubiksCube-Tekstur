/* _cube.c : Les fonctions de base du cube (Reset,a,p,g,d,h,b et inverses)
 *           Base cube functions
	modif oleh AceOneWorks (Nizam, EC, Elfansoer)
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

#include "_cube.h"
#include <unistd.h>

void Reset( CUBE *cube )
{
  cube->cubelet[0][0][0].face[0] = W;
  cube->cubelet[0][0][0].face[1] = N;
  cube->cubelet[0][0][0].face[2] = N;
  cube->cubelet[0][0][0].face[3] = G;
  cube->cubelet[0][0][0].face[4] = O;
  cube->cubelet[0][0][0].face[5] = N;

  cube->cubelet[1][0][0].face[0] = W;
  cube->cubelet[1][0][0].face[1] = N;
  cube->cubelet[1][0][0].face[2] = N;
  cube->cubelet[1][0][0].face[3] = G;
  cube->cubelet[1][0][0].face[4] = N;
  cube->cubelet[1][0][0].face[5] = N;

  cube->cubelet[2][0][0].face[0] = W;
  cube->cubelet[2][0][0].face[1] = N;
  cube->cubelet[2][0][0].face[2] = R;
  cube->cubelet[2][0][0].face[3] = G;
  cube->cubelet[2][0][0].face[4] = N;
  cube->cubelet[2][0][0].face[5] = N;

  cube->cubelet[0][1][0].face[0] = W;
  cube->cubelet[0][1][0].face[1] = N;
  cube->cubelet[0][1][0].face[2] = N;
  cube->cubelet[0][1][0].face[3] = N;
  cube->cubelet[0][1][0].face[4] = O;
  cube->cubelet[0][1][0].face[5] = N;

  cube->cubelet[1][1][0].face[0] = W;
  cube->cubelet[1][1][0].face[1] = N;
  cube->cubelet[1][1][0].face[2] = N;
  cube->cubelet[1][1][0].face[3] = N;
  cube->cubelet[1][1][0].face[4] = N;
  cube->cubelet[1][1][0].face[5] = N;

  cube->cubelet[2][1][0].face[0] = W;
  cube->cubelet[2][1][0].face[1] = N;
  cube->cubelet[2][1][0].face[2] = R;
  cube->cubelet[2][1][0].face[3] = N;
  cube->cubelet[2][1][0].face[4] = N;
  cube->cubelet[2][1][0].face[5] = N;

  cube->cubelet[0][2][0].face[0] = W;
  cube->cubelet[0][2][0].face[1] = B;
  cube->cubelet[0][2][0].face[2] = N;
  cube->cubelet[0][2][0].face[3] = N;
  cube->cubelet[0][2][0].face[4] = O;
  cube->cubelet[0][2][0].face[5] = N;

  cube->cubelet[1][2][0].face[0] = W;
  cube->cubelet[1][2][0].face[1] = B;
  cube->cubelet[1][2][0].face[2] = N;
  cube->cubelet[1][2][0].face[3] = N;
  cube->cubelet[1][2][0].face[4] = N;
  cube->cubelet[1][2][0].face[5] = N;

  cube->cubelet[2][2][0].face[0] = W;
  cube->cubelet[2][2][0].face[1] = B;
  cube->cubelet[2][2][0].face[2] = R;
  cube->cubelet[2][2][0].face[3] = N;
  cube->cubelet[2][2][0].face[4] = N;
  cube->cubelet[2][2][0].face[5] = N;

  cube->cubelet[0][0][1].face[0] = N;
  cube->cubelet[0][0][1].face[1] = N;
  cube->cubelet[0][0][1].face[2] = N;
  cube->cubelet[0][0][1].face[3] = G;
  cube->cubelet[0][0][1].face[4] = O;
  cube->cubelet[0][0][1].face[5] = N;

  cube->cubelet[1][0][1].face[0] = N;
  cube->cubelet[1][0][1].face[1] = N;
  cube->cubelet[1][0][1].face[2] = N;
  cube->cubelet[1][0][1].face[3] = G;
  cube->cubelet[1][0][1].face[4] = N;
  cube->cubelet[1][0][1].face[5] = N;

  cube->cubelet[2][0][1].face[0] = N;
  cube->cubelet[2][0][1].face[1] = N;
  cube->cubelet[2][0][1].face[2] = R;
  cube->cubelet[2][0][1].face[3] = G;
  cube->cubelet[2][0][1].face[4] = N;
  cube->cubelet[2][0][1].face[5] = N;

  cube->cubelet[0][1][1].face[0] = N;
  cube->cubelet[0][1][1].face[1] = N;
  cube->cubelet[0][1][1].face[2] = N;
  cube->cubelet[0][1][1].face[3] = N;
  cube->cubelet[0][1][1].face[4] = O;
  cube->cubelet[0][1][1].face[5] = N;

  cube->cubelet[1][1][1].face[0] = N;
  cube->cubelet[1][1][1].face[1] = N;
  cube->cubelet[1][1][1].face[2] = N;
  cube->cubelet[1][1][1].face[3] = N;
  cube->cubelet[1][1][1].face[4] = N;
  cube->cubelet[1][1][1].face[5] = N;

  cube->cubelet[2][1][1].face[0] = N;
  cube->cubelet[2][1][1].face[1] = N;
  cube->cubelet[2][1][1].face[2] = R;
  cube->cubelet[2][1][1].face[3] = N;
  cube->cubelet[2][1][1].face[4] = N;
  cube->cubelet[2][1][1].face[5] = N;

  cube->cubelet[0][2][1].face[0] = N;
  cube->cubelet[0][2][1].face[1] = B;
  cube->cubelet[0][2][1].face[2] = N;
  cube->cubelet[0][2][1].face[3] = N;
  cube->cubelet[0][2][1].face[4] = O;
  cube->cubelet[0][2][1].face[5] = N;

  cube->cubelet[1][2][1].face[0] = N;
  cube->cubelet[1][2][1].face[1] = B;
  cube->cubelet[1][2][1].face[2] = N;
  cube->cubelet[1][2][1].face[3] = N;
  cube->cubelet[1][2][1].face[4] = N;
  cube->cubelet[1][2][1].face[5] = N;

  cube->cubelet[2][2][1].face[0] = N;
  cube->cubelet[2][2][1].face[1] = B;
  cube->cubelet[2][2][1].face[2] = R;
  cube->cubelet[2][2][1].face[3] = N;
  cube->cubelet[2][2][1].face[4] = N;
  cube->cubelet[2][2][1].face[5] = N;

  cube->cubelet[0][0][2].face[0] = N;
  cube->cubelet[0][0][2].face[1] = N;
  cube->cubelet[0][0][2].face[2] = N;
  cube->cubelet[0][0][2].face[3] = G;
  cube->cubelet[0][0][2].face[4] = O;
  cube->cubelet[0][0][2].face[5] = Y;

  cube->cubelet[1][0][2].face[0] = N;
  cube->cubelet[1][0][2].face[1] = N;
  cube->cubelet[1][0][2].face[2] = N;
  cube->cubelet[1][0][2].face[3] = G;
  cube->cubelet[1][0][2].face[4] = N;
  cube->cubelet[1][0][2].face[5] = Y;

  cube->cubelet[2][0][2].face[0] = N;
  cube->cubelet[2][0][2].face[1] = N;
  cube->cubelet[2][0][2].face[2] = R;
  cube->cubelet[2][0][2].face[3] = G;
  cube->cubelet[2][0][2].face[4] = N;
  cube->cubelet[2][0][2].face[5] = Y;

  cube->cubelet[0][1][2].face[0] = N;
  cube->cubelet[0][1][2].face[1] = N;
  cube->cubelet[0][1][2].face[2] = N;
  cube->cubelet[0][1][2].face[3] = N;
  cube->cubelet[0][1][2].face[4] = O;
  cube->cubelet[0][1][2].face[5] = Y;

  cube->cubelet[1][1][2].face[0] = N;
  cube->cubelet[1][1][2].face[1] = N;
  cube->cubelet[1][1][2].face[2] = N;
  cube->cubelet[1][1][2].face[3] = N;
  cube->cubelet[1][1][2].face[4] = N;
  cube->cubelet[1][1][2].face[5] = Y;

  cube->cubelet[2][1][2].face[0] = N;
  cube->cubelet[2][1][2].face[1] = N;
  cube->cubelet[2][1][2].face[2] = R;
  cube->cubelet[2][1][2].face[3] = N;
  cube->cubelet[2][1][2].face[4] = N;
  cube->cubelet[2][1][2].face[5] = Y;

  cube->cubelet[0][2][2].face[0] = N;
  cube->cubelet[0][2][2].face[1] = B;
  cube->cubelet[0][2][2].face[2] = N;
  cube->cubelet[0][2][2].face[3] = N;
  cube->cubelet[0][2][2].face[4] = O;
  cube->cubelet[0][2][2].face[5] = Y;

  cube->cubelet[1][2][2].face[0] = N;
  cube->cubelet[1][2][2].face[1] = B;
  cube->cubelet[1][2][2].face[2] = N;
  cube->cubelet[1][2][2].face[3] = N;
  cube->cubelet[1][2][2].face[4] = N;
  cube->cubelet[1][2][2].face[5] = Y;

  cube->cubelet[2][2][2].face[0] = N;
  cube->cubelet[2][2][2].face[1] = B;
  cube->cubelet[2][2][2].face[2] = R;
  cube->cubelet[2][2][2].face[3] = N;
  cube->cubelet[2][2][2].face[4] = N;
  cube->cubelet[2][2][2].face[5] = Y;

  cube->a_angle = 0;
  cube->p_angle = 0;
  cube->d_angle = 0;
}

#define anim_delay 3000

void a_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->a_angle+=1;
    usleep(anim_delay);
  }
  cube->a_angle=0;
  a(cube);
}

void a(CUBE *cube)
{
  COLOR sav1, sav2, sav3;

  sav1 = cube->cubelet[0][0][0].face[0];
  sav2 = cube->cubelet[0][0][0].face[4];
  sav3 = cube->cubelet[0][0][0].face[3];

  cube->cubelet[0][0][0].face[0] = cube->cubelet[2][0][0].face[0];
  cube->cubelet[0][0][0].face[4] = cube->cubelet[2][0][0].face[3];
  cube->cubelet[0][0][0].face[3] = cube->cubelet[2][0][0].face[2];

  cube->cubelet[2][0][0].face[0] = cube->cubelet[2][2][0].face[0];
  cube->cubelet[2][0][0].face[2] = cube->cubelet[2][2][0].face[1];
  cube->cubelet[2][0][0].face[3] = cube->cubelet[2][2][0].face[2];

  cube->cubelet[2][2][0].face[0] = cube->cubelet[0][2][0].face[0];
  cube->cubelet[2][2][0].face[2] = cube->cubelet[0][2][0].face[1];
  cube->cubelet[2][2][0].face[1] = cube->cubelet[0][2][0].face[4];

  cube->cubelet[0][2][0].face[0] = sav1;
  cube->cubelet[0][2][0].face[1] = sav2;
  cube->cubelet[0][2][0].face[4] = sav3;

  sav1 = cube->cubelet[1][0][0].face[0];
  sav2 = cube->cubelet[1][0][0].face[3];

  cube->cubelet[1][0][0].face[0] = cube->cubelet[2][1][0].face[0];
  cube->cubelet[1][0][0].face[3] = cube->cubelet[2][1][0].face[2];

  cube->cubelet[2][1][0].face[0] = cube->cubelet[1][2][0].face[0];
  cube->cubelet[2][1][0].face[2] = cube->cubelet[1][2][0].face[1];

  cube->cubelet[1][2][0].face[0] = cube->cubelet[0][1][0].face[0];
  cube->cubelet[1][2][0].face[1] = cube->cubelet[0][1][0].face[4];

  cube->cubelet[0][1][0].face[0] = sav1;
  cube->cubelet[0][1][0].face[4] = sav2;
}

void a_inv_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->a_angle-=1;
    usleep(anim_delay);
  }
  cube->a_angle=0;
  a_inv(cube);
}

void a_inv(CUBE *cube)
{
  a(cube);
  a(cube);
  a(cube);
}

void p_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->p_angle-=1;
    usleep(anim_delay);
  }
  cube->p_angle=0;
  p(cube);
}

void p(CUBE *cube)
{
  p_inv(cube);
  p_inv(cube);
  p_inv(cube);
}


void p_inv_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->p_angle+=1;
    usleep(anim_delay);
  }
  cube->p_angle=0;
  p_inv(cube);
}

void p_inv(CUBE *cube)
{
  COLOR sav1, sav2, sav3;

  sav1 = cube->cubelet[0][0][2].face[5];
  sav2 = cube->cubelet[0][0][2].face[4];
  sav3 = cube->cubelet[0][0][2].face[3];

  cube->cubelet[0][0][2].face[5] = cube->cubelet[2][0][2].face[5];
  cube->cubelet[0][0][2].face[4] = cube->cubelet[2][0][2].face[3];
  cube->cubelet[0][0][2].face[3] = cube->cubelet[2][0][2].face[2];

  cube->cubelet[2][0][2].face[5] = cube->cubelet[2][2][2].face[5];
  cube->cubelet[2][0][2].face[2] = cube->cubelet[2][2][2].face[1];
  cube->cubelet[2][0][2].face[3] = cube->cubelet[2][2][2].face[2];

  cube->cubelet[2][2][2].face[5] = cube->cubelet[0][2][2].face[5];
  cube->cubelet[2][2][2].face[2] = cube->cubelet[0][2][2].face[1];
  cube->cubelet[2][2][2].face[1] = cube->cubelet[0][2][2].face[4];

  cube->cubelet[0][2][2].face[5] = sav1;
  cube->cubelet[0][2][2].face[1] = sav2;
  cube->cubelet[0][2][2].face[4] = sav3;

  sav1 = cube->cubelet[1][0][2].face[5];
  sav2 = cube->cubelet[1][0][2].face[3];

  cube->cubelet[1][0][2].face[5] = cube->cubelet[2][1][2].face[5];
  cube->cubelet[1][0][2].face[3] = cube->cubelet[2][1][2].face[2];

  cube->cubelet[2][1][2].face[5] = cube->cubelet[1][2][2].face[5];
  cube->cubelet[2][1][2].face[2] = cube->cubelet[1][2][2].face[1];

  cube->cubelet[1][2][2].face[5] = cube->cubelet[0][1][2].face[5];
  cube->cubelet[1][2][2].face[1] = cube->cubelet[0][1][2].face[4];

  cube->cubelet[0][1][2].face[5] = sav1;
  cube->cubelet[0][1][2].face[4] = sav2;
}

void h_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->h_angle+=1;
    usleep(anim_delay);
  }
  cube->h_angle=0;
  h(cube);
}

void h(CUBE *cube)
{
  COLOR sav1, sav2, sav3;

  sav1 = cube->cubelet[0][2][0].face[1];
  sav2 = cube->cubelet[0][2][0].face[0];
  sav3 = cube->cubelet[0][2][0].face[4];

  cube->cubelet[0][2][0].face[1] = cube->cubelet[2][2][0].face[1];
  cube->cubelet[0][2][0].face[0] = cube->cubelet[2][2][0].face[2];
  cube->cubelet[0][2][0].face[4] = cube->cubelet[2][2][0].face[0];

  cube->cubelet[2][2][0].face[1] = cube->cubelet[2][2][2].face[1];
  cube->cubelet[2][2][0].face[2] = cube->cubelet[2][2][2].face[5];
  cube->cubelet[2][2][0].face[0] = cube->cubelet[2][2][2].face[2];

  cube->cubelet[2][2][2].face[1] = cube->cubelet[0][2][2].face[1];
  cube->cubelet[2][2][2].face[5] = cube->cubelet[0][2][2].face[4];
  cube->cubelet[2][2][2].face[2] = cube->cubelet[0][2][2].face[5];

  cube->cubelet[0][2][2].face[1] = sav1;
  cube->cubelet[0][2][2].face[4] = sav2;
  cube->cubelet[0][2][2].face[5] = sav3;

  sav1 = cube->cubelet[1][2][0].face[1];
  sav2 = cube->cubelet[1][2][0].face[0];

  cube->cubelet[1][2][0].face[1] = cube->cubelet[2][2][1].face[1];
  cube->cubelet[1][2][0].face[0] = cube->cubelet[2][2][1].face[2];

  cube->cubelet[2][2][1].face[1] = cube->cubelet[1][2][2].face[1];
  cube->cubelet[2][2][1].face[2] = cube->cubelet[1][2][2].face[5];

  cube->cubelet[1][2][2].face[1] = cube->cubelet[0][2][1].face[1];
  cube->cubelet[1][2][2].face[5] = cube->cubelet[0][2][1].face[4];

  cube->cubelet[0][2][1].face[1] = sav1;
  cube->cubelet[0][2][1].face[4] = sav2;
}

void h_inv_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->h_angle-=1;
    usleep(anim_delay);
  }
  cube->h_angle=0;
  h_inv(cube);
}

void h_inv(CUBE *cube)
{
  h(cube);
  h(cube);
  h(cube);
}

void b_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->b_angle-=1;
    usleep(anim_delay);
  }
  cube->b_angle=0;
  b(cube);
}

void b(CUBE *cube)
{
  b_inv(cube);
  b_inv(cube);
  b_inv(cube);
}


void b_inv(CUBE *cube)
{
  COLOR sav1, sav2, sav3;

  sav1 = cube->cubelet[0][0][0].face[3];
  sav2 = cube->cubelet[0][0][0].face[0];
  sav3 = cube->cubelet[0][0][0].face[4];

  cube->cubelet[0][0][0].face[3] = cube->cubelet[2][0][0].face[3];
  cube->cubelet[0][0][0].face[0] = cube->cubelet[2][0][0].face[2];
  cube->cubelet[0][0][0].face[4] = cube->cubelet[2][0][0].face[0];

  cube->cubelet[2][0][0].face[3] = cube->cubelet[2][0][2].face[3];
  cube->cubelet[2][0][0].face[2] = cube->cubelet[2][0][2].face[5];
  cube->cubelet[2][0][0].face[0] = cube->cubelet[2][0][2].face[2];

  cube->cubelet[2][0][2].face[3] = cube->cubelet[0][0][2].face[3];
  cube->cubelet[2][0][2].face[5] = cube->cubelet[0][0][2].face[4];
  cube->cubelet[2][0][2].face[2] = cube->cubelet[0][0][2].face[5];

  cube->cubelet[0][0][2].face[3] = sav1;
  cube->cubelet[0][0][2].face[4] = sav2;
  cube->cubelet[0][0][2].face[5] = sav3;

  sav1 = cube->cubelet[1][0][0].face[3];
  sav2 = cube->cubelet[1][0][0].face[0];

  cube->cubelet[1][0][0].face[3] = cube->cubelet[2][0][1].face[3];
  cube->cubelet[1][0][0].face[0] = cube->cubelet[2][0][1].face[2];

  cube->cubelet[2][0][1].face[3] = cube->cubelet[1][0][2].face[3];
  cube->cubelet[2][0][1].face[2] = cube->cubelet[1][0][2].face[5];

  cube->cubelet[1][0][2].face[3] = cube->cubelet[0][0][1].face[3];
  cube->cubelet[1][0][2].face[5] = cube->cubelet[0][0][1].face[4];

  cube->cubelet[0][0][1].face[3] = sav1;
  cube->cubelet[0][0][1].face[4] = sav2;
}

void b_inv_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->b_angle+=1;
    usleep(anim_delay);
  }
  cube->b_angle=0;
  b_inv(cube);
}

void d_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->d_angle+=1;
    usleep(anim_delay);
  }
  cube->d_angle=0;
  d(cube);
}

void d(CUBE *cube)
{
  COLOR sav1, sav2, sav3;

  sav1 = cube->cubelet[2][0][0].face[2];
  sav2 = cube->cubelet[2][0][0].face[3];
  sav3 = cube->cubelet[2][0][0].face[0];

  cube->cubelet[2][0][0].face[2] = cube->cubelet[2][0][2].face[2];
  cube->cubelet[2][0][0].face[3] = cube->cubelet[2][0][2].face[5];
  cube->cubelet[2][0][0].face[0] = cube->cubelet[2][0][2].face[3];

  cube->cubelet[2][0][2].face[2] = cube->cubelet[2][2][2].face[2];
  cube->cubelet[2][0][2].face[5] = cube->cubelet[2][2][2].face[1];
  cube->cubelet[2][0][2].face[3] = cube->cubelet[2][2][2].face[5];

  cube->cubelet[2][2][2].face[2] = cube->cubelet[2][2][0].face[2];
  cube->cubelet[2][2][2].face[1] = cube->cubelet[2][2][0].face[0];
  cube->cubelet[2][2][2].face[5] = cube->cubelet[2][2][0].face[1];

  cube->cubelet[2][2][0].face[2] = sav1;
  cube->cubelet[2][2][0].face[0] = sav2;
  cube->cubelet[2][2][0].face[1] = sav3;

  sav1 = cube->cubelet[2][0][1].face[2];
  sav2 = cube->cubelet[2][0][1].face[3];

  cube->cubelet[2][0][1].face[2] = cube->cubelet[2][1][2].face[2];
  cube->cubelet[2][0][1].face[3] = cube->cubelet[2][1][2].face[5];

  cube->cubelet[2][1][2].face[2] = cube->cubelet[2][2][1].face[2];
  cube->cubelet[2][1][2].face[5] = cube->cubelet[2][2][1].face[1];

  cube->cubelet[2][2][1].face[2] = cube->cubelet[2][1][0].face[2];
  cube->cubelet[2][2][1].face[1] = cube->cubelet[2][1][0].face[0];

  cube->cubelet[2][1][0].face[2] = sav1;
  cube->cubelet[2][1][0].face[0] = sav2;
}


void d_inv(CUBE *cube)
{
  d(cube);
  d(cube);
  d(cube);
}

void d_inv_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->d_angle-=1;
    usleep(anim_delay);
  }
  cube->d_angle=0;
  d_inv(cube);
}


void g_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->g_angle-=1;
    usleep(anim_delay);
  }
  cube->g_angle=0;
  g(cube);
}

void g(CUBE *cube)
{
  g_inv(cube);
  g_inv(cube);
  g_inv(cube);
}


void g_inv(CUBE *cube)
{
  COLOR sav1, sav2, sav3;

  sav1 = cube->cubelet[0][0][0].face[4];
  sav2 = cube->cubelet[0][0][0].face[3];
  sav3 = cube->cubelet[0][0][0].face[0];

  cube->cubelet[0][0][0].face[4] = cube->cubelet[0][0][2].face[4];
  cube->cubelet[0][0][0].face[3] = cube->cubelet[0][0][2].face[5];
  cube->cubelet[0][0][0].face[0] = cube->cubelet[0][0][2].face[3];

  cube->cubelet[0][0][2].face[4] = cube->cubelet[0][2][2].face[4];
  cube->cubelet[0][0][2].face[5] = cube->cubelet[0][2][2].face[1];
  cube->cubelet[0][0][2].face[3] = cube->cubelet[0][2][2].face[5];

  cube->cubelet[0][2][2].face[4] = cube->cubelet[0][2][0].face[4];
  cube->cubelet[0][2][2].face[1] = cube->cubelet[0][2][0].face[0];
  cube->cubelet[0][2][2].face[5] = cube->cubelet[0][2][0].face[1];

  cube->cubelet[0][2][0].face[4] = sav1;
  cube->cubelet[0][2][0].face[0] = sav2;
  cube->cubelet[0][2][0].face[1] = sav3;

  sav1 = cube->cubelet[0][0][1].face[4];
  sav2 = cube->cubelet[0][0][1].face[3];

  cube->cubelet[0][0][1].face[4] = cube->cubelet[0][1][2].face[4];
  cube->cubelet[0][0][1].face[3] = cube->cubelet[0][1][2].face[5];

  cube->cubelet[0][1][2].face[4] = cube->cubelet[0][2][1].face[4];
  cube->cubelet[0][1][2].face[5] = cube->cubelet[0][2][1].face[1];

  cube->cubelet[0][2][1].face[4] = cube->cubelet[0][1][0].face[4];
  cube->cubelet[0][2][1].face[1] = cube->cubelet[0][1][0].face[0];

  cube->cubelet[0][1][0].face[4] = sav1;
  cube->cubelet[0][1][0].face[0] = sav2;
}

void g_inv_anim(CUBE * cube)
{
  int i;
  for (i = 0; i < 90; i++){
    cube->g_angle+=1;
    usleep(anim_delay);
  }
  cube->g_angle=0;
  g_inv(cube);
}


void r_xz(CUBE *cube)
{
  COLOR sav1, sav2;

  h(cube);
  b_inv(cube);

  sav1 = cube->cubelet[1][1][0].face[0];
  cube->cubelet[1][1][0].face[0] = cube->cubelet[2][1][1].face[2];
  cube->cubelet[2][1][1].face[2] = cube->cubelet[1][1][2].face[5];
  cube->cubelet[1][1][2].face[5] = cube->cubelet[0][1][1].face[4];
  cube->cubelet[0][1][1].face[4] = sav1;

  sav1 = cube->cubelet[0][1][0].face[0];
  sav2 = cube->cubelet[0][1][0].face[4];
  cube->cubelet[0][1][0].face[0] = cube->cubelet[2][1][0].face[2];
  cube->cubelet[0][1][0].face[4] = cube->cubelet[2][1][0].face[0];
  cube->cubelet[2][1][0].face[2] = cube->cubelet[2][1][2].face[5];
  cube->cubelet[2][1][0].face[0] = cube->cubelet[2][1][2].face[2];
  cube->cubelet[2][1][2].face[5] = cube->cubelet[0][1][2].face[4];
  cube->cubelet[2][1][2].face[2] = cube->cubelet[0][1][2].face[5];
  cube->cubelet[0][1][2].face[4] = sav1;
  cube->cubelet[0][1][2].face[5] = sav2;
}


void r_xz_inv(CUBE *cube)
{
  r_xz(cube);
  r_xz(cube);
  r_xz(cube);
}


void r_xy(CUBE *cube)
{
  COLOR sav1, sav2;

  a(cube);
  p_inv(cube);

  sav1 = cube->cubelet[1][2][1].face[1];
  cube->cubelet[1][2][1].face[1] = cube->cubelet[0][1][1].face[4];
  cube->cubelet[0][1][1].face[4] = cube->cubelet[1][0][1].face[3];
  cube->cubelet[1][0][1].face[3] = cube->cubelet[2][1][1].face[2];
  cube->cubelet[2][1][1].face[2] = sav1;

  sav1 = cube->cubelet[0][2][1].face[1];
  sav2 = cube->cubelet[0][2][1].face[4];
  cube->cubelet[0][2][1].face[1] = cube->cubelet[0][0][1].face[4];
  cube->cubelet[0][2][1].face[4] = cube->cubelet[0][0][1].face[3];
  cube->cubelet[0][0][1].face[4] = cube->cubelet[2][0][1].face[3];
  cube->cubelet[0][0][1].face[3] = cube->cubelet[2][0][1].face[2];
  cube->cubelet[2][0][1].face[3] = cube->cubelet[2][2][1].face[2];
  cube->cubelet[2][0][1].face[2] = cube->cubelet[2][2][1].face[1];
  cube->cubelet[2][2][1].face[2] = sav1;
  cube->cubelet[2][2][1].face[1] = sav2;
}


void r_xy_inv(CUBE *cube)
{
  r_xy(cube);
  r_xy(cube);
  r_xy(cube);
}


void r_yz(CUBE *cube)
{
  r_xy(cube);
  r_xz(cube);
  r_xy_inv(cube);
}


void r_yz_inv(CUBE *cube)
{
  r_xy_inv(cube);
  r_xz(cube);
  r_xy(cube);
}

/* END OF _cube.c */
