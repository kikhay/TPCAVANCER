#ifndef __POPULATION__
#define __POPULATION__

/*		### BIBLIOTHEQUE ###		*/
#include "Aleatoire.h"
#include "code.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*		### MACRO ###		*/
#define TAILLE_POP 8
/*		### STRUCTURE ###		*/
typedef struct{
	Bitkey* tab;
	unsigned int taille;
}Population;


/*		### DECLARATION FONCTION ###	*/
void init_pop(Population* p, unsigned int taille);

void libere_pop(Population* p);

void faites_des_bebes(const Bitkey* papa, const Bitkey* maman, const Bitkey* alcool, Bitkey* bebe);

void tri(Population* pop);

void genere_bitkey(Bitkey* b, unsigned int d);

void echange_bitkey(Bitkey* b1, Bitkey* b2);
#endif
