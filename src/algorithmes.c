/* algorithmes.c : algorithme pour refaire le cube (incomplet)
 *                 an algorithme which resolves the cube
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

#include <stdio.h>
#include "cube.h"
#include "tests.h"


void I_range_ah( CUBE *cube )
{
  COLOR color;
  CA ca;
  
  color = facea(cube);
  switch(color) {
  case I:
    ca = BI;
    break;
  case R:
    ca = BR;
    break;
  case J:
    ca = BJ;
    break;
  case O:
    ca = BO;
  }
  
  if(ah(cube)==ca)
    goto lbl3;
  else
    goto lbl4;
 lbl3:
  if(faceah(cube)==color) {
    return;
  } else {
    Exec(cube,"a²");
    goto lbl8;
  }
 lbl4:
  if(gh(cube)==ca) {
    Exec(cube,"g²");
  } else if(dh(cube)==ca) {
    Exec(cube,"d²");
  } else if(ph(cube)==ca) {
    Exec(cube,"p²");
  }
 lbl5:
  if(gb(cube)==ca) {
    Exec(cube,"b");
  } else if(db(cube)==ca) {
    Exec(cube,"b'");
  } else if(pb(cube)==ca) {
    Exec(cube,"b²");
  } else if(ab(cube)==ca) {
  } else {
    goto lbl6;
  }
  goto lbl7;
 lbl6:
  if(ad(cube)==ca) {
    Exec(cube,"aba'");
  } else if(ag(cube)==ca) {
    Exec(cube,"a'ba");
  } else if(pd(cube)==ca) {
    Exec(cube,"p'bp");
  } else if(pg(cube)==ca) {
    Exec(cube,"pbp'");
  }
  goto lbl5;
 lbl7:
  if(faceab(cube)==color) {
    Exec(cube,"a²");
    return;
  } else {
    goto lbl8;
  }
 lbl8:
  Exec(cube,"bda'd'");
  return;
}


void I_range_adh(CUBE *cube)
{
  int h;
  CS cs;
  
  h = 0;
  
  switch(facea(cube)) {
  case I:
    cs = BIR;
    break;
  case R:
    cs = BJR;
    break;
  case J:
    cs = BJO;
    break;
  case O:
    cs = BIO;
  }
  
//1
  if(adh(cube)==cs) {
  } else if(agh(cube)==cs) {
    Exec(cube,"h'");
    h = -1;
  } else if(pdh(cube)==cs) {
    Exec(cube,"h");
    h = 1;
  } else if(pgh(cube)==cs) {
    Exec(cube,"h²");
    h = 2;
  } else {
    goto lbl3;
  }
  goto lbl2;
 lbl2:
  Exec(cube,"aba'b'");
  switch(h) {
  case 0:
    break;
  case -1:
    Exec(cube,"h");
    break;
  case 1:
    Exec(cube,"h'");
    break;
  case 2:
    Exec(cube,"h²");
  }
  h = 0;
  goto lbl3;
 lbl3:
  if(agb(cube)==cs) {
    Exec(cube,"b");
  } else if(pdb(cube)==cs) {
    Exec(cube,"b'");
  } else if(pgb(cube)==cs) {
    Exec(cube,"b²");
  }
  if(facebda(cube)==faceh(cube)) {
    Exec(cube,"ab'a'b²");
  }
//4:
  if(faceadb(cube)==facea(cube)) {
    Exec(cube,"d'b'd");
  } else {
    Exec(cube,"aba'");
  }
}

/*     ____
     /    /!
    /____/ !
   !     ! !
   !     ! /
   !_____!/


*/

void g1(CUBE *cube)
{
  printf("G1\n");
  Exec(cube,"hdh'd'h'a'ha");
}


void g2(CUBE *cube)
{
  printf("G2\n");
  Exec(cube,"h'g'hghah'a'");
}


