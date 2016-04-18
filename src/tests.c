/* tests.c : tests pour voir la couleur d'une certaine face
 *           test functions
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

#include "tests.h"

/* Faces */

//CF
COLOR facea(CUBE*cube){ return cube->cubelet[1][1][0].face[0]; }
COLOR facep(CUBE*cube){ return cube->cubelet[1][1][2].face[5]; }
COLOR faced(CUBE*cube){ return cube->cubelet[2][1][1].face[2]; }
COLOR faceg(CUBE*cube){ return cube->cubelet[0][1][1].face[4]; }
COLOR faceh(CUBE*cube){ return cube->cubelet[1][2][1].face[1]; }
COLOR faceb(CUBE*cube){ return cube->cubelet[1][0][1].face[3]; }

COLOR faceah(CUBE*cube){ return cube->cubelet[1][2][0].face[0]; }
COLOR facedh(CUBE*cube){ return cube->cubelet[2][2][1].face[2]; }
COLOR facegh(CUBE*cube){ return cube->cubelet[0][2][1].face[4]; }
COLOR faceph(CUBE*cube){ return cube->cubelet[1][2][2].face[5]; }
COLOR faceab(CUBE*cube){ return cube->cubelet[1][0][0].face[0]; }
COLOR facedb(CUBE*cube){ return cube->cubelet[2][0][1].face[2]; }
COLOR facegb(CUBE*cube){ return cube->cubelet[0][0][1].face[4]; }
COLOR facepb(CUBE*cube){ return cube->cubelet[1][0][2].face[5]; }
COLOR facead(CUBE*cube){ return cube->cubelet[2][1][0].face[0]; }
COLOR faceag(CUBE*cube){ return cube->cubelet[0][1][0].face[0]; }
COLOR facepd(CUBE*cube){ return cube->cubelet[2][1][2].face[5]; }
COLOR facepg(CUBE*cube){ return cube->cubelet[0][1][2].face[5]; }

//CA
COLOR faceha(CUBE*cube){ return cube->cubelet[1][2][0].face[1]; }
COLOR facehd(CUBE*cube){ return cube->cubelet[2][2][1].face[1]; }
COLOR facehg(CUBE*cube){ return cube->cubelet[0][2][1].face[1]; }
COLOR facehp(CUBE*cube){ return cube->cubelet[1][2][2].face[1]; }
COLOR faceba(CUBE*cube){ return cube->cubelet[1][0][0].face[3]; }
COLOR facebd(CUBE*cube){ return cube->cubelet[2][0][1].face[3]; }
COLOR facebg(CUBE*cube){ return cube->cubelet[0][0][1].face[3]; }
COLOR facebp(CUBE*cube){ return cube->cubelet[1][0][2].face[3]; }
COLOR faceda(CUBE*cube){ return cube->cubelet[2][1][0].face[2]; }
COLOR facega(CUBE*cube){ return cube->cubelet[0][1][0].face[4]; }
COLOR facedp(CUBE*cube){ return cube->cubelet[2][1][2].face[2]; }
COLOR facegp(CUBE*cube){ return cube->cubelet[0][1][2].face[4]; }

//CS
COLOR facegah(CUBE*cube){ return cube->cubelet[0][2][0].face[4]; }
COLOR facehag(CUBE*cube){ return cube->cubelet[0][2][0].face[1]; }
COLOR faceahg(CUBE*cube){ return cube->cubelet[0][2][0].face[0]; }

COLOR facedah(CUBE*cube){ return cube->cubelet[2][2][0].face[2]; }
COLOR facehad(CUBE*cube){ return cube->cubelet[2][2][0].face[1]; }
COLOR faceahd(CUBE*cube){ return cube->cubelet[2][2][0].face[0]; }

COLOR facegph(CUBE*cube){ return cube->cubelet[0][2][2].face[4]; }
COLOR facehpg(CUBE*cube){ return cube->cubelet[0][2][2].face[1]; }
COLOR facephg(CUBE*cube){ return cube->cubelet[0][2][2].face[5]; }

COLOR facedph(CUBE*cube){ return cube->cubelet[2][2][2].face[2]; }
COLOR facehpd(CUBE*cube){ return cube->cubelet[2][2][2].face[1]; }
COLOR facephd(CUBE*cube){ return cube->cubelet[2][2][2].face[5]; }

COLOR facegab(CUBE*cube){ return cube->cubelet[0][0][0].face[4]; }
COLOR facebag(CUBE*cube){ return cube->cubelet[0][0][0].face[3]; }
COLOR faceabg(CUBE*cube){ return cube->cubelet[0][0][0].face[0]; }

COLOR facedab(CUBE*cube){ return cube->cubelet[2][0][0].face[2]; }
COLOR facebad(CUBE*cube){ return cube->cubelet[2][0][0].face[3]; }
COLOR faceabd(CUBE*cube){ return cube->cubelet[2][0][0].face[0]; }

COLOR facegpb(CUBE*cube){ return cube->cubelet[0][0][2].face[4]; }
COLOR facebpg(CUBE*cube){ return cube->cubelet[0][0][2].face[3]; }
COLOR facepbg(CUBE*cube){ return cube->cubelet[0][0][2].face[5]; }

COLOR facedpb(CUBE*cube){ return cube->cubelet[2][0][2].face[2]; }
COLOR facebpd(CUBE*cube){ return cube->cubelet[2][0][2].face[3]; }
COLOR facepbd(CUBE*cube){ return cube->cubelet[2][0][2].face[5]; }


/* Places */

//CA
CA ah(CUBE*cube)
{
  if(((faceah(cube)==I)&&(faceha(cube)==R))||
     ((faceah(cube)==R)&&(faceha(cube)==I)))
    return IR;
  else if(((faceah(cube)==I)&&(faceha(cube)==B))||
          ((faceah(cube)==B)&&(faceha(cube)==I)))
    return IB;
  else if(((faceah(cube)==I)&&(faceha(cube)==V))||
          ((faceah(cube)==V)&&(faceha(cube)==I)))
    return IV;
  else if(((faceah(cube)==I)&&(faceha(cube)==O))||
          ((faceah(cube)==O)&&(faceha(cube)==I)))
    return IO;
  else if(((faceah(cube)==J)&&(faceha(cube)==R))||
          ((faceah(cube)==R)&&(faceha(cube)==J)))
    return JR;
  else if(((faceah(cube)==J)&&(faceha(cube)==B))||
          ((faceah(cube)==B)&&(faceha(cube)==J)))
    return JB;
  else if(((faceah(cube)==J)&&(faceha(cube)==V))||
          ((faceah(cube)==V)&&(faceha(cube)==J)))
    return JV;
  else if(((faceah(cube)==J)&&(faceha(cube)==O))||
          ((faceah(cube)==O)&&(faceha(cube)==J)))
    return JO;
  else if(((faceah(cube)==O)&&(faceha(cube)==B))||
          ((faceah(cube)==B)&&(faceha(cube)==O)))
    return OB;
  else if(((faceah(cube)==R)&&(faceha(cube)==B))||
          ((faceah(cube)==B)&&(faceha(cube)==R)))
    return RB;
  else if(((faceah(cube)==O)&&(faceha(cube)==V))||
          ((faceah(cube)==V)&&(faceha(cube)==O)))
    return OV;
  else if(((faceah(cube)==R)&&(faceha(cube)==V))||
          ((faceah(cube)==V)&&(faceha(cube)==R)))
    return RV;
}

CA dh(CUBE*cube)
{
  if(((facedh(cube)==I)&&(facehd(cube)==R))||
     ((facedh(cube)==R)&&(facehd(cube)==I)))
    return IR;
  else if(((facedh(cube)==I)&&(facehd(cube)==B))||
          ((facedh(cube)==B)&&(facehd(cube)==I)))
    return IB;
  else if(((facedh(cube)==I)&&(facehd(cube)==V))||
          ((facedh(cube)==V)&&(facehd(cube)==I)))
    return IV;
  else if(((facedh(cube)==I)&&(facehd(cube)==O))||
          ((facedh(cube)==O)&&(facehd(cube)==I)))
    return IO;
  else if(((facedh(cube)==J)&&(facehd(cube)==R))||
          ((facedh(cube)==R)&&(facehd(cube)==J)))
    return JR;
  else if(((facedh(cube)==J)&&(facehd(cube)==B))||
          ((facedh(cube)==B)&&(facehd(cube)==J)))
    return JB;
  else if(((facedh(cube)==J)&&(facehd(cube)==V))||
          ((facedh(cube)==V)&&(facehd(cube)==J)))
    return JV;
  else if(((facedh(cube)==J)&&(facehd(cube)==O))||
          ((facedh(cube)==O)&&(facehd(cube)==J)))
    return JO;
  else if(((facedh(cube)==O)&&(facehd(cube)==B))||
          ((facedh(cube)==B)&&(facehd(cube)==O)))
    return OB;
  else if(((facedh(cube)==R)&&(facehd(cube)==B))||
          ((facedh(cube)==B)&&(facehd(cube)==R)))
    return RB;
  else if(((facedh(cube)==O)&&(facehd(cube)==V))||
          ((facedh(cube)==V)&&(facehd(cube)==O)))
    return OV;
  else if(((facedh(cube)==R)&&(facehd(cube)==V))||
          ((facedh(cube)==V)&&(facehd(cube)==R)))
    return RV;
}

