/* main.c : fonction main 
 *          'main' function




AceResolution's Rubik's Cube Simulator
Muhammad Nizami
Erick Chandra
Fathul Asrar Alfansuri

- dibuat untuk kepentingan pendidikan - 

Built on top of Rubik's Cube Simulator by AnTiKoNs

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
#include <time.h>
#include "_cube.h"
#include "cube.h"
#include "display.h"
#include "interpretor.h"


int main( int argc, char *argv[] )
{
  CUBE cube;
  srand(time(NULL));
  Reset(&cube);
  runinterpretor(&cube);
  rundisplay(&cube,argc,argv);
  return 0;
}


/* END OF main.c */