void II_range_3e(CUBE *cube)
{
  int intrus;
  
  printf("II_range_3e\n");
  
  do {
    //Range les intrus
    if((faceah(cube)!=V)&&(faceha(cube)!=V)) {
      switch(faceah(cube)) {
      case I:
        switch(faceha(cube)) {
        case R:
          g2(cube);
          break;
        case O:
          g1(cube);
        }
        break;
      case O:
        Exec(cube,"h'");
        r_xz(cube);
        switch(faceha(cube)) {
        case I:
          g2(cube);
          break;
        case J:
          g1(cube);
        }
        r_xz_inv(cube);
        break;
      case J:
        Exec(cube,"h²");
        r_xz(cube);
        r_xz(cube);
        switch(faceha(cube)) {
        case O:
          g2(cube);
          break;
        case R:
          g1(cube);
        }
        r_xz(cube);
        r_xz(cube);
        break;
      case R:
        Exec(cube,"h");
        r_xz_inv(cube);
        switch(faceha(cube)) {
        case J:
          g2(cube);
          break;
        case I:
          g1(cube);
        }
        r_xz(cube);
      }
    } else if((faceph(cube)!=V)&&(facehp(cube)!=V)) {
      switch(faceph(cube)) {
      case I:
        Exec(cube,"h²");
        switch(faceha(cube)) {
        case R:
          g2(cube);
          break;
        case O:
          g1(cube);
        }
        break;
      case O:
        Exec(cube,"h");
        r_xz(cube);
        switch(faceha(cube)) {
        case I:
          g2(cube);
          break;
        case J:
          g1(cube);
        }
        r_xz_inv(cube);
        break;
      case J:
        r_xz(cube);
        r_xz(cube);
        switch(faceha(cube)) {
        case O:
          g2(cube);
          break;
        case R:
          g1(cube);
        }
        r_xz(cube);
        r_xz(cube);
        break;
      case R:
        Exec(cube,"h'");
        r_xz_inv(cube);
        switch(faceha(cube)) {
        case J:
          g2(cube);
          break;
        case I:
          g1(cube);
        }
        r_xz(cube);
      }
    } else if((facedh(cube)!=V)&&(facehd(cube)!=V)) {
      switch(facedh(cube)) {
      case I:
        Exec(cube,"h");
        switch(faceha(cube)) {
        case R:
          g2(cube);
          break;
        case O:
          g1(cube);
        }
        break;
      case O:
        r_xz(cube);
        switch(faceha(cube)) {
        case I:
          g2(cube);
          break;
        case J:
          g1(cube);
        }
        r_xz_inv(cube);
        break;
      case J:
        Exec(cube,"h'");
        r_xz(cube);
        r_xz(cube);
        switch(faceha(cube)) {
        case O:
          g2(cube);
          break;
        case R:
          g1(cube);
        }
        r_xz(cube);
        r_xz(cube);
        break;
      case R:
        Exec(cube,"h²");
        r_xz_inv(cube);
        switch(faceha(cube)) {
        case J:
          g2(cube);
          break;
        case I:
          g1(cube);
        }
        r_xz(cube);
      }
    } else if((facegh(cube)!=V)&&(facehg(cube)!=V)) {
      switch(facegh(cube)) {
      case I:
        Exec(cube,"h'");
        switch(faceha(cube)) {
        case R:
          g2(cube);
          break;
        case O:
          g1(cube);
        }
        break;
      case O:
        Exec(cube,"h²");
        r_xz(cube);
        switch(faceha(cube)) {
        case I:
          g2(cube);
          break;
        case J:
          g1(cube);
        }
        r_xz_inv(cube);
        break;
      case J:
        Exec(cube,"h");
        r_xz(cube);
        r_xz(cube);
        switch(faceha(cube)) {
        case O:
          g2(cube);
          break;
        case R:
          g1(cube);
        }
        r_xz(cube);
        r_xz(cube);
        break;
      case R:
        r_xz_inv(cube);
        switch(faceha(cube)) {
        case J:
          g2(cube);
          break;
        case I:
          g1(cube);
        }
        r_xz(cube);
      }
    }
    
    //Compte les intrus
    intrus = 0;
    if((faceah(cube)!=V)&&(faceha(cube)!=V)) intrus++;
    if((faceph(cube)!=V)&&(facehp(cube)!=V)) intrus++;
    if((facedh(cube)!=V)&&(facehd(cube)!=V)) intrus++;
    if((facegh(cube)!=V)&&(facehg(cube)!=V)) intrus++;
    
  } while(intrus);
  
  /*
    do {
      range les intrus
      compte les intrus
    } while(intrus)
  */
	/*
	int i, intrus;

	printf("II : range intrus\n");
	
	//Compte les intrus
	intrus = 0;
	if((faceah(cube)!=V)&&(faceha(cube)!=V)) intrus++;
	if((faceph(cube)!=V)&&(facehp(cube)!=V)) intrus++;
	if((facedh(cube)!=V)&&(facehd(cube)!=V)) intrus++;
	if((facegh(cube)!=V)&&(facehg(cube)!=V)) intrus++;
	
	printf("intrus=%i\n",intrus);
	getchar();

	for( i = 0 ; i < intrus ; i++ )
	{
		while((faceah(cube)==V)||(faceha(cube)==V)) Exec(cube,"h"); //Détection d'intrus
		printf("intrus\n");
		switch(faceah(cube))
		{
		case I:
			switch(faceha(cube))
			{
			case R:
				g2(cube);
				break;
			case O:
				g1(cube);
			}
			break;
		case O:
			Exec(cube,"h'");
			r_xz(cube);
			switch(faceha(cube))
			{
			case I:
				g2(cube);
				break;
			case J:
				g1(cube);
			}
			r_xz_inv(cube);
			break;
		case J:
			Exec(cube,"h²");
			r_xz(cube);
			r_xz(cube);
			switch(faceha(cube))
			{
			case O:
				g2(cube);
				break;
			case R:
				g1(cube);
			}
			r_xz(cube);
			r_xz(cube);
			break;
		case R:
			Exec(cube,"h");
			r_xz_inv(cube);
			switch(faceha(cube))
			{
			case J:
				g2(cube);
				break;
			case I:
				g1(cube);
			}
			r_xz(cube);
		}
	}
	getchar();*/
}