CA gh(CUBE*cube)
{
  if(((facegh(cube)==I)&&(facehg(cube)==R))||
     ((facegh(cube)==R)&&(facehg(cube)==I)))
    return IR;
  else if(((facegh(cube)==I)&&(facehg(cube)==B))||
          ((facegh(cube)==B)&&(facehg(cube)==I)))
    return IB;
  else if(((facegh(cube)==I)&&(facehg(cube)==V))||
          ((facegh(cube)==V)&&(facehg(cube)==I)))
    return IV;
  else if(((facegh(cube)==I)&&(facehg(cube)==O))||
          ((facegh(cube)==O)&&(facehg(cube)==I)))
    return IO;
  else if(((facegh(cube)==J)&&(facehg(cube)==R))||
          ((facegh(cube)==R)&&(facehg(cube)==J)))
    return JR;
  else if(((facegh(cube)==J)&&(facehg(cube)==B))||
          ((facegh(cube)==B)&&(facehg(cube)==J)))
    return JB;
  else if(((facegh(cube)==J)&&(facehg(cube)==V))||
          ((facegh(cube)==V)&&(facehg(cube)==J)))
    return JV;
  else if(((facegh(cube)==J)&&(facehg(cube)==O))||
          ((facegh(cube)==O)&&(facehg(cube)==J)))
    return JO;
  else if(((facegh(cube)==O)&&(facehg(cube)==B))||
          ((facegh(cube)==O)&&(facehg(cube)==J)))
    return JO;
  else if(((facegh(cube)==O)&&(facehg(cube)==B))||
          ((facegh(cube)==B)&&(facehg(cube)==O)))
    return OB;
  else if(((facegh(cube)==R)&&(facehg(cube)==B))||
          ((facegh(cube)==B)&&(facehg(cube)==R)))
    return RB;
  else if(((facegh(cube)==O)&&(facehg(cube)==V))||
          ((facegh(cube)==V)&&(facehg(cube)==O)))
    return OV;
  else if(((facegh(cube)==R)&&(facehg(cube)==V))||
          ((facegh(cube)==V)&&(facehg(cube)==R)))
    return RV;
}

CA ph(CUBE*cube)
{
  if(((faceph(cube)==I)&&(facehp(cube)==R))||
     ((faceph(cube)==R)&&(facehp(cube)==I)))
    return IR;
  else if(((faceph(cube)==I)&&(facehp(cube)==B))||
          ((faceph(cube)==B)&&(facehp(cube)==I)))
    return IB;
  else if(((faceph(cube)==I)&&(facehp(cube)==V))||
          ((faceph(cube)==V)&&(facehp(cube)==I)))
    return IV;
  else if(((faceph(cube)==I)&&(facehp(cube)==O))||
          ((faceph(cube)==O)&&(facehp(cube)==I)))
    return IO;
  else if(((faceph(cube)==J)&&(facehp(cube)==R))||
          ((faceph(cube)==R)&&(facehp(cube)==J)))
    return JR;
  else if(((faceph(cube)==J)&&(facehp(cube)==B))||
          ((faceph(cube)==B)&&(facehp(cube)==J)))
    return JB;
  else if(((faceph(cube)==J)&&(facehp(cube)==V))||
          ((faceph(cube)==V)&&(facehp(cube)==J)))
    return JV;
  else if(((faceph(cube)==J)&&(facehp(cube)==O))||
          ((faceph(cube)==O)&&(facehp(cube)==J)))
    return JO;
  else if(((faceph(cube)==O)&&(facehp(cube)==B))||
          ((faceph(cube)==B)&&(facehp(cube)==O)))
    return OB;
  else if(((faceph(cube)==R)&&(facehp(cube)==B))||
          ((faceph(cube)==B)&&(facehp(cube)==R)))
    return RB;
  else if(((faceph(cube)==O)&&(facehp(cube)==V))||
          ((faceph(cube)==V)&&(facehp(cube)==O)))
    return OV;
  else if(((faceph(cube)==R)&&(facehp(cube)==V))||
          ((faceph(cube)==V)&&(facehp(cube)==R)))
    return RV;
}

CA ab(CUBE*cube)
{
  if(((faceab(cube)==I)&&(faceba(cube)==R))||((faceab(cube)==R)&&(faceba(cube)==I)))
    return IR;
  else if(((faceab(cube)==I)&&(faceba(cube)==B))||((faceab(cube)==B)&&(faceba(cube)==I)))
    return IB;
  else if(((faceab(cube)==I)&&(faceba(cube)==V))||
          ((faceab(cube)==V)&&(faceba(cube)==I)))
    return IV;
  else if(((faceab(cube)==I)&&(faceba(cube)==O))||
          ((faceab(cube)==O)&&(faceba(cube)==I)))
    return IO;
  else if(((faceab(cube)==J)&&(faceba(cube)==R))||
          ((faceab(cube)==R)&&(faceba(cube)==J)))
    return JR;
  else if(((faceab(cube)==J)&&(faceba(cube)==B))||
          ((faceab(cube)==B)&&(faceba(cube)==J)))
    return JB;
  else if(((faceab(cube)==J)&&(faceba(cube)==V))||
          ((faceab(cube)==V)&&(faceba(cube)==J)))
    return JV;
  else if(((faceab(cube)==J)&&(faceba(cube)==O))||
          ((faceab(cube)==O)&&(faceba(cube)==J)))
    return JO;
  else if(((faceab(cube)==O)&&(faceba(cube)==B))||
          ((faceab(cube)==B)&&(faceba(cube)==O)))
    return OB;
  else if(((faceab(cube)==R)&&(faceba(cube)==B))||
          ((faceab(cube)==B)&&(faceba(cube)==R)))
    return RB;
  else if(((faceab(cube)==O)&&(faceba(cube)==V))||
          ((faceab(cube)==V)&&(faceba(cube)==O)))
    return OV;
  else if(((faceab(cube)==R)&&(faceba(cube)==V))||
          ((faceab(cube)==V)&&(faceba(cube)==R)))
    return RV;
}

CA db(CUBE*cube)
{
  if(((facedb(cube)==I)&&(facebd(cube)==R))||
     ((facedb(cube)==R)&&(facebd(cube)==I)))
    return IR;
  else if(((facedb(cube)==I)&&(facebd(cube)==B))||
          ((facedb(cube)==B)&&(facebd(cube)==I)))
    return IB;
  else if(((facedb(cube)==I)&&(facebd(cube)==V))||
          ((facedb(cube)==V)&&(facebd(cube)==I)))
    return IV;
  else if(((facedb(cube)==I)&&(facebd(cube)==O))||
          ((facedb(cube)==O)&&(facebd(cube)==I)))
    return IO;
  else if(((facedb(cube)==J)&&(facebd(cube)==R))||
          ((facedb(cube)==R)&&(facebd(cube)==J)))
    return JR;
  else if(((facedb(cube)==J)&&(facebd(cube)==B))||
          ((facedb(cube)==B)&&(facebd(cube)==J)))
    return JB;
  else if(((facedb(cube)==J)&&(facebd(cube)==V))||
          ((facedb(cube)==V)&&(facebd(cube)==J)))
    return JV;
  else if(((facedb(cube)==J)&&(facebd(cube)==O))||
          ((facedb(cube)==O)&&(facebd(cube)==J)))
    return JO;
  else if(((facedb(cube)==O)&&(facebd(cube)==B))||
          ((facedb(cube)==B)&&(facebd(cube)==O)))
    return OB;
  else if(((facedb(cube)==R)&&(facebd(cube)==B))||
          ((facedb(cube)==B)&&(facebd(cube)==R)))
    return RB;
  else if(((facedb(cube)==O)&&(facebd(cube)==V))||
          ((facedb(cube)==V)&&(facebd(cube)==O)))
    return OV;
  else if(((facedb(cube)==R)&&(facebd(cube)==V))||
          ((facedb(cube)==V)&&(facebd(cube)==R)))
    return RV;
}

