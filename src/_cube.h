/* _cube.h : structures pour gerer le cube en memoire
 *           cube structures
 * modif oleh AceOneWorks (Nizam, EC, Elfansoer)
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

#ifndef __INC_CUBEPRIM_H
#define __INC_CUBEPRIM_H


/** Structures **/

enum COLOR
{
  W,	//I,blanc,white
  R,	//R,rouge,red
  B,	//B,bleu,blue
  G,	//V,vert,green
  Y,	//J,jaune,yellow
  O,	//O,orange
  N	//no color (black)
} typedef COLOR;


struct CUBELET
{
  COLOR face[6];
} typedef CUBELET;


struct CUBE
{
  CUBELET cubelet[3][3][3];
  double a_angle;
  double p_angle;
  double g_angle;
  double d_angle;
  double b_angle;
  double h_angle;
} typedef CUBE;



/** Functions **/

void Reset( CUBE *cube );
void a_anim( CUBE *cube );
void a_inv_anim( CUBE *cube );
void p_anim( CUBE *cube );
void p_inv_anim( CUBE *cube );
void h_anim( CUBE *cube );
void h_inv_anim( CUBE *cube );
void b_anim( CUBE *cube );
void b_inv_anim( CUBE *cube );
void d_anim( CUBE *cube );
void d_inv_anim( CUBE *cube );
void g_anim( CUBE *cube );
void g_inv_anim( CUBE *cube );
void a( CUBE *cube );
void a_inv( CUBE *cube );
void p( CUBE *cube );
void p_inv( CUBE *cube );
void h( CUBE *cube );
void h_inv( CUBE *cube );
void b( CUBE *cube );
void b_inv( CUBE *cube );
void d( CUBE *cube );
void d_inv( CUBE *cube );
void g( CUBE *cube );
void g_inv( CUBE *cube );
void r_xy( CUBE *cube );
void r_xy_inv( CUBE *cube );
void r_xz( CUBE *cube );
void r_xz_inv( CUBE *cube );
void r_yz( CUBE *cube );
void r_yz_inv( CUBE *cube );

#define r_yx r_xy
#define r_zx r_xz
#define r_zy r_yz
#define r_yx_inv r_xy_inv
#define r_zx_inv r_xz_inv
#define r_zy_inv r_yz_inv

#endif //__INC_CUBEPRIM_H

/* END OF _cube.h */