void II_range_2e(CUBE *cube)
{
  printf("II_range_2e\n");
  
  if((facead(cube)!=I)||(faceda(cube)!=O)) {
    g1(cube);
    II_range_3e(cube);
  } else if((faceag(cube)!=I)||(facega(cube)!=R)) {
    g2(cube);
    II_range_3e(cube);
  } else if((facepd(cube)!=J)||(facedp(cube)!=O)) {
    r_xz(cube);
    g1(cube);
    r_xz_inv(cube);
    II_range_3e(cube);
  } else if((facepg(cube)!=J)||(facegp(cube)!=R)) {
    r_xz_inv(cube);
    g2(cube);
    r_xz(cube);
    II_range_3e(cube);
  }
}


void g3(CUBE *cube)
{
  printf("G3\n");
  Exec(cube,"ahdh'd'a'");
}


void g3_inv(CUBE *cube)
{
  printf("G3'\n");
  Exec(cube,"adhd'h'a'");
}


void g4(CUBE *cube)
{
  printf("G4\n");
  Exec(cube,"p'd'h'dhp");
}


void g4_inv(CUBE *cube)
{
  printf("G4'\n");
  Exec(cube,"p'h'd'hdp");
}


void g5(CUBE *cube)
{
  printf("G5\n");
  Exec(cube,"dp'd'ph²ph²p'");
}


void g5_inv(CUBE *cube)
{
  printf("G5'\n");
  Exec(cube,"ph²p'h²p'dpd'");
}


void g6(CUBE *cube)
{
  printf("G6\n");
  Exec(cube,"h²d'h²dhd'hd");
}


void g6_inv(CUBE *cube)
{
  printf("G6'\n");
  Exec(cube,"d'h'dh'd'h²dh²");
}


int III_compte_ca_places(CUBE *cube)
{
  int places = 0;
  
  if(ha(cube)==VI) places++;
  if(hd(cube)==VO) places++;
  if(hg(cube)==VR) places++;
  if(hp(cube)==VJ) places++;
	
  return places;
}


int III_ca_tous_ranges(CUBE *cube)
{
  return ((faceah(cube)==I)&&(faceha(cube)==V)&&(facedh(cube)==O)&&
          (facehd(cube)==V)&&(facegh(cube)==R)&&(facehg(cube)==V)&&
          (faceph(cube)==J)&&(facehp(cube)==V))?1:0;
}


void III_tourne_tq_hp_mal_range(CUBE *cube)
{
  while(faceph(cube)==J) {
    r_xz(cube);
  }
}


