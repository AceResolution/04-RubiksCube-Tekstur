/* cube.c : fonctions evoluees pour le cube (Scramble et Exec)
 *          advanced cube functions (Scramble and Exec)
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

#include <stdlib.h>
#include <stdio.h>
#include "_cube.h"


#define RND_SCRAMBLE (RAND_MAX / 14)


void Scramble( CUBE *cube )
{
  int i, n;
  for( i = 0 ; i < 100 ; i++ ) {
    n = rand() / RND_SCRAMBLE;
    switch( n ) {
    case 1:
      a_anim( cube );
      break;
    case 2:
      a_inv_anim( cube );
      break;
    case 3:
      p_anim( cube );
      break;
    case 4:
      p_inv_anim( cube );
      break;
    case 5:
      g_anim( cube );
      break;
    case 6:
      g_inv_anim( cube );
      break;
    case 7:
      d_anim( cube );
      break;
    case 8:
      d_inv_anim( cube );
      break;
    case 9:
      b_anim( cube );
      break;
    case 10:
      b_inv_anim( cube );
      break;
    case 11:
      h_anim( cube );
      break;
    default:
      h_inv_anim( cube );
    }
  }
}


void Exec( CUBE *cube, char *command )
{
  char buf[3];
  char *pc;

  for( pc = command ; *pc != 0 ; pc++ ) {
    buf[0] = *pc;
    if((*(pc+1)=='\'')||(*(pc+1)=='-')||(*(pc+1)=='2')||(*(pc+1)=='ý')||
       (*(pc+1)=='²')) //ý=²
      {
        pc++;
        buf[1] = *pc;
        buf[2] = 0;
      } else {
        buf[1] = 0;
      }
    switch(buf[0]) {
    case 'a':
      switch(buf[1]) {
      case '-':
      case '\'':
        a_inv_anim(cube);
        break;
      case '2':
      case 'ý'://²
      case '²':
        a_anim(cube);
      case 0:
        a_anim(cube);
      }
      break;
    case 'p':
      switch(buf[1]) {
      case '-':
      case '\'':
        p_inv_anim(cube);
        break;
      case '2':
      case 'ý'://²
      case '²':
        p_anim(cube);
      case 0:
        p_anim(cube);
      }
      break;
    case 'd':
      switch(buf[1]) {
      case '-':
      case '\'':
        d_inv_anim(cube);
        break;
      case '2':
      case 'ý'://²
      case '²':
        d_anim(cube);
      case 0:
        d_anim(cube);
      }
      break;
    case 'g':
      switch(buf[1])
        {
        case '-':
        case '\'':
          g_inv_anim(cube);
          break;
        case '2':
        case 'ý'://²
        case '²':
          g_anim(cube);
        case 0:
          g_anim(cube);
        }
      break;
    case 'h':
      switch(buf[1]) {
      case '-':
      case '\'':
        h_inv_anim(cube);
        break;
      case '2':
      case 'ý'://²
      case '²':
        h_anim(cube);
      case 0:
        h_anim(cube);
      }
      break;
    case 'b':
      switch(buf[1]) {
      case '-':
      case '\'':
        b_inv_anim(cube);
        break;
      case '2':
      case 'ý'://²
      case '²':
        b_anim(cube);
      case 0:
        b_anim(cube);
      }
    case '.':
    case ' ':
      break;
    default:
      printf("Exec : ERROR : invalid character: %c\n", buf[0]);
    }
  }
}

/* END OF cube.c */