CA gb(CUBE*cube)
{
  if(((facegb(cube)==I)&&(facebg(cube)==R))||
     ((facegb(cube)==R)&&(facebg(cube)==I)))
    return IR;
  else if(((facegb(cube)==I)&&(facebg(cube)==B))||
          ((facegb(cube)==B)&&(facebg(cube)==I)))
    return IB;
  else if(((facegb(cube)==I)&&(facebg(cube)==V))||
          ((facegb(cube)==V)&&(facebg(cube)==I)))
    return IV;
  else if(((facegb(cube)==I)&&(facebg(cube)==O))||
          ((facegb(cube)==O)&&(facebg(cube)==I)))
    return IO;
  else if(((facegb(cube)==J)&&(facebg(cube)==R))||
          ((facegb(cube)==R)&&(facebg(cube)==J)))
    return JR;
  else if(((facegb(cube)==J)&&(facebg(cube)==B))||
          ((facegb(cube)==B)&&(facebg(cube)==J)))
    return JB;
  else if(((facegb(cube)==J)&&(facebg(cube)==V))||
          ((facegb(cube)==V)&&(facebg(cube)==J)))
    return JV;
  else if(((facegb(cube)==J)&&(facebg(cube)==O))||
          ((facegb(cube)==O)&&(facebg(cube)==J)))
    return JO;
  else if(((facegb(cube)==O)&&(facebg(cube)==B))||
          ((facegb(cube)==B)&&(facebg(cube)==O)))
    return OB;
  else if(((facegb(cube)==R)&&(facebg(cube)==B))||
          ((facegb(cube)==B)&&(facebg(cube)==R)))
    return RB;
  else if(((facegb(cube)==O)&&(facebg(cube)==V))||
          ((facegb(cube)==V)&&(facebg(cube)==O)))
    return OV;
  else if(((facegb(cube)==R)&&(facebg(cube)==V))||
          ((facegb(cube)==V)&&(facebg(cube)==R)))
    return RV;
}

CA pb(CUBE*cube)
{
  if(((facepb(cube)==I)&&(facebp(cube)==R))||
     ((facepb(cube)==R)&&(facebp(cube)==I)))
    return IR;
  else if(((facepb(cube)==I)&&(facebp(cube)==B))||
          ((facepb(cube)==B)&&(facebp(cube)==I)))
    return IB;
  else if(((facepb(cube)==I)&&(facebp(cube)==V))||
          ((facepb(cube)==V)&&(facebp(cube)==I)))
    return IV;
  else if(((facepb(cube)==I)&&(facebp(cube)==O))||
          ((facepb(cube)==O)&&(facebp(cube)==I)))
    return IO;
  else if(((facepb(cube)==J)&&(facebp(cube)==R))||
          ((facepb(cube)==R)&&(facebp(cube)==J)))
    return JR;
  else if(((facepb(cube)==J)&&(facebp(cube)==B))||
          ((facepb(cube)==B)&&(facebp(cube)==J)))
    return JB;
  else if(((facepb(cube)==J)&&(facebp(cube)==V))||
          ((facepb(cube)==V)&&(facebp(cube)==J)))
    return JV;
  else if(((facepb(cube)==J)&&(facebp(cube)==O))||
          ((facepb(cube)==O)&&(facebp(cube)==J)))
    return JO;
  else if(((facepb(cube)==O)&&(facebp(cube)==B))||
          ((facepb(cube)==B)&&(facebp(cube)==O)))
    return OB;
  else if(((facepb(cube)==R)&&(facebp(cube)==B))||
          ((facepb(cube)==B)&&(facebp(cube)==R)))
    return RB;
  else if(((facepb(cube)==O)&&(facebp(cube)==V))||
          ((facepb(cube)==V)&&(facebp(cube)==O)))
    return OV;
  else if(((facepb(cube)==R)&&(facebp(cube)==V))||
          ((facepb(cube)==V)&&(facebp(cube)==R)))
    return RV;
}

CA ad(CUBE*cube)
{
  if(((facead(cube)==I)&&(faceda(cube)==R))||
     ((facead(cube)==R)&&(faceda(cube)==I)))
    return IR;
  else if(((facead(cube)==I)&&(faceda(cube)==B))||
          ((facead(cube)==B)&&(faceda(cube)==I)))
    return IB;
  else if(((facead(cube)==I)&&(faceda(cube)==V))||
          ((facead(cube)==V)&&(faceda(cube)==I)))
    return IV;
  else if(((facead(cube)==I)&&(faceda(cube)==O))||
          ((facead(cube)==O)&&(faceda(cube)==I)))
    return IO;
  else if(((facead(cube)==J)&&(faceda(cube)==R))||
          ((facead(cube)==R)&&(faceda(cube)==J)))
    return JR;
  else if(((facead(cube)==J)&&(faceda(cube)==B))||
          ((facead(cube)==B)&&(faceda(cube)==J)))
    return JB;
  else if(((facead(cube)==J)&&(faceda(cube)==V))||
          ((facead(cube)==V)&&(faceda(cube)==J)))
    return JV;
  else if(((facead(cube)==J)&&(faceda(cube)==O))||
          ((facead(cube)==O)&&(faceda(cube)==J)))
    return JO;
  else if(((facead(cube)==O)&&(faceda(cube)==B))||
          ((facead(cube)==B)&&(faceda(cube)==O)))
    return OB;
  else if(((facead(cube)==R)&&(faceda(cube)==B))||
          ((facead(cube)==B)&&(faceda(cube)==R)))
    return RB;
  else if(((facead(cube)==O)&&(faceda(cube)==V))||
          ((facead(cube)==V)&&(faceda(cube)==O)))
    return OV;
  else if(((facead(cube)==R)&&(faceda(cube)==V))||
          ((facead(cube)==V)&&(faceda(cube)==R)))
    return RV;
}

CA ag(CUBE*cube)
{
  if(((faceag(cube)==I)&&(facega(cube)==R))||
     ((faceag(cube)==R)&&(facega(cube)==I)))
    return IR;
  else if(((faceag(cube)==I)&&(facega(cube)==B))||
          ((faceag(cube)==B)&&(facega(cube)==I)))
    return IB;
  else if(((faceag(cube)==I)&&(facega(cube)==V))||
          ((faceag(cube)==V)&&(facega(cube)==I)))
    return IV;
  else if(((faceag(cube)==I)&&(facega(cube)==O))||
          ((faceag(cube)==O)&&(facega(cube)==I)))
    return IO;
  else if(((faceag(cube)==J)&&(facega(cube)==R))||
          ((faceag(cube)==R)&&(facega(cube)==J)))
    return JR;
  else if(((faceag(cube)==J)&&(facega(cube)==B))||
          ((faceag(cube)==B)&&(facega(cube)==J)))
    return JB;
  else if(((faceag(cube)==J)&&(facega(cube)==V))||
          ((faceag(cube)==V)&&(facega(cube)==J)))
    return JV;
  else if(((faceag(cube)==J)&&(facega(cube)==O))||
          ((faceag(cube)==O)&&(facega(cube)==J)))
    return JO;
  else if(((faceag(cube)==O)&&(facega(cube)==B))||
          ((faceag(cube)==B)&&(facega(cube)==O)))
    return OB;
  else if(((faceag(cube)==R)&&(facega(cube)==B))||
          ((faceag(cube)==B)&&(facega(cube)==R)))
    return RB;
  else if(((faceag(cube)==O)&&(facega(cube)==V))||
          ((faceag(cube)==V)&&(facega(cube)==O)))
    return OV;
  else if(((faceag(cube)==R)&&(facega(cube)==V))||
          ((faceag(cube)==V)&&(facega(cube)==R)))
    return RV;
}

CA pd(CUBE*cube)
{
  if(((facepd(cube)==I)&&(facedp(cube)==R))||
     ((facepd(cube)==R)&&(facedp(cube)==I)))
    return IR;
  else if(((facepd(cube)==I)&&(facedp(cube)==B))||
          ((facepd(cube)==B)&&(facedp(cube)==I)))
    return IB;
  else if(((facepd(cube)==I)&&(facedp(cube)==V))||
          ((facepd(cube)==V)&&(facedp(cube)==I)))
    return IV;
  else if(((facepd(cube)==I)&&(facedp(cube)==O))||
          ((facepd(cube)==O)&&(facedp(cube)==I)))
    return IO;
  else if(((facepd(cube)==J)&&(facedp(cube)==R))||
          ((facepd(cube)==R)&&(facedp(cube)==J)))
    return JR;
  else if(((facepd(cube)==J)&&(facedp(cube)==B))||
          ((facepd(cube)==B)&&(facedp(cube)==J)))
    return JB;
  else if(((facepd(cube)==J)&&(facedp(cube)==V))||
          ((facepd(cube)==V)&&(facedp(cube)==J)))
    return JV;
  else if(((facepd(cube)==J)&&(facedp(cube)==O))||
          ((facepd(cube)==O)&&(facedp(cube)==J)))
    return JO;
  else if(((facepd(cube)==O)&&(facedp(cube)==B))||
          ((facepd(cube)==B)&&(facedp(cube)==O)))
    return OB;
  else if(((facepd(cube)==R)&&(facedp(cube)==B))||
          ((facepd(cube)==B)&&(facedp(cube)==R)))
    return RB;
  else if(((facepd(cube)==O)&&(facedp(cube)==V))||
          ((facepd(cube)==V)&&(facedp(cube)==O)))
    return OV;
  else if(((facepd(cube)==R)&&(facedp(cube)==V))||
          ((facepd(cube)==V)&&(facedp(cube)==R)))
    return RV;
}