void III_range_ca(CUBE *cube)
{
  int i;
  
  printf("III_range_ca\n");
  
  for( i = 0 ; i < 4 ; i++ ) {
    if(facegh(cube)==R) {
      if((facedh(cube)==O)&&(faceph(cube)==J)&&(faceah(cube)==I))
        return;
      else if((dh(cube)!=OV)&&(ph(cube)!=JV)&&(ah(cube)!=IV))
        goto suite;
    }
    Exec(cube,"h");
  }
  r_xz(cube);
  for( i = 0 ; i < 4 ; i++ ) {
    if((facegh(cube)==I)&&(dh(cube)!=JV)&&(ph(cube)!=RV)&&(ah(cube)!=OV))
      goto suite;
    Exec(cube,"h");
  }
  r_xz(cube);
  for( i = 0 ; i < 4 ; i++ ) {
    if((facegh(cube)==O)&&(dh(cube)!=RV)&&(ph(cube)!=IV)&&(ah(cube)!=JV))
      goto suite;
    Exec(cube,"h");
  }
  r_xz(cube);
  for( i = 0 ; i < 4 ; i++ ) {
    if((facegh(cube)==J)&&(dh(cube)!=IV)&&(ph(cube)!=OV)&&(ah(cube)!=RV))
      goto suite;
    Exec(cube,"h");
  }
  r_xz(cube);
  printf("conf incorrecte\n");
/*	if((gh(cube)==RV)&&(dh(cube)==OV)&&(ph(cube)==JV)&&(ah(cube)==IV))
	{
		III_tourne_tq_hp_mal_range(cube);
		Exec(cube,"h²");
		g3(cube);
	}
	else if((gh(cube)==IV)&&(dh(cube)==JV)&&(ph(cube)==RV)&&(ah(cube)==OV))
	{
		Exec(cube,"h");
		III_tourne_tq_hp_mal_range(cube);
		Exec(cube,"h²");
		g3(cube);
	}
	else if((gh(cube)==OV)&&(dh(cube)==RV)&&(ph(cube)==IV)&&(ah(cube)==JV))
	{
		Exec(cube,"h²");
		III_tourne_tq_hp_mal_range(cube);
		Exec(cube,"h²");
		g3(cube);
	}
	else if((gh(cube)==JV)&&(dh(cube)==IV)&&(ph(cube)==OV)&&(ah(cube)==RV))
	{
		Exec(cube,"h'");
		III_tourne_tq_hp_mal_range(cube);
		Exec(cube,"h²");
		g3(cube);
	}
	else
	{*/
	/* vérifier que le générateur utilisé ne place qu'un CA (sinon utilier g6 ou g6') */
  printf("hg mal range...\n");
  while((hg(cube)==RV)||((dh(cube)!=VJ)&&(dh(cube)!=VI))) {
    printf("h\n");
    getchar();
    Exec(cube,"h");
  }
  getchar();
  switch(dh(cube)) {
  case VJ:
    switch(facedh(cube)) {
    case V:
      g4_inv(cube);
      break;
    case J:
      g3_inv(cube);
    }
    break;
  case VI:
    switch(facedh(cube)) {
    case V:
      g3(cube);
      break;
    case I:
      g4(cube);
    }
  }
/*}*/
 suite:
  return;
/*	int r;

	//a)
	for(;;)
	{
		if(III_compte_ca_places(cube))
			break;
		Exec(cube,"h");
	}
	
	if(III_compte_ca_places(cube)==2)
	{
		Exec(cube,"h");
	}
	
	//b)
b:
	switch(III_compte_ca_places(cube))
	{
	case 4:
		if(III_ca_tous_ranges(cube))
			return;
		Exec(cube,"h²");
		g3(cube);
		break;
	default:
		if((ah(cube)==VJ)&&(ph(cube)==VI)&&(dh(cube)==VR)&&(gh(cube)==VO))
		{
			Exec(cube,"h²");
			goto b;
		}
		else
		{
			while(!((hg(cube)!=VR)&&((dh(cube)==IV)||(dh(cube)==JV))))
			{
				Exec(cube,"h");
			}
			switch(facehd(cube))
			{
			case V:
				switch(facedh(cube))
				{
				case I:
					g3(cube);
					break;
				case J:
					g4_inv(cube);
				}
				break;
			case J:
				g3_inv(cube);
				break;
			case I:
				g4(cube);
			}
		}
	}
	//c)
	if(III_ca_tous_ranges(cube))
		return;
	r = 0;
	while(hg(cube)!=VR)
	{
		r++;
		r_xz(cube);
	}
	if((faceha(cube)==V)&&(facehd(cube)==V)&&(facehp(cube)==V))
	{
		switch(faceah(cube))
		{
		case J:
			g6(cube);
			break;
		case O:
			g6_inv(cube);
		}
	}
	else
	{
		if(facehp(cube)==V)
		{
			switch(faceph(cube))
			{
			case O:
				g3(cube);
				break;
			case I:
				g5_inv(cube);
			}
		}
		else if(facehd(cube)==V)
		{
			switch(facedh(cube))
			{
			case I:
				g4(cube);
				break;
			case O:
				g3_inv(cube);
			}
		}
		else if(faceha(cube)==V)
		{
			switch(faceah(cube))
			{
			case J:
				g3(cube);
				break;
			case O:
				g4_inv(cube);
			}
		}
	}*/
}


