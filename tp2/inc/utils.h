#ifndef UTILS_H
#define UTILS_H

#include "all.h"

extern int angle;

void update();
void afficherPixel(int x, int y);
void afficherGrille();
void afficherPoly(point *points, int nbPoints);
void usage(char *s);
#endif
