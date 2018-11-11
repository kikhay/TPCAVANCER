
/*		### BIBLIOTHEQUE ###		*/
#include "../include/Population.h"
#include "../include/code.h"
/*		### DECLARATION FONCTION PRIVEE###	*/
void mem_swap(void* un, void* deux, int taille);
/*		### DEFINITION FONCTION ###		*/

void genere_bitkey(Bitkey* b, unsigned int d){
	Population p;
	int i;
	if(d == 0){
		random_bitkey(b);
		return;
	}
	init_pop(&p, TAILLE_POP);
	for(i = 0; i < TAILLE_POP; i++){
		genere_bitkey(&p.tab[i], i);
	}
	tri(&p);
	faites_des_bebes(&p.tab[0],&p.tab[1], &p.tab[2], b);
	
	if(fitness_key(&p.tab[0]) > fitness_key(b)){
		echange_bitkey(&p.tab[0], b);
	}
	
	libere_pop(&p);
}

void init_pop(Population* p, unsigned int taille){
	p->taille = taille;
	p->tab = malloc(sizeof(Bitkey) * taille);
	if(NULL == p->tab)
		exit(EXIT_FAILURE);
	
}

void libere_pop(Population* p){
	p->taille = 0;
	free(p->tab);
}

void faites_des_bebes(const Bitkey* papa, const Bitkey* maman, const Bitkey* alcool, Bitkey* bebe){
	int i;
	
	for(i = 0; i < TAILLE_POP; i++){
		bebe->values[i] = (papa->values[i] & maman->values[i]) |
						 (maman->values[i] & alcool->values[i]) |
						 (papa->values[i] & alcool->values[i]);
	}
	
}

void mem_swap(void* un, void* deux, int taille){
	char *u,*d;
	int i;
	char temp;
	
	assert(NULL != un);
	assert(NULL != deux);
	assert(-1 < taille);
	
	u = (char*)un;
	d = (char*)deux;
	
	for( i = 0; i < taille; i++){
		temp = u[i];
		u[i] = d[i];
		d[i] = temp;
	}
}

void echange_bitkey(Bitkey* b1, Bitkey* b2){
	mem_swap(&(b1->values), &(b2->values), sizeof(uint8_t) * NB_OCT);
}
