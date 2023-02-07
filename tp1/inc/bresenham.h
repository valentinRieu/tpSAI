#ifndef BRESENHAM_H
#define BRESENHAM_H

#include "common.h"
#include "utils.h"

void bresenhamInitial(int x1, int y1, int x2, int y2);
void bresenhamPremierOct(int x1, int y1, int x2, int y2);

void bresenham(int x1, int y1, int x2, int y2);

void bresenham_propre(int x1, int y1, int x2, int y2);

#endif