CA pg(CUBE*cube)
{
  if(((facepg(cube)==I)&&(facegp(cube)==R))||
     ((facepg(cube)==R)&&(facegp(cube)==I)))
    return IR;
  else if(((facepg(cube)==I)&&(facegp(cube)==B))||
          ((facepg(cube)==B)&&(facegp(cube)==I)))
    return IB;
  else if(((facepg(cube)==I)&&(facegp(cube)==V))||
          ((facepg(cube)==V)&&(facegp(cube)==I)))
    return IV;
  else if(((facepg(cube)==I)&&(facegp(cube)==O))||
          ((facepg(cube)==O)&&(facegp(cube)==I)))
    return IO;
  else if(((facepg(cube)==J)&&(facegp(cube)==R))||
          ((facepg(cube)==R)&&(facegp(cube)==J)))
    return JR;
  else if(((facepg(cube)==J)&&(facegp(cube)==B))||
          ((facepg(cube)==B)&&(facegp(cube)==J)))
    return JB;
  else if(((facepg(cube)==J)&&(facegp(cube)==V))||
          ((facepg(cube)==V)&&(facegp(cube)==J)))
    return JV;
  else if(((facepg(cube)==J)&&(facegp(cube)==O))||
          ((facepg(cube)==O)&&(facegp(cube)==J)))
    return JO;
  else if(((facepg(cube)==O)&&(facegp(cube)==B))||
          ((facepg(cube)==B)&&(facegp(cube)==O)))
    return OB;
  else if(((facepg(cube)==R)&&(facegp(cube)==B))||
          ((facepg(cube)==B)&&(facegp(cube)==R)))
    return RB;
  else if(((facepg(cube)==O)&&(facegp(cube)==V))||
          ((facepg(cube)==V)&&(facegp(cube)==O)))
    return OV;
  else if(((facepg(cube)==R)&&(facegp(cube)==V))||
          ((facepg(cube)==V)&&(facegp(cube)==R)))
    return RV;
}

//CS
CS gha(CUBE*cube)
{
  if (((facegha(cube)==I)&&(facehga(cube)==R)&&(faceagh(cube)==B))||
      ((facegha(cube)==I)&&(facehga(cube)==B)&&(faceagh(cube)==R))||
      ((facegha(cube)==R)&&(facehga(cube)==I)&&(faceagh(cube)==B))||
      ((facegha(cube)==R)&&(facehga(cube)==B)&&(faceagh(cube)==I))||
      ((facegha(cube)==B)&&(facehga(cube)==I)&&(faceagh(cube)==R))||
      ((facegha(cube)==B)&&(facehga(cube)==R)&&(faceagh(cube)==I)))
    return IRB;
  else if(((facegha(cube)==I)&&(facehga(cube)==R)&&(faceagh(cube)==V))||
          ((facegha(cube)==I)&&(facehga(cube)==V)&&(faceagh(cube)==R))||
          ((facegha(cube)==R)&&(facehga(cube)==I)&&(faceagh(cube)==V))||
          ((facegha(cube)==R)&&(facehga(cube)==V)&&(faceagh(cube)==I))||
          ((facegha(cube)==V)&&(facehga(cube)==I)&&(faceagh(cube)==R))||
          ((facegha(cube)==V)&&(facehga(cube)==R)&&(faceagh(cube)==I)))
    return IRV;
  else if(((facegha(cube)==J)&&(facehga(cube)==R)&&(faceagh(cube)==V))||
          ((facegha(cube)==J)&&(facehga(cube)==V)&&(faceagh(cube)==R))||
          ((facegha(cube)==R)&&(facehga(cube)==J)&&(faceagh(cube)==V))||
          ((facegha(cube)==R)&&(facehga(cube)==V)&&(faceagh(cube)==J))||
          ((facegha(cube)==V)&&(facehga(cube)==J)&&(faceagh(cube)==R))||
          ((facegha(cube)==V)&&(facehga(cube)==R)&&(faceagh(cube)==J)))
    return JRV;
  else if(((facegha(cube)==J)&&(facehga(cube)==R)&&(faceagh(cube)==B))||
          ((facegha(cube)==J)&&(facehga(cube)==B)&&(faceagh(cube)==R))||
          ((facegha(cube)==R)&&(facehga(cube)==J)&&(faceagh(cube)==B))||
          ((facegha(cube)==R)&&(facehga(cube)==B)&&(faceagh(cube)==J))||
          ((facegha(cube)==B)&&(facehga(cube)==J)&&(faceagh(cube)==R))||
          ((facegha(cube)==B)&&(facehga(cube)==R)&&(faceagh(cube)==J)))
    return JRB;
  else if(((facegha(cube)==I)&&(facehga(cube)==O)&&(faceagh(cube)==V))||
          ((facegha(cube)==I)&&(facehga(cube)==V)&&(faceagh(cube)==O))||
          ((facegha(cube)==O)&&(facehga(cube)==I)&&(faceagh(cube)==V))||
          ((facegha(cube)==O)&&(facehga(cube)==V)&&(faceagh(cube)==I))||
          ((facegha(cube)==V)&&(facehga(cube)==I)&&(faceagh(cube)==O))||
          ((facegha(cube)==V)&&(facehga(cube)==O)&&(faceagh(cube)==I)))
    return IOV;
  else if(((facegha(cube)==J)&&(facehga(cube)==O)&&(faceagh(cube)==V))||
          ((facegha(cube)==J)&&(facehga(cube)==V)&&(faceagh(cube)==O))||
          ((facegha(cube)==O)&&(facehga(cube)==J)&&(faceagh(cube)==V))||
          ((facegha(cube)==O)&&(facehga(cube)==V)&&(faceagh(cube)==J))||
          ((facegha(cube)==V)&&(facehga(cube)==J)&&(faceagh(cube)==O))||
          ((facegha(cube)==V)&&(facehga(cube)==O)&&(faceagh(cube)==J)))
    return JOV;
  else if(((facegha(cube)==J)&&(facehga(cube)==O)&&(faceagh(cube)==B))||
          ((facegha(cube)==J)&&(facehga(cube)==B)&&(faceagh(cube)==O))||
          ((facegha(cube)==O)&&(facehga(cube)==J)&&(faceagh(cube)==B))||
          ((facegha(cube)==O)&&(facehga(cube)==B)&&(faceagh(cube)==J))||
          ((facegha(cube)==B)&&(facehga(cube)==J)&&(faceagh(cube)==O))||
          ((facegha(cube)==B)&&(facehga(cube)==O)&&(faceagh(cube)==J)))
    return JOB;
  else if(((facegha(cube)==I)&&(facehga(cube)==O)&&(faceagh(cube)==B))||
          ((facegha(cube)==I)&&(facehga(cube)==B)&&(faceagh(cube)==O))||
          ((facegha(cube)==O)&&(facehga(cube)==I)&&(faceagh(cube)==B))||
          ((facegha(cube)==O)&&(facehga(cube)==B)&&(faceagh(cube)==I))||
          ((facegha(cube)==B)&&(facehga(cube)==I)&&(faceagh(cube)==O))||
          ((facegha(cube)==B)&&(facehga(cube)==O)&&(faceagh(cube)==I)))
    return IOB;
}