void g7(CUBE *cube)
{
  printf("G7\n");
  Exec(cube,"g'hdh'ghd'h'");
}


void g7_inv(CUBE *cube)
{
  printf("G7'\n");
  Exec(cube,"hdh'g'hd'h'g");
}


void III_place_cs(CUBE *cube)
{
  int places, r;
  
  r = 0;
  
  places = 0;
  if(adh(cube)==IVO) places++;
  if(agh(cube)==IVR) places++;
  if(pdh(cube)==JVO) places++;
  if(pgh(cube)==JVR) places++;
  
  printf("places=%i\n",places);
  
  switch(places) {
  case 0:
    //générateur supplémentaire
    if((ahg(cube)==IOV)&&(adh(cube)==IRV)&&(pgh(cube)==JOV)&&(pdh(cube)==RVJ)){
      Exec(cube,"adhd'h'dhd'h'dhd'h'a'");
      break;
    }
    switch(ahg(cube)) {
    case JVR:
      g7(cube);
      break;
    case JVO:
      g7_inv(cube);
      break;
    case IVO:
      switch(adh(cube)) {
      case IVR:
        r_xz(cube);
        r = 1;
        g7(cube);
        break;
      case JVR:
        r_xz(cube);
        r = 1;
        g7_inv(cube);
        break;
      case JVO:
        g7(cube);
        III_place_cs(cube);
        return;
      }
    }
    break;
  case 1:
    if(agh(cube)==IVR) {
      r_xz_inv(cube);
      r = -1;
    } else if(pdh(cube)==JVO) {
      r_xz(cube);
      r = 1;
    } else if(pdh(cube)==JVR) {
      r_xz(cube);
      r_xz(cube);
      r = 2;
    }
    switch(agh(cube)) {
    case JVR:
      g7(cube);
      break;
    case JVO:
      g7_inv(cube);
    }
    break;
  }
  switch(r) {
  case -1:
    r_xz(cube);
    break;
  case 1:
    r_xz_inv(cube);
    break;
  case 2:
    r_xz(cube);
    r_xz(cube);
  }
}


void III_range_cs(CUBE *cube)
{
}


void test( CUBE *cube )
{
  /** Etape I : couronne superieure **/
  
  /* 1. Ranger les CA */
  
  // Rangeons IB=ah
  I_range_ah(cube);
  r_xz(cube);
  // Rangeons RB
  I_range_ah(cube);
  r_xz(cube);
  // Rangeons JB
  I_range_ah(cube);
  r_xz(cube);
  // Rangeons OB
  I_range_ah(cube);
  r_xz(cube);
  
  /* 2. Ranger les CS */
  
  // Rangeons BIR=adh
  I_range_adh(cube);
  r_xz(cube);
  // Rangeons BJR=adh
  I_range_adh(cube);
  r_xz(cube);
  // Rangeons BJO=adh
  I_range_adh(cube);
  r_xz(cube);
  // Rangeons BIO=adh
  I_range_adh(cube);
  r_xz(cube);
  
  /** Etape II : second étage **/
  
  //Tourner le cube
  r_xy(cube);
  r_xy(cube);
  
  //Rangeons les cubes qui se trouvent sur le 3è étage
  II_range_3e(cube);
  
  //Virons et plaçons les cubes du 2e étage qui sont mal placés
  II_range_2e(cube);
  
  /** Etape III : troisième étage **/
  
  /* 1. Ranger les CA */
  III_range_ca(cube);
  
  /* 2. Placer les CS */
  //	III_place_cs(cube);
  
  /* 3. Ranger les CS */
  //	III_range_cs(cube);
  
  //On remet le cube dans sa position initiale
  //	r_xy(cube);
  //	r_xy(cube);
}


/* END OF algorithmes.c */
