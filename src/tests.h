/* tests.h */
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

#ifndef __INC_TESTS_H
#define __INC_TESTS_H


#include "_cube.h"


#define I W
#define blanc W
#define white W
#define rouge R
#define red R
#define bleu B
#define blue B
#define V G
#define vert G
#define green G
#define J Y
#define jaune Y
#define yellow Y
#define orange O


enum CA
{
  BI,
  BR,
  BO,
  BJ,
  VI,
  VR,
  VO,
  VJ,
  IO,
  IR,
  JO,
  JR
} typedef CA;

enum CS
{
  OBI,
  RBI,
  OBJ,
  RBJ,
  OVI,
  RVI,
  OVJ,
  RVJ
} typedef CS;

COLOR facea(CUBE*cube);
COLOR facep(CUBE*cube);
COLOR faced(CUBE*cube);
COLOR faceg(CUBE*cube);
COLOR faceh(CUBE*cube);
COLOR faceb(CUBE*cube);

COLOR faceah(CUBE*cube);
COLOR facedh(CUBE*cube);
COLOR facegh(CUBE*cube);
COLOR faceph(CUBE*cube);
COLOR faceab(CUBE*cube);
COLOR facedb(CUBE*cube);
COLOR facegb(CUBE*cube);
COLOR facepb(CUBE*cube);
COLOR facead(CUBE*cube);
COLOR faceag(CUBE*cube);
COLOR facepd(CUBE*cube);
COLOR facepg(CUBE*cube);
COLOR faceha(CUBE*cube);
COLOR facehd(CUBE*cube);
COLOR facehg(CUBE*cube);
COLOR facehp(CUBE*cube);
COLOR faceba(CUBE*cube);
COLOR facebd(CUBE*cube);
COLOR facebg(CUBE*cube);
COLOR facebp(CUBE*cube);
COLOR faceda(CUBE*cube);
COLOR facega(CUBE*cube);
COLOR facedp(CUBE*cube);
COLOR facegp(CUBE*cube);

COLOR facegah(CUBE*cube);
COLOR facehag(CUBE*cube);
COLOR faceahg(CUBE*cube);
COLOR facedah(CUBE*cube);
COLOR facehad(CUBE*cube);
COLOR faceahd(CUBE*cube);
COLOR facegph(CUBE*cube);
COLOR facehpg(CUBE*cube);
COLOR facephg(CUBE*cube);
COLOR facedph(CUBE*cube);
COLOR facehpd(CUBE*cube);
COLOR facephd(CUBE*cube);
COLOR facegab(CUBE*cube);
COLOR facebag(CUBE*cube);
COLOR faceabg(CUBE*cube);
COLOR facedab(CUBE*cube);
COLOR facebad(CUBE*cube);
COLOR faceabd(CUBE*cube);
COLOR facegpb(CUBE*cube);
COLOR facebpg(CUBE*cube);
COLOR facepbg(CUBE*cube);
COLOR facedpb(CUBE*cube);
COLOR facebpd(CUBE*cube);
COLOR facepbd(CUBE*cube);

CA ah(CUBE*cube);
CA dh(CUBE*cube);
CA gh(CUBE*cube);
CA ph(CUBE*cube);
CA ab(CUBE*cube);
CA db(CUBE*cube);
CA gb(CUBE*cube);
CA pb(CUBE*cube);
CA ad(CUBE*cube);
CA ag(CUBE*cube);
CA pd(CUBE*cube);
CA pg(CUBE*cube);

CS gha(CUBE*cube);
CS dha(CUBE*cube);
CS ghp(CUBE*cube);
CS dhp(CUBE*cube);
CS gba(CUBE*cube);
CS dba(CUBE*cube);
CS gbp(CUBE*cube);
CS dbp(CUBE*cube);


#define IB BI
#define RB BR
#define OB BO
#define JB BJ
#define IV VI
#define RV VR
#define OV VO
#define JV VJ
#define OI IO
#define RI IR
#define OJ JO
#define RJ JR

#define ha ah
#define hd dh
#define hg gh
#define hp ph
#define ba ab
#define bd db
#define bg gb
#define bp pb
#define da ad
#define ga ag
#define dp pd
#define gp pg

#define OIB OBI
#define BIO OBI
#define BOI OBI
#define IBO OBI
#define IOB OBI
#define RIB RBI
#define BIR RBI
#define BRI RBI
#define IBR RBI
#define IRB RBI
#define OJB OBJ
#define BJO OBJ
#define BOJ OBJ
#define JBO OBJ
#define JOB OBJ
#define RJB RBJ
#define BJR RBJ
#define BRJ RBJ
#define JBR RBJ
#define JRB RBJ
#define OIV OVI
#define VIO OVI
#define VOI OVI
#define IVO OVI
#define IOV OVI
#define RIV RVI
#define VIR RVI
#define VRI RVI
#define IVR RVI
#define IRV RVI
#define OJV OVJ
#define VJO OVJ
#define VOJ OVJ
#define JVO OVJ
#define JOV OVJ
#define RJV RVJ
#define VJR RVJ
#define VRJ RVJ
#define JVR RVJ
#define JRV RVJ

#define gah gha
#define hag gha
#define hga gha
#define ahg gha
#define agh gha
#define dah dha
#define had dha
#define hda dha
#define ahd dha
#define adh dha
#define gph ghp
#define hpg ghp
#define hgp ghp
#define phg ghp
#define pgh ghp
#define dph dhp
#define hpd dhp
#define hdp dhp
#define phd dhp
#define pdh dhp
#define gab gba
#define bag gba
#define bga gba
#define abg gba
#define agb gba
#define dab dba
#define bad dba
#define bda dba
#define abd dba
#define adb dba
#define gpb gbp
#define bpg gbp
#define bgp gbp
#define pbg gbp
#define pgb gbp
#define dpb dbp
#define bpd dbp
#define bdp dbp
#define pbd dbp
#define pdb dbp

#define facegha facegah
#define facehga facehag
#define faceagh faceahg

#define facedha facedah
#define facehda facehad
#define faceadh faceahd

#define faceghp facegph
#define facehgp facehpg
#define facepgh facephg

#define facedhp facedph
#define facehdp facehpd
#define facepdh facephd

#define facegba facegab
#define facebga facebag
#define faceagb faceabg

#define facedba facedab
#define facebda facebad
#define faceadb faceabd

#define facegbp facegpb
#define facebgp facebpg
#define facepgb facepbg

#define facedbp facedpb
#define facebdp facebpd
#define facepdb facepbd


#endif //__INC_TESTS_H

/* END OF tests.h */