CS dha(CUBE*cube)
{
  if (((facedha(cube)==I)&&(facehda(cube)==R)&&(faceadh(cube)==B))||
      ((facedha(cube)==I)&&(facehda(cube)==B)&&(faceadh(cube)==R))||
      ((facedha(cube)==R)&&(facehda(cube)==I)&&(faceadh(cube)==B))||
      ((facedha(cube)==R)&&(facehda(cube)==B)&&(faceadh(cube)==I))||
      ((facedha(cube)==B)&&(facehda(cube)==I)&&(faceadh(cube)==R))||
      ((facedha(cube)==B)&&(facehda(cube)==R)&&(faceadh(cube)==I)))
    return IRB;
  else if(((facedha(cube)==I)&&(facehda(cube)==R)&&(faceadh(cube)==V))||
          ((facedha(cube)==I)&&(facehda(cube)==V)&&(faceadh(cube)==R))||
          ((facedha(cube)==R)&&(facehda(cube)==I)&&(faceadh(cube)==V))||
          ((facedha(cube)==R)&&(facehda(cube)==V)&&(faceadh(cube)==I))||
          ((facedha(cube)==V)&&(facehda(cube)==I)&&(faceadh(cube)==R))||
          ((facedha(cube)==V)&&(facehda(cube)==R)&&(faceadh(cube)==I)))
    return IRV;
  else if(((facedha(cube)==J)&&(facehda(cube)==R)&&(faceadh(cube)==V))||
          ((facedha(cube)==J)&&(facehda(cube)==V)&&(faceadh(cube)==R))||
          ((facedha(cube)==R)&&(facehda(cube)==J)&&(faceadh(cube)==V))||
          ((facedha(cube)==R)&&(facehda(cube)==V)&&(faceadh(cube)==J))||
          ((facedha(cube)==V)&&(facehda(cube)==J)&&(faceadh(cube)==R))||
          ((facedha(cube)==V)&&(facehda(cube)==R)&&(faceadh(cube)==J)))
    return JRV;
  else if(((facedha(cube)==J)&&(facehda(cube)==R)&&(faceadh(cube)==B))||
          ((facedha(cube)==J)&&(facehda(cube)==B)&&(faceadh(cube)==R))||
          ((facedha(cube)==R)&&(facehda(cube)==J)&&(faceadh(cube)==B))||
          ((facedha(cube)==R)&&(facehda(cube)==B)&&(faceadh(cube)==J))||
          ((facedha(cube)==B)&&(facehda(cube)==J)&&(faceadh(cube)==R))||
          ((facedha(cube)==B)&&(facehda(cube)==R)&&(faceadh(cube)==J)))
    return JRB;
  else if(((facedha(cube)==I)&&(facehda(cube)==O)&&(faceadh(cube)==V))||
          ((facedha(cube)==I)&&(facehda(cube)==V)&&(faceadh(cube)==O))||
          ((facedha(cube)==O)&&(facehda(cube)==I)&&(faceadh(cube)==V))||
          ((facedha(cube)==O)&&(facehda(cube)==V)&&(faceadh(cube)==I))||
          ((facedha(cube)==V)&&(facehda(cube)==I)&&(faceadh(cube)==O))||
          ((facedha(cube)==V)&&(facehda(cube)==O)&&(faceadh(cube)==I)))
    return IOV;
  else if(((facedha(cube)==J)&&(facehda(cube)==O)&&(faceadh(cube)==V))||
          ((facedha(cube)==J)&&(facehda(cube)==V)&&(faceadh(cube)==O))||
          ((facedha(cube)==O)&&(facehda(cube)==J)&&(faceadh(cube)==V))||
          ((facedha(cube)==O)&&(facehda(cube)==V)&&(faceadh(cube)==J))||
          ((facedha(cube)==V)&&(facehda(cube)==J)&&(faceadh(cube)==O))||
          ((facedha(cube)==V)&&(facehda(cube)==O)&&(faceadh(cube)==J)))
    return JOV;
  else if(((facedha(cube)==J)&&(facehda(cube)==O)&&(faceadh(cube)==B))||
          ((facedha(cube)==J)&&(facehda(cube)==B)&&(faceadh(cube)==O))||
          ((facedha(cube)==O)&&(facehda(cube)==J)&&(faceadh(cube)==B))||
          ((facedha(cube)==O)&&(facehda(cube)==B)&&(faceadh(cube)==J))||
          ((facedha(cube)==B)&&(facehda(cube)==J)&&(faceadh(cube)==O))||
          ((facedha(cube)==B)&&(facehda(cube)==O)&&(faceadh(cube)==J)))
    return JOB;
  else if(((facedha(cube)==I)&&(facehda(cube)==O)&&(faceadh(cube)==B))||
          ((facedha(cube)==I)&&(facehda(cube)==B)&&(faceadh(cube)==O))||
          ((facedha(cube)==O)&&(facehda(cube)==I)&&(faceadh(cube)==B))||
          ((facedha(cube)==O)&&(facehda(cube)==B)&&(faceadh(cube)==I))||
          ((facedha(cube)==B)&&(facehda(cube)==I)&&(faceadh(cube)==O))||
          ((facedha(cube)==B)&&(facehda(cube)==O)&&(faceadh(cube)==I)))
    return IOB;
}

CS ghp(CUBE*cube)
{
  if (((faceghp(cube)==I)&&(facehgp(cube)==R)&&(facepgh(cube)==B))||
      ((faceghp(cube)==I)&&(facehgp(cube)==B)&&(facepgh(cube)==R))||
      ((faceghp(cube)==R)&&(facehgp(cube)==I)&&(facepgh(cube)==B))||
      ((faceghp(cube)==R)&&(facehgp(cube)==B)&&(facepgh(cube)==I))||
      ((faceghp(cube)==B)&&(facehgp(cube)==I)&&(facepgh(cube)==R))||
      ((faceghp(cube)==B)&&(facehgp(cube)==R)&&(facepgh(cube)==I)))
    return IRB;
  else if(((faceghp(cube)==I)&&(facehgp(cube)==R)&&(facepgh(cube)==V))||
          ((faceghp(cube)==I)&&(facehgp(cube)==V)&&(facepgh(cube)==R))||
          ((faceghp(cube)==R)&&(facehgp(cube)==I)&&(facepgh(cube)==V))||
          ((faceghp(cube)==R)&&(facehgp(cube)==V)&&(facepgh(cube)==I))||
          ((faceghp(cube)==V)&&(facehgp(cube)==I)&&(facepgh(cube)==R))||
          ((faceghp(cube)==V)&&(facehgp(cube)==R)&&(facepgh(cube)==I)))
    return IRV;
  else if(((faceghp(cube)==J)&&(facehgp(cube)==R)&&(facepgh(cube)==V))||
          ((faceghp(cube)==J)&&(facehgp(cube)==V)&&(facepgh(cube)==R))||
          ((faceghp(cube)==R)&&(facehgp(cube)==J)&&(facepgh(cube)==V))||
          ((faceghp(cube)==R)&&(facehgp(cube)==V)&&(facepgh(cube)==J))||
          ((faceghp(cube)==V)&&(facehgp(cube)==J)&&(facepgh(cube)==R))||
          ((faceghp(cube)==V)&&(facehgp(cube)==R)&&(facepgh(cube)==J)))
    return JRV;
  else if(((faceghp(cube)==J)&&(facehgp(cube)==R)&&(facepgh(cube)==B))||
          ((faceghp(cube)==J)&&(facehgp(cube)==B)&&(facepgh(cube)==R))||
          ((faceghp(cube)==R)&&(facehgp(cube)==J)&&(facepgh(cube)==B))||
          ((faceghp(cube)==R)&&(facehgp(cube)==B)&&(facepgh(cube)==J))||
          ((faceghp(cube)==B)&&(facehgp(cube)==J)&&(facepgh(cube)==R))||
          ((faceghp(cube)==B)&&(facehgp(cube)==R)&&(facepgh(cube)==J)))
    return JRB;
  else if(((faceghp(cube)==I)&&(facehgp(cube)==O)&&(facepgh(cube)==V))||
          ((faceghp(cube)==I)&&(facehgp(cube)==V)&&(facepgh(cube)==O))||
          ((faceghp(cube)==O)&&(facehgp(cube)==I)&&(facepgh(cube)==V))||
          ((faceghp(cube)==O)&&(facehgp(cube)==V)&&(facepgh(cube)==I))||
          ((faceghp(cube)==V)&&(facehgp(cube)==I)&&(facepgh(cube)==O))||
          ((faceghp(cube)==V)&&(facehgp(cube)==O)&&(facepgh(cube)==I)))
    return IOV;
  else if(((faceghp(cube)==J)&&(facehgp(cube)==O)&&(facepgh(cube)==V))||
          ((faceghp(cube)==J)&&(facehgp(cube)==V)&&(facepgh(cube)==O))||
          ((faceghp(cube)==O)&&(facehgp(cube)==J)&&(facepgh(cube)==V))||
          ((faceghp(cube)==O)&&(facehgp(cube)==V)&&(facepgh(cube)==J))||
          ((faceghp(cube)==V)&&(facehgp(cube)==J)&&(facepgh(cube)==O))||
          ((faceghp(cube)==V)&&(facehgp(cube)==O)&&(facepgh(cube)==J)))
    return JOV;
  else if(((faceghp(cube)==J)&&(facehgp(cube)==O)&&(facepgh(cube)==B))||
          ((faceghp(cube)==J)&&(facehgp(cube)==B)&&(facepgh(cube)==O))||
          ((faceghp(cube)==O)&&(facehgp(cube)==J)&&(facepgh(cube)==B))||
          ((faceghp(cube)==O)&&(facehgp(cube)==B)&&(facepgh(cube)==J))||
          ((faceghp(cube)==B)&&(facehgp(cube)==J)&&(facepgh(cube)==O))||
          ((faceghp(cube)==B)&&(facehgp(cube)==O)&&(facepgh(cube)==J)))
    return JOB;
  else if(((faceghp(cube)==I)&&(facehgp(cube)==O)&&(facepgh(cube)==B))||
          ((faceghp(cube)==I)&&(facehgp(cube)==B)&&(facepgh(cube)==O))||
          ((faceghp(cube)==O)&&(facehgp(cube)==I)&&(facepgh(cube)==B))||
          ((faceghp(cube)==O)&&(facehgp(cube)==B)&&(facepgh(cube)==I))||
          ((faceghp(cube)==B)&&(facehgp(cube)==I)&&(facepgh(cube)==O))||
          ((faceghp(cube)==B)&&(facehgp(cube)==O)&&(facepgh(cube)==I)))
    return IOB;
}

