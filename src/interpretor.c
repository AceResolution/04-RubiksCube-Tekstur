/* interpretor.c : l'interpreteur de commandes 
 *                 commands interpretor
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

#ifdef _WIN32
#include <windows.h>
#define CARRE "ý"
#else
#include <pthread.h>
#define CARRE "²"
#endif //_WIN32
#include <stdio.h>
#include <string.h>
#include "cube.h"
#include "algorithmes.h"


void printhelp( char *word )
{
  printf(
         "\n"
         "Help:\n"
         "-----\n"
         );
  if(word==NULL) {
    printf(
    "Select the Rubik's Cube window and press:\n"
    " '2' or '8' to rotate the cube along the x axis\n"
    " '4' or '6' to rotate the cube along the y axis\n"
    " '7' or '9' to rotate the cube along the z axis\n"
    " '+' or '-' to zoom or unzoom on the cube\n"
    " 'SPACE' to move the cube to his initial position\n"
    " 'ESC' to exit program\n"
    "\n"
    "Select the command (this) window and type:\n"
    " 'reset' to reset the cube\n"
    " 'scramble' to scramble the cube\n"
    " 'help [+ word]' to get help\n"
    " One or several of the following operations:\n"
    "   a, a' or a-, a2 or a" CARRE ", p, p' or p-, p2 or p" CARRE 
    ", d, d' or d-, d2 or d" CARRE ",\n"
    "   g, g' or g-, g2 or g" CARRE ", h, h' or h-, h2 or h" CARRE
    ", b, b' or b-, b2 or b" CARRE ",\n"
    " 'exit' or press CTRL+C to exit program\n"
    );
  } else if((!strcmp(word,"reset"))||(!strcmp(word,"Reset"))||
            (!strcmp(word,"RESET"))) {
    printf(
           " 'Reset' : reset the cube to his initial position\n"
           );
  } else if((!strcmp(word,"scramble"))||(!strcmp(word,"Scramble"))||
            (!strcmp(word,"SCRAMBLE"))) {
    printf(
           " 'Scramble' : scramble the cube, that is to say make 100 random"
           " operations\n"
 );
  } else if((!strcmp(word,"exit"))||(!strcmp(word,"Exit"))||
            (!strcmp(word,"EXIT"))) {
    printf(
           " 'Exit' : exit program. Pressing CRTL+C has the same effect\n"
           );
  } else if((*word=='a')||(*word=='p')||(*word=='g')||(*word=='d')||
            (*word=='h')||(*word=='b')) {
    printf(
  " Operations:\n"
  "  a = move the front face in the no-trigonometric sense\n"
  "  a' or a- = move the front face in the trigonometric sense\n"
  "  a2 or a" CARRE " = move th front face twice (the sense does not matter)\n"
  "  p = move the back face in the no-trigonometric sense\n"
  "  p' or a- = move the back face in the trigonometric sense\n"
  "  p2 or p" CARRE " = move th front face twice (the sense does not matter)\n"
  "  d = move the right face in the no-trigonometric sense\n"
  "  d' or a- = move the right face in the trigonometric sense\n"
  "  d2 or d" CARRE " = move th front face twice (the sense does not matter)\n"
  "  g = move the left face in the no-trigonometric sense\n"
  "  g' or a- = move the left face in the trigonometric sense\n"
  "  g2 or g" CARRE " = move th front face twice (the sense does not matter)\n"
  "  h = move the top face in the no-trigonometric sense\n"
  "  h' or a- = move the top face in the trigonometric sense\n"
  "  h2 or h" CARRE " = move th front face twice (the sense does not matter)\n"
  "  b = move the bottom face in the no-trigonometric sense\n"
  "  b' or a- = move the bottom face in the trigonometric sense\n"
  "  b2 or b" CARRE " = move th front face twice (the sense does not matter)\n"
          );
  } else {
    printf("No help avaible about this word\n");
  }
  printf("\n");
}


int check(char *command)
{
  unsigned int i;
  
  for( i = 0 ; i < strlen(command) ; i++ ) {
    switch(command[i]) {
    case 'a':
    case 'p':
    case 'd':
    case 'g':
    case 'h':
    case 'b':
    case '-':
    case '\'':
    case '2':
#ifdef _WIN32
    case 'ý'://²
#else
    case '²':
#endif //_WIN32
    case '.':
    case ' ':
      continue;
    }
    return 0;
  }
  return 1;
}


void *interpretor( void *arg )
{
  char command[256];
  CUBE *cube = (CUBE*)arg;
  
  printf(
         "Welcome to the Rubik's Cube Simulotor vers 0.1\n"
         "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
         );
  printhelp(NULL);
  for(;;) {
    fgets(command,256,stdin);
    command[strlen(command)-1]=0;
    if(!strcmp(command,"help")) {
      printhelp(NULL);
    } else if(!strncmp(command,"help ",5)) {
      printhelp(command+5);
    } else if(!strcmp(command,"reset")) {
      Reset(cube);
      printf("OK\n");
    } else if(!strcmp(command,"scramble")) {
      Scramble(cube);
      printf("OK\n");
    } else if(!strcmp(command,"exit")) {
      exit(0);
    } else if(!strcmp(command,"test")) {
      test(cube);
      printf("OK\n");
    } else if((!strcmp(command,"rxy"))||(!strcmp(command,"ryx"))) {
      r_xy(cube);
      printf("OK\n");
    } else if((!strcmp(command,"rxy'"))||(!strcmp(command,"rxy-"))||
              (!strcmp(command,"ryx'"))||(!strcmp(command,"ryx-"))) {
      r_xy_inv(cube);
      printf("OK\n");
    } else if((!strcmp(command,"rxz"))||(!strcmp(command,"rzx"))) {
      r_xz(cube);
      printf("OK\n");
    } else if((!strcmp(command,"rxz'"))||(!strcmp(command,"rxz-"))||
              (!strcmp(command,"rzx'"))||(!strcmp(command,"rzx-"))) {
      r_xz_inv(cube);
      printf("OK\n");
    } else if((!strcmp(command,"ryz"))||(!strcmp(command,"rzy"))) {
      r_xy(cube);
      printf("OK\n");
    } else if((!strcmp(command,"ryz'"))||(!strcmp(command,"ryz-"))||
              (!strcmp(command,"rzy'"))||(!strcmp(command,"rzy-"))) {
      r_xy_inv(cube);
      printf("OK\n");
    } else if(check(command)) {
      Exec(cube,command);
      printf("OK\n");
    } else {
      printf("Invalid command\n");
    }
  }
#ifndef _WIN32
  pthread_exit(0);
#endif //_WIN32
}


#ifdef _WIN32
DWORD WINAPI InterpretorThread(LPVOID *param)
{
  interpretor((CUBE*)param);
  return 0;
}
#endif //_WIN32


void runinterpretor( CUBE *cube )
{
#ifdef _WIN32
  DWORD dw;
  CreateThread(NULL,0,InterpretorThread,cube,0,&dw);
#else
  pthread_t th;
  if(pthread_create(&th, NULL, interpretor, cube) < 0) {
    printf("ERROR: Cannot create thread\n");
  }
  pthread_detach(th);
#endif //_WIN32
}


/* END OF interpretor.c */
