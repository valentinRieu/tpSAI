#ifndef KARBRE_H
#define KARBRE_H

#include "common.h"

#define K 4

typedef enum {VIDE, PLEIN, PARTIEL} statut;

typedef struct {
	point pos;
	statut stat;
} element;

typedef struct s_karbre {
	cube detection;
	element e;

	struct s_karbre **children;
} *karbre;

karbre kArbreVide();

karbre kConsArbre(int n, element e, ...);

karbre kFils(int ieme, karbre a);

element kRacine(karbre a);

int kEstVide(karbre a);

void kAfficher(karbre a);

void kDestroy(karbre a);

#endif