CS dhp(CUBE*cube)
{
  if (((facedhp(cube)==I)&&(facehdp(cube)==R)&&(facepdh(cube)==B))||
      ((facedhp(cube)==I)&&(facehdp(cube)==B)&&(facepdh(cube)==R))||
      ((facedhp(cube)==R)&&(facehdp(cube)==I)&&(facepdh(cube)==B))||
      ((facedhp(cube)==R)&&(facehdp(cube)==B)&&(facepdh(cube)==I))||
      ((facedhp(cube)==B)&&(facehdp(cube)==I)&&(facepdh(cube)==R))||
      ((facedhp(cube)==B)&&(facehdp(cube)==R)&&(facepdh(cube)==I)))
    return IRB;
  else if(((facedhp(cube)==I)&&(facehdp(cube)==R)&&(facepdh(cube)==V))||
          ((facedhp(cube)==I)&&(facehdp(cube)==V)&&(facepdh(cube)==R))||
          ((facedhp(cube)==R)&&(facehdp(cube)==I)&&(facepdh(cube)==V))||
          ((facedhp(cube)==R)&&(facehdp(cube)==V)&&(facepdh(cube)==I))||
          ((facedhp(cube)==V)&&(facehdp(cube)==I)&&(facepdh(cube)==R))||
          ((facedhp(cube)==V)&&(facehdp(cube)==R)&&(facepdh(cube)==I)))
    return IRV;
  else if(((facedhp(cube)==J)&&(facehdp(cube)==R)&&(facepdh(cube)==V))||
          ((facedhp(cube)==J)&&(facehdp(cube)==V)&&(facepdh(cube)==R))||
          ((facedhp(cube)==R)&&(facehdp(cube)==J)&&(facepdh(cube)==V))||
          ((facedhp(cube)==R)&&(facehdp(cube)==V)&&(facepdh(cube)==J))||
          ((facedhp(cube)==V)&&(facehdp(cube)==J)&&(facepdh(cube)==R))||
          ((facedhp(cube)==V)&&(facehdp(cube)==R)&&(facepdh(cube)==J)))
    return JRV;
  else if(((facedhp(cube)==J)&&(facehdp(cube)==R)&&(facepdh(cube)==B))||
          ((facedhp(cube)==J)&&(facehdp(cube)==B)&&(facepdh(cube)==R))||
          ((facedhp(cube)==R)&&(facehdp(cube)==J)&&(facepdh(cube)==B))||
          ((facedhp(cube)==R)&&(facehdp(cube)==B)&&(facepdh(cube)==J))||
          ((facedhp(cube)==B)&&(facehdp(cube)==J)&&(facepdh(cube)==R))||
          ((facedhp(cube)==B)&&(facehdp(cube)==R)&&(facepdh(cube)==J)))
    return JRB;
  else if(((facedhp(cube)==I)&&(facehdp(cube)==O)&&(facepdh(cube)==V))||
          ((facedhp(cube)==I)&&(facehdp(cube)==V)&&(facepdh(cube)==O))||
          ((facedhp(cube)==O)&&(facehdp(cube)==I)&&(facepdh(cube)==V))||
          ((facedhp(cube)==O)&&(facehdp(cube)==V)&&(facepdh(cube)==I))||
          ((facedhp(cube)==V)&&(facehdp(cube)==I)&&(facepdh(cube)==O))||
          ((facedhp(cube)==V)&&(facehdp(cube)==O)&&(facepdh(cube)==I)))
    return IOV;
  else if(((facedhp(cube)==J)&&(facehdp(cube)==O)&&(facepdh(cube)==V))||
          ((facedhp(cube)==J)&&(facehdp(cube)==V)&&(facepdh(cube)==O))||
          ((facedhp(cube)==O)&&(facehdp(cube)==J)&&(facepdh(cube)==V))||
          ((facedhp(cube)==O)&&(facehdp(cube)==V)&&(facepdh(cube)==J))||
          ((facedhp(cube)==V)&&(facehdp(cube)==J)&&(facepdh(cube)==O))||
          ((facedhp(cube)==V)&&(facehdp(cube)==O)&&(facepdh(cube)==J)))
    return JOV;
  else if(((facedhp(cube)==J)&&(facehdp(cube)==O)&&(facepdh(cube)==B))||
          ((facedhp(cube)==J)&&(facehdp(cube)==B)&&(facepdh(cube)==O))||
          ((facedhp(cube)==O)&&(facehdp(cube)==J)&&(facepdh(cube)==B))||
          ((facedhp(cube)==O)&&(facehdp(cube)==B)&&(facepdh(cube)==J))||
          ((facedhp(cube)==B)&&(facehdp(cube)==J)&&(facepdh(cube)==O))||
          ((facedhp(cube)==B)&&(facehdp(cube)==O)&&(facepdh(cube)==J)))
    return JOB;
  else if(((facedhp(cube)==I)&&(facehdp(cube)==O)&&(facepdh(cube)==B))||
          ((facedhp(cube)==I)&&(facehdp(cube)==B)&&(facepdh(cube)==O))||
          ((facedhp(cube)==O)&&(facehdp(cube)==I)&&(facepdh(cube)==B))||
          ((facedhp(cube)==O)&&(facehdp(cube)==B)&&(facepdh(cube)==I))||
          ((facedhp(cube)==B)&&(facehdp(cube)==I)&&(facepdh(cube)==O))||
          ((facedhp(cube)==B)&&(facehdp(cube)==O)&&(facepdh(cube)==I)))
    return IOB;
}

CS gba(CUBE*cube)
{
  if (((facegba(cube)==I)&&(facebga(cube)==R)&&(faceagb(cube)==B))||
      ((facegba(cube)==I)&&(facebga(cube)==B)&&(faceagb(cube)==R))||
      ((facegba(cube)==R)&&(facebga(cube)==I)&&(faceagb(cube)==B))||
      ((facegba(cube)==R)&&(facebga(cube)==B)&&(faceagb(cube)==I))||
      ((facegba(cube)==B)&&(facebga(cube)==I)&&(faceagb(cube)==R))||
      ((facegba(cube)==B)&&(facebga(cube)==R)&&(faceagb(cube)==I)))
    return IRB;
  else if(((facegba(cube)==I)&&(facebga(cube)==R)&&(faceagb(cube)==V))||
          ((facegba(cube)==I)&&(facebga(cube)==V)&&(faceagb(cube)==R))||
          ((facegba(cube)==R)&&(facebga(cube)==I)&&(faceagb(cube)==V))||
          ((facegba(cube)==R)&&(facebga(cube)==V)&&(faceagb(cube)==I))||
          ((facegba(cube)==V)&&(facebga(cube)==I)&&(faceagb(cube)==R))||
          ((facegba(cube)==V)&&(facebga(cube)==R)&&(faceagb(cube)==I)))
    return IRV;
  else if(((facegba(cube)==J)&&(facebga(cube)==R)&&(faceagb(cube)==V))||
          ((facegba(cube)==J)&&(facebga(cube)==V)&&(faceagb(cube)==R))||
          ((facegba(cube)==R)&&(facebga(cube)==J)&&(faceagb(cube)==V))||
          ((facegba(cube)==R)&&(facebga(cube)==V)&&(faceagb(cube)==J))||
          ((facegba(cube)==V)&&(facebga(cube)==J)&&(faceagb(cube)==R))||
          ((facegba(cube)==V)&&(facebga(cube)==R)&&(faceagb(cube)==J)))
    return JRV;
  else if(((facegba(cube)==J)&&(facebga(cube)==R)&&(faceagb(cube)==B))||
          ((facegba(cube)==J)&&(facebga(cube)==B)&&(faceagb(cube)==R))||
          ((facegba(cube)==R)&&(facebga(cube)==J)&&(faceagb(cube)==B))||
          ((facegba(cube)==R)&&(facebga(cube)==B)&&(faceagb(cube)==J))||
          ((facegba(cube)==B)&&(facebga(cube)==J)&&(faceagb(cube)==R))||
          ((facegba(cube)==B)&&(facebga(cube)==R)&&(faceagb(cube)==J)))
    return JRB;
  else if(((facegba(cube)==I)&&(facebga(cube)==O)&&(faceagb(cube)==V))||
          ((facegba(cube)==I)&&(facebga(cube)==V)&&(faceagb(cube)==O))||
          ((facegba(cube)==O)&&(facebga(cube)==I)&&(faceagb(cube)==V))||
          ((facegba(cube)==O)&&(facebga(cube)==V)&&(faceagb(cube)==I))||
          ((facegba(cube)==V)&&(facebga(cube)==I)&&(faceagb(cube)==O))||
          ((facegba(cube)==V)&&(facebga(cube)==O)&&(faceagb(cube)==I)))
    return IOV;
  else if(((facegba(cube)==J)&&(facebga(cube)==O)&&(faceagb(cube)==V))||
          ((facegba(cube)==J)&&(facebga(cube)==V)&&(faceagb(cube)==O))||
          ((facegba(cube)==O)&&(facebga(cube)==J)&&(faceagb(cube)==V))||
          ((facegba(cube)==O)&&(facebga(cube)==V)&&(faceagb(cube)==J))||
          ((facegba(cube)==V)&&(facebga(cube)==J)&&(faceagb(cube)==O))||
          ((facegba(cube)==V)&&(facebga(cube)==O)&&(faceagb(cube)==J)))
    return JOV;
  else if(((facegba(cube)==J)&&(facebga(cube)==O)&&(faceagb(cube)==B))||
          ((facegba(cube)==J)&&(facebga(cube)==B)&&(faceagb(cube)==O))||
          ((facegba(cube)==O)&&(facebga(cube)==J)&&(faceagb(cube)==B))||
          ((facegba(cube)==O)&&(facebga(cube)==B)&&(faceagb(cube)==J))||
          ((facegba(cube)==B)&&(facebga(cube)==J)&&(faceagb(cube)==O))||
          ((facegba(cube)==B)&&(facebga(cube)==O)&&(faceagb(cube)==J)))
    return JOB;
  else if(((facegba(cube)==I)&&(facebga(cube)==O)&&(faceagb(cube)==B))||
          ((facegba(cube)==I)&&(facebga(cube)==B)&&(faceagb(cube)==O))||
          ((facegba(cube)==O)&&(facebga(cube)==I)&&(faceagb(cube)==B))||
          ((facegba(cube)==O)&&(facebga(cube)==B)&&(faceagb(cube)==I))||
          ((facegba(cube)==B)&&(facebga(cube)==I)&&(faceagb(cube)==O))||
          ((facegba(cube)==B)&&(facebga(cube)==O)&&(faceagb(cube)==I)))
    return IOB;
}

