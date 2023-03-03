#ifndef CODAGE_H
#define CODAGE_H
#include "common.h"
#include "karbre.h"
#include <math.h>
#define N 8


int intersection(cube c, boule b);

int contient(cube c, boule b);

karbre boule2arbre(boule b);

karbre kIntersection(karbre a, karbre b);

#endif