CS dba(CUBE*cube)
{
  if (((facedba(cube)==I)&&(facebad(cube)==R)&&(faceadb(cube)==B))||
      ((facedba(cube)==I)&&(facebad(cube)==B)&&(faceadb(cube)==R))||
      ((facedba(cube)==R)&&(facebad(cube)==I)&&(faceadb(cube)==B))||
      ((facedba(cube)==R)&&(facebad(cube)==B)&&(faceadb(cube)==I))||
      ((facedba(cube)==B)&&(facebad(cube)==I)&&(faceadb(cube)==R))||
      ((facedba(cube)==B)&&(facebad(cube)==R)&&(faceadb(cube)==I)))
    return IRB;
  else if(((facedba(cube)==I)&&(facebad(cube)==R)&&(faceadb(cube)==V))||
          ((facedba(cube)==I)&&(facebad(cube)==V)&&(faceadb(cube)==R))||
          ((facedba(cube)==R)&&(facebad(cube)==I)&&(faceadb(cube)==V))||
          ((facedba(cube)==R)&&(facebad(cube)==V)&&(faceadb(cube)==I))||
          ((facedba(cube)==V)&&(facebad(cube)==I)&&(faceadb(cube)==R))||
          ((facedba(cube)==V)&&(facebad(cube)==R)&&(faceadb(cube)==I)))
    return IRV;
  else if(((facedba(cube)==J)&&(facebad(cube)==R)&&(faceadb(cube)==V))||
          ((facedba(cube)==J)&&(facebad(cube)==V)&&(faceadb(cube)==R))||
          ((facedba(cube)==R)&&(facebad(cube)==J)&&(faceadb(cube)==V))||
          ((facedba(cube)==R)&&(facebad(cube)==V)&&(faceadb(cube)==J))||
          ((facedba(cube)==V)&&(facebad(cube)==J)&&(faceadb(cube)==R))||
          ((facedba(cube)==V)&&(facebad(cube)==R)&&(faceadb(cube)==J)))
    return JRV;
  else if(((facedba(cube)==J)&&(facebad(cube)==R)&&(faceadb(cube)==B))||
          ((facedba(cube)==J)&&(facebad(cube)==B)&&(faceadb(cube)==R))||
          ((facedba(cube)==R)&&(facebad(cube)==J)&&(faceadb(cube)==B))||
          ((facedba(cube)==R)&&(facebad(cube)==B)&&(faceadb(cube)==J))||
          ((facedba(cube)==B)&&(facebad(cube)==J)&&(faceadb(cube)==R))||
          ((facedba(cube)==B)&&(facebad(cube)==R)&&(faceadb(cube)==J)))
    return JRB;
  else if(((facedba(cube)==I)&&(facebad(cube)==O)&&(faceadb(cube)==V))||
          ((facedba(cube)==I)&&(facebad(cube)==V)&&(faceadb(cube)==O))||
          ((facedba(cube)==O)&&(facebad(cube)==I)&&(faceadb(cube)==V))||
          ((facedba(cube)==O)&&(facebad(cube)==V)&&(faceadb(cube)==I))||
          ((facedba(cube)==V)&&(facebad(cube)==I)&&(faceadb(cube)==O))||
          ((facedba(cube)==V)&&(facebad(cube)==O)&&(faceadb(cube)==I)))
    return IOV;
  else if(((facedba(cube)==J)&&(facebad(cube)==O)&&(faceadb(cube)==V))||
          ((facedba(cube)==J)&&(facebad(cube)==V)&&(faceadb(cube)==O))||
          ((facedba(cube)==O)&&(facebad(cube)==J)&&(faceadb(cube)==V))||
          ((facedba(cube)==O)&&(facebad(cube)==V)&&(faceadb(cube)==J))||
          ((facedba(cube)==V)&&(facebad(cube)==J)&&(faceadb(cube)==O))||
          ((facedba(cube)==V)&&(facebad(cube)==O)&&(faceadb(cube)==J)))
    return JOV;
  else if(((facedba(cube)==J)&&(facebad(cube)==O)&&(faceadb(cube)==B))||
          ((facedba(cube)==J)&&(facebad(cube)==B)&&(faceadb(cube)==O))||
          ((facedba(cube)==O)&&(facebad(cube)==J)&&(faceadb(cube)==B))||
          ((facedba(cube)==O)&&(facebad(cube)==B)&&(faceadb(cube)==J))||
          ((facedba(cube)==B)&&(facebad(cube)==J)&&(faceadb(cube)==O))||
          ((facedba(cube)==B)&&(facebad(cube)==O)&&(faceadb(cube)==J)))
    return JOB;
  else if(((facedba(cube)==I)&&(facebad(cube)==O)&&(faceadb(cube)==B))||
          ((facedba(cube)==I)&&(facebad(cube)==B)&&(faceadb(cube)==O))||
          ((facedba(cube)==O)&&(facebad(cube)==I)&&(faceadb(cube)==B))||
          ((facedba(cube)==O)&&(facebad(cube)==B)&&(faceadb(cube)==I))||
          ((facedba(cube)==B)&&(facebad(cube)==I)&&(faceadb(cube)==O))||
          ((facedba(cube)==B)&&(facebad(cube)==O)&&(faceadb(cube)==I)))
    return IOB;
}

CS gbp(CUBE*cube)
{
  if (((facegbp(cube)==I)&&(facebgp(cube)==R)&&(facepgb(cube)==B))||
      ((facegbp(cube)==I)&&(facebgp(cube)==B)&&(facepgb(cube)==R))||
      ((facegbp(cube)==R)&&(facebgp(cube)==I)&&(facepgb(cube)==B))||
      ((facegbp(cube)==R)&&(facebgp(cube)==B)&&(facepgb(cube)==I))||
      ((facegbp(cube)==B)&&(facebgp(cube)==I)&&(facepgb(cube)==R))||
      ((facegbp(cube)==B)&&(facebgp(cube)==R)&&(facepgb(cube)==I)))
    return IRB;
  else if(((facegbp(cube)==I)&&(facebgp(cube)==R)&&(facepgb(cube)==V))||
          ((facegbp(cube)==I)&&(facebgp(cube)==V)&&(facepgb(cube)==R))||
          ((facegbp(cube)==R)&&(facebgp(cube)==I)&&(facepgb(cube)==V))||
          ((facegbp(cube)==R)&&(facebgp(cube)==V)&&(facepgb(cube)==I))||
          ((facegbp(cube)==V)&&(facebgp(cube)==I)&&(facepgb(cube)==R))||
          ((facegbp(cube)==V)&&(facebgp(cube)==R)&&(facepgb(cube)==I)))
    return IRV;
  else if(((facegbp(cube)==J)&&(facebgp(cube)==R)&&(facepgb(cube)==V))||
          ((facegbp(cube)==J)&&(facebgp(cube)==V)&&(facepgb(cube)==R))||
          ((facegbp(cube)==R)&&(facebgp(cube)==J)&&(facepgb(cube)==V))||
          ((facegbp(cube)==R)&&(facebgp(cube)==V)&&(facepgb(cube)==J))||
          ((facegbp(cube)==V)&&(facebgp(cube)==J)&&(facepgb(cube)==R))||
          ((facegbp(cube)==V)&&(facebgp(cube)==R)&&(facepgb(cube)==J)))
    return JRV;
  else if(((facegbp(cube)==J)&&(facebgp(cube)==R)&&(facepgb(cube)==B))||
          ((facegbp(cube)==J)&&(facebgp(cube)==B)&&(facepgb(cube)==R))||
          ((facegbp(cube)==R)&&(facebgp(cube)==J)&&(facepgb(cube)==B))||
          ((facegbp(cube)==R)&&(facebgp(cube)==B)&&(facepgb(cube)==J))||
          ((facegbp(cube)==B)&&(facebgp(cube)==J)&&(facepgb(cube)==R))||
          ((facegbp(cube)==B)&&(facebgp(cube)==R)&&(facepgb(cube)==J)))
    return JRB;
  else if(((facegbp(cube)==I)&&(facebgp(cube)==O)&&(facepgb(cube)==V))||
          ((facegbp(cube)==I)&&(facebgp(cube)==V)&&(facepgb(cube)==O))||
          ((facegbp(cube)==O)&&(facebgp(cube)==I)&&(facepgb(cube)==V))||
          ((facegbp(cube)==O)&&(facebgp(cube)==V)&&(facepgb(cube)==I))||
          ((facegbp(cube)==V)&&(facebgp(cube)==I)&&(facepgb(cube)==O))||
          ((facegbp(cube)==V)&&(facebgp(cube)==O)&&(facepgb(cube)==I)))
    return IOV;
  else if(((facegbp(cube)==J)&&(facebgp(cube)==O)&&(facepgb(cube)==V))||
          ((facegbp(cube)==J)&&(facebgp(cube)==V)&&(facepgb(cube)==O))||
          ((facegbp(cube)==O)&&(facebgp(cube)==J)&&(facepgb(cube)==V))||
          ((facegbp(cube)==O)&&(facebgp(cube)==V)&&(facepgb(cube)==J))||
          ((facegbp(cube)==V)&&(facebgp(cube)==J)&&(facepgb(cube)==O))||
          ((facegbp(cube)==V)&&(facebgp(cube)==O)&&(facepgb(cube)==J)))
    return JOV;
  else if(((facegbp(cube)==J)&&(facebgp(cube)==O)&&(facepgb(cube)==B))||
          ((facegbp(cube)==J)&&(facebgp(cube)==B)&&(facepgb(cube)==O))||
          ((facegbp(cube)==O)&&(facebgp(cube)==J)&&(facepgb(cube)==B))||
          ((facegbp(cube)==O)&&(facebgp(cube)==B)&&(facepgb(cube)==J))||
          ((facegbp(cube)==B)&&(facebgp(cube)==J)&&(facepgb(cube)==O))||
          ((facegbp(cube)==B)&&(facebgp(cube)==O)&&(facepgb(cube)==J)))
    return JOB;
  else if(((facegbp(cube)==I)&&(facebgp(cube)==O)&&(facepgb(cube)==B))||
          ((facegbp(cube)==I)&&(facebgp(cube)==B)&&(facepgb(cube)==O))||
          ((facegbp(cube)==O)&&(facebgp(cube)==I)&&(facepgb(cube)==B))||
          ((facegbp(cube)==O)&&(facebgp(cube)==B)&&(facepgb(cube)==I))||
          ((facegbp(cube)==B)&&(facebgp(cube)==I)&&(facepgb(cube)==O))||
          ((facegbp(cube)==B)&&(facebgp(cube)==O)&&(facepgb(cube)==I)))
    return IOB;
}

CS dbp(CUBE*cube)
{
  if (((facedbp(cube)==I)&&(facebdp(cube)==R)&&(facepdb(cube)==B))||
      ((facedbp(cube)==I)&&(facebdp(cube)==B)&&(facepdb(cube)==R))||
      ((facedbp(cube)==R)&&(facebdp(cube)==I)&&(facepdb(cube)==B))||
      ((facedbp(cube)==R)&&(facebdp(cube)==B)&&(facepdb(cube)==I))||
      ((facedbp(cube)==B)&&(facebdp(cube)==I)&&(facepdb(cube)==R))||
      ((facedbp(cube)==B)&&(facebdp(cube)==R)&&(facepdb(cube)==I)))
    return IRB;
  else if(((facedbp(cube)==I)&&(facebdp(cube)==R)&&(facepdb(cube)==V))||
          ((facedbp(cube)==I)&&(facebdp(cube)==V)&&(facepdb(cube)==R))||
          ((facedbp(cube)==R)&&(facebdp(cube)==I)&&(facepdb(cube)==V))||
          ((facedbp(cube)==R)&&(facebdp(cube)==V)&&(facepdb(cube)==I))||
          ((facedbp(cube)==V)&&(facebdp(cube)==I)&&(facepdb(cube)==R))||
          ((facedbp(cube)==V)&&(facebdp(cube)==R)&&(facepdb(cube)==I)))
    return IRV;
  else if(((facedbp(cube)==J)&&(facebdp(cube)==R)&&(facepdb(cube)==V))||
          ((facedbp(cube)==J)&&(facebdp(cube)==V)&&(facepdb(cube)==R))||
          ((facedbp(cube)==R)&&(facebdp(cube)==J)&&(facepdb(cube)==V))||
          ((facedbp(cube)==R)&&(facebdp(cube)==V)&&(facepdb(cube)==J))||
          ((facedbp(cube)==V)&&(facebdp(cube)==J)&&(facepdb(cube)==R))||
          ((facedbp(cube)==V)&&(facebdp(cube)==R)&&(facepdb(cube)==J)))
    return JRV;
  else if(((facedbp(cube)==J)&&(facebdp(cube)==R)&&(facepdb(cube)==B))||
          ((facedbp(cube)==J)&&(facebdp(cube)==B)&&(facepdb(cube)==R))||
          ((facedbp(cube)==R)&&(facebdp(cube)==J)&&(facepdb(cube)==B))||
          ((facedbp(cube)==R)&&(facebdp(cube)==B)&&(facepdb(cube)==J))||
          ((facedbp(cube)==B)&&(facebdp(cube)==J)&&(facepdb(cube)==R))||
          ((facedbp(cube)==B)&&(facebdp(cube)==R)&&(facepdb(cube)==J)))
    return JRB;
  else if(((facedbp(cube)==I)&&(facebdp(cube)==O)&&(facepdb(cube)==V))||
          ((facedbp(cube)==I)&&(facebdp(cube)==V)&&(facepdb(cube)==O))||
          ((facedbp(cube)==O)&&(facebdp(cube)==I)&&(facepdb(cube)==V))||
          ((facedbp(cube)==O)&&(facebdp(cube)==V)&&(facepdb(cube)==I))||
          ((facedbp(cube)==V)&&(facebdp(cube)==I)&&(facepdb(cube)==O))||
          ((facedbp(cube)==V)&&(facebdp(cube)==O)&&(facepdb(cube)==I)))
    return IOV;
  else if(((facedbp(cube)==J)&&(facebdp(cube)==O)&&(facepdb(cube)==V))||
          ((facedbp(cube)==J)&&(facebdp(cube)==V)&&(facepdb(cube)==O))||
          ((facedbp(cube)==O)&&(facebdp(cube)==J)&&(facepdb(cube)==V))||
          ((facedbp(cube)==O)&&(facebdp(cube)==V)&&(facepdb(cube)==J))||
          ((facedbp(cube)==V)&&(facebdp(cube)==J)&&(facepdb(cube)==O))||
          ((facedbp(cube)==V)&&(facebdp(cube)==O)&&(facepdb(cube)==J)))
    return JOV;
  else if(((facedbp(cube)==J)&&(facebdp(cube)==O)&&(facepdb(cube)==B))||
          ((facedbp(cube)==J)&&(facebdp(cube)==B)&&(facepdb(cube)==O))||
          ((facedbp(cube)==O)&&(facebdp(cube)==J)&&(facepdb(cube)==B))||
          ((facedbp(cube)==O)&&(facebdp(cube)==B)&&(facepdb(cube)==J))||
          ((facedbp(cube)==B)&&(facebdp(cube)==J)&&(facepdb(cube)==O))||
          ((facedbp(cube)==B)&&(facebdp(cube)==O)&&(facepdb(cube)==J)))
    return JOB;
  else if(((facedbp(cube)==I)&&(facebdp(cube)==O)&&(facepdb(cube)==B))||
          ((facedbp(cube)==I)&&(facebdp(cube)==B)&&(facepdb(cube)==O))||
          ((facedbp(cube)==O)&&(facebdp(cube)==I)&&(facepdb(cube)==B))||
          ((facedbp(cube)==O)&&(facebdp(cube)==B)&&(facepdb(cube)==I))||
          ((facedbp(cube)==B)&&(facebdp(cube)==I)&&(facepdb(cube)==O))||
          ((facedbp(cube)==B)&&(facebdp(cube)==O)&&(facepdb(cube)==I)))
    return IOB;
}


/* END OF tests.c */
